#include "s21_decimal.h"

void s21_dec_to_big(s21_decimal num, big_decimal *big_num) {
  big_num->bits[0] = num.bits[0];
  big_num->bits[1] = num.bits[1];
  big_num->bits[2] = num.bits[2];
  big_num->bits[3] = big_num->bits[4] = big_num->bits[5] = 0;
  big_num->bits[6] = num.bits[3];
}

void s21_big_to_dec(big_decimal big_num, s21_decimal *num) {
  num->bits[0] = big_num.bits[0];
  num->bits[1] = big_num.bits[1];
  num->bits[2] = big_num.bits[2];
  num->bits[3] = big_num.bits[6];
}

void s21_big_init(big_decimal *num) {
  num->bits[0] = num->bits[1] = num->bits[2] = num->bits[3] = num->bits[4] =
      num->bits[5] = num->bits[6] = 0;
}

void s21_big_copy(big_decimal root, big_decimal *dest) {
  dest->bits[0] = root.bits[0];
  dest->bits[1] = root.bits[1];
  dest->bits[2] = root.bits[2];
  dest->bits[3] = root.bits[3];
  dest->bits[4] = root.bits[4];
  dest->bits[5] = root.bits[5];
  dest->bits[6] = root.bits[6];
}

void s21_big_set_sign(big_decimal *dst) {
  dst->bits[6] = dst->bits[6] | 1U << 31;
}

int s21_big_get_sign(big_decimal dst) {
  int sign = (dst.bits[6] & 1U << 31) != 0;

  return sign;
}

int s21_big_get_scale(big_decimal dst) {
  int mask = 0b11111111 << 16;
  int scale = (dst.bits[6] & mask) >> 16;

  return scale;
}

int s21_big_is_empty(big_decimal value) {
  int res = 1;
  if (value.bits[0] || value.bits[1] || value.bits[2] || value.bits[3] ||
      value.bits[4] || value.bits[5]) {
    res = 0;
  }
  return res;
}

void s21_big_set_scale(big_decimal *num, int value) {
  value <<= 16;
  char sign = s21_big_get_sign(*num);
  num->bits[6] = value;
  if (sign) s21_big_set_sign(num);
}

int s21_big_get_bit(big_decimal dst, int idx) {
  unsigned mask = 1U << (idx % 32);
  int bit = (dst.bits[idx / 32] & mask) != 0;

  return bit;
}

void s21_big_set_bit(big_decimal *dest, int value, int pos) {
  unsigned int point = 1U << (pos % 32);

  if (value) {
    dest->bits[pos / 32] = dest->bits[pos / 32] | point;
  } else {
    point = ~point;
    dest->bits[pos / 32] = dest->bits[pos / 32] & point;
  }
}

int s21_big_left_shift(big_decimal *num) {
  int res = 0;
  char bit_1 = s21_big_get_bit(*num, 31);
  char bit_2 = s21_big_get_bit(*num, 63);
  char bit_3 = s21_big_get_bit(*num, 95);
  char bit_4 = s21_big_get_bit(*num, 127);
  char bit_5 = s21_big_get_bit(*num, 159);
  char bit_6 = s21_big_get_bit(*num, 191);
  if (!bit_6) {
    num->bits[0] <<= 1;
    num->bits[1] <<= 1;
    s21_big_set_bit(num, bit_1, 32);
    num->bits[2] <<= 1;
    s21_big_set_bit(num, bit_2, 64);
    num->bits[3] <<= 1;
    s21_big_set_bit(num, bit_3, 96);
    num->bits[4] <<= 1;
    s21_big_set_bit(num, bit_4, 128);
    num->bits[5] <<= 1;
    s21_big_set_bit(num, bit_5, 160);
  } else {
    res = 1;
  }
  return res;
}

void s21_big_right_shift(big_decimal *num) {
  char bit_1 = s21_big_get_bit(*num, 32);
  char bit_2 = s21_big_get_bit(*num, 64);
  char bit_3 = s21_big_get_bit(*num, 96);
  char bit_4 = s21_big_get_bit(*num, 128);
  char bit_5 = s21_big_get_bit(*num, 160);
  num->bits[5] >>= 1;
  num->bits[4] >>= 1;
  s21_big_set_bit(num, bit_5, 159);
  num->bits[3] >>= 1;
  s21_big_set_bit(num, bit_4, 127);
  num->bits[2] >>= 1;
  s21_big_set_bit(num, bit_3, 95);
  num->bits[1] >>= 1;
  s21_big_set_bit(num, bit_2, 63);
  num->bits[0] >>= 1;
  s21_big_set_bit(num, bit_1, 31);
}

/*
it looks bad. I know.
*/
int s21_mant_big_is_bigger_or_equal(big_decimal value_1, big_decimal value_2) {
  int res = 1;
  if (value_1.bits[5] < value_2.bits[5]) {
    res = 0;
  } else if (value_1.bits[5] == value_2.bits[5]) {
    if (value_1.bits[4] < value_2.bits[4]) {
      res = 0;
    } else if (value_1.bits[4] == value_2.bits[4]) {
      if (value_1.bits[3] < value_2.bits[3]) {
        res = 0;
      } else if (value_1.bits[3] == value_2.bits[3]) {
        if (value_1.bits[2] < value_2.bits[2]) {
          res = 0;
        } else if (value_1.bits[2] == value_2.bits[2]) {
          if (value_1.bits[1] < value_2.bits[1]) {
            res = 0;
          } else if (value_1.bits[1] == value_2.bits[1]) {
            if (value_1.bits[0] < value_2.bits[0]) {
              res = 0;
            }
          }
        }
      }
    }
  }

  return res;
}

// works only with matisses
// doesn't count scales
int s21_big_mant_mult(big_decimal num_1, big_decimal num_2,
                      big_decimal *result) {
  int res = 0;
  big_decimal temp;
  s21_big_init(&temp);
  s21_big_init(result);

  int i;
  for (i = 0; i < 192 && (!res); i++) {
    if (s21_big_get_bit(num_1, i)) {
      s21_big_copy(num_2, &temp);
      for (int j = 0; j < i && (!res); j++) {
        res = s21_big_left_shift(&temp);
      }
      if (!res) {
        res = s21_big_mant_add(temp, *result, result);
      }
    }
  }
  return res;
}

// works only with matisses
// doesn't count scales
int s21_big_mant_add(big_decimal value_1, big_decimal value_2,
                     big_decimal *result) {
  int res = 0;
  char bit_1 = 0, bit_2 = 0, bit_mem = 0, bit_res = 0;
  s21_big_init(result);

  for (int i = 0; i < 192; i++) {
    bit_1 = s21_big_get_bit(value_1, i);
    bit_2 = s21_big_get_bit(value_2, i);
    bit_res = bit_1 + bit_2 + bit_mem;
    if (bit_res > 1) {
      bit_res -= 2;
      bit_mem = 1;
    } else {
      bit_mem = 0;
    }

    s21_big_set_bit(result, bit_res, i);
    // насчет такого рода проверки не уверен
    // это ж что такое мы складываем, что у нас big_dec переполнило...
    if (i == 191 && bit_mem) {
      res = 1;
    }
  }
  return res;
}

// works only with matisses
// doesn't count scales
void s21_big_mant_sub(big_decimal value_1, big_decimal value_2,
                      big_decimal *result) {
  s21_big_init(result);
  for (int i = 0; i < 192; i++) {
    int bit_1, bit_2;
    bit_1 = s21_big_get_bit(value_1, i);
    bit_2 = s21_big_get_bit(value_2, i);
    // only possible when bit_1 = 0, bit_2 = 1
    if (bit_2 > bit_1) {
      int j = i + 1;
      while (!s21_big_get_bit(value_1, j)) {
        j++;
      }
      s21_big_set_bit(&value_1, 0, j);
      for (j -= 1; j != i; j--) {
        s21_big_set_bit(&value_1, 1, j);
      }
      s21_big_set_bit(result, 1, i);
    } else {
      s21_big_set_bit(result, bit_1 - bit_2, i);
    }
  }
}

// works only with matisses
// doesn't count scales
big_decimal s21_big_mant_div(big_decimal num_1, big_decimal num_2,
                             big_decimal *result) {
  s21_big_init(result);
  big_decimal temp, one;
  while (s21_mant_big_is_bigger_or_equal(num_1, num_2)) {
    s21_big_init(&one);
    one.bits[0] = 1;
    int curr_exp = 0;
    s21_big_copy(num_2, &temp);
    while (s21_mant_big_is_bigger_or_equal(num_1, temp)) {
      s21_big_left_shift(&temp);
      curr_exp++;
    }
    s21_big_right_shift(&temp);
    s21_big_mant_sub(num_1, temp, &num_1);
    curr_exp--;
    while (curr_exp) {
      s21_big_left_shift(&one);
      curr_exp--;
    }
    s21_big_mant_add(one, *result, result);
  }

  return num_1;
}

void s21_equal_scales(big_decimal *num_1, big_decimal *num_2) {
  int scale_1 = s21_big_get_scale(*num_1);
  int scale_2 = s21_big_get_scale(*num_2);
  big_decimal tmp;
  s21_big_init(&tmp);
  tmp.bits[0] = 10;
  while (scale_1 > scale_2) {
    s21_big_mant_mult(*num_2, tmp, num_2);
    scale_2++;
  }
  while (scale_1 < scale_2) {
    s21_big_mant_mult(*num_1, tmp, num_1);
    scale_1++;
  }

  s21_big_set_scale(num_1, scale_1);
  s21_big_set_scale(num_2, scale_2);
}

// Сравнивает знаки двух big_decimal_alt
int compare_big_decimal_alt_sign(big_decimal var1, big_decimal var2) {
  int result = 0;
  if (s21_big_get_sign(var1) == 0 && s21_big_get_sign(var2) == 1) result = 1;
  if (s21_big_get_sign(var1) == 1 && s21_big_get_sign(var2) == 0) result = -1;
  if (s21_big_get_sign(var1) == 0 && s21_big_get_sign(var2) == 0) result = 2;
  if (s21_big_get_sign(var1) == 1 && s21_big_get_sign(var2) == 1) result = -2;
  return result;
}

big_decimal scale_big_decimal_alt_up(big_decimal op) {
  big_decimal result = {0};
  unsigned long long accum = 0;
  for (int i = 0; i < 6; i++) {
    accum = accum + (unsigned long long)op.bits[i] * 10;
    result.bits[i] = (unsigned)accum;
    accum = accum >> 32;
  }
  return result;
}

// Приводит big_decimal_alt к нужному коэффициенту масштабирования
big_decimal normalization_big_decimal_alt(big_decimal src, int scale) {
  while (scale--) {
    src = scale_big_decimal_alt_up(src);
  }
  return src;
}

// Сравнивает значение двух big_decimal_alt
int compare_big_decimal_alt_digit(big_decimal var1, big_decimal var2) {
  int result = 0;
  if (s21_big_get_scale(var1) > s21_big_get_scale(var2)) {
    var2 = normalization_big_decimal_alt(
        var2, s21_big_get_scale(var1) - s21_big_get_scale(var2));
  }
  if (s21_big_get_scale(var2) > s21_big_get_scale(var1)) {
    var1 = normalization_big_decimal_alt(
        var1, s21_big_get_scale(var2) - s21_big_get_scale(var1));
  }
  for (int i = 5; i >= 0; i--) {
    if (var1.bits[i] > var2.bits[i]) {
      result = 1;
      break;
    } else if (var1.bits[i] < var2.bits[i]) {
      result = -1;
      break;
    }
  }
  return result;
}
