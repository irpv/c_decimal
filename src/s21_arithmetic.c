#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int res = 0, rem_1 = 0, rem_2 = 0;

  big_decimal num_1, num_2, big_result, remain;
  s21_dec_to_big(value_1, &num_1);
  s21_dec_to_big(value_2, &num_2);
  s21_big_init(&big_result);
  s21_big_init(&remain);

  int sign_1 = s21_big_get_sign(num_1);
  int sign_2 = s21_big_get_sign(num_2);

  s21_equal_scales(&num_1, &num_2);

  if (sign_1 == sign_2) {
    s21_big_mant_add(num_1, num_2, &big_result);
    if (sign_1) s21_big_set_sign(&big_result);
  } else if (sign_1 > sign_2) {
    if (s21_mant_big_is_bigger_or_equal(num_1, num_2)) {
      s21_big_mant_sub(num_1, num_2, &big_result);
      s21_big_set_sign(&big_result);
    } else {
      s21_big_mant_sub(num_2, num_1, &big_result);
    }
  } else {
    if (s21_mant_big_is_bigger_or_equal(num_1, num_2)) {
      s21_big_mant_sub(num_1, num_2, &big_result);
    } else {
      s21_big_mant_sub(num_2, num_1, &big_result);
      s21_big_set_sign(&big_result);
    }
  }

  int res_scale = s21_big_get_scale(num_1);
  s21_big_set_scale(&big_result, res_scale);

  big_decimal tmp;
  s21_big_init(&tmp);
  tmp.bits[0] = 10;

  int sign = s21_big_get_sign(big_result);

  while ((big_result.bits[5] || big_result.bits[4] || big_result.bits[3]) &&
         res_scale) {
    remain = s21_big_mant_div(big_result, tmp, &big_result);
    res_scale--;
  }

  rem_1 = remain.bits[0];

  if (res_scale == 0 &&
      (big_result.bits[5] || big_result.bits[4] || big_result.bits[3])) {
    if (s21_big_get_sign(big_result)) {
      res = 2;
    } else {
      res = 1;
    }
  } else {
    if (rem_1 > 5) {
      tmp.bits[0] = 1;
      res = s21_big_mant_add(big_result, tmp, &big_result);
    } else if (rem_1 == 5) {
      remain = s21_big_mant_div(big_result, tmp, &num_1);
      rem_2 = remain.bits[0];
      if (rem_2 % 2 == 1) {
        tmp.bits[0] = 1;
        res = s21_big_mant_add(big_result, tmp, &big_result);
      }
    }
  }

  s21_big_set_scale(&big_result, res_scale);

  if (sign) {
    s21_big_set_sign(&big_result);
  }

  if (!res) {
    s21_big_to_dec(big_result, result);
  } else {
    result->bits[0] = 0U;
    result->bits[1] = 0U;
    result->bits[2] = 0U;
    result->bits[3] = 0U;
  }

  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  value_2.bits[3] += 1U << 31;
  return s21_add(value_1, value_2, result);
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int res = 0, rem_1 = 0, rem_2 = 0;
  s21_dec_init(result);

  big_decimal num_1, num_2, big_result, remain;
  s21_dec_to_big(value_1, &num_1);
  s21_dec_to_big(value_2, &num_2);
  s21_big_init(&big_result);
  s21_big_init(&remain);

  s21_big_mant_mult(num_1, num_2, &big_result);

  int res_scale = s21_big_get_scale(num_1) + s21_big_get_scale(num_2);
  s21_big_set_scale(&big_result, res_scale);

  big_decimal tmp;
  s21_big_init(&tmp);
  tmp.bits[0] = 10;

  while (res_scale > 28) {
    remain = s21_big_mant_div(big_result, tmp, &big_result);
    res_scale--;
  }

  while ((big_result.bits[5] || big_result.bits[4] || big_result.bits[3]) &&
         res_scale) {
    remain = s21_big_mant_div(big_result, tmp, &big_result);
    res_scale--;
  }

  rem_1 = remain.bits[0];

  if (res_scale == 0 &&
      (big_result.bits[5] || big_result.bits[4] || big_result.bits[3])) {
    if (s21_big_get_sign(big_result)) {
      res = 2;
    } else {
      res = 1;
    }
  } else {
    if (rem_1 > 5) {
      tmp.bits[0] = 1;
      res = s21_big_mant_add(big_result, tmp, &big_result);
    } else if (rem_1 == 5) {
      remain = s21_big_mant_div(big_result, tmp, &num_1);
      rem_2 = remain.bits[0];
      if (rem_2 % 2 == 1) {
        tmp.bits[0] = 1;
        res = s21_big_mant_add(big_result, tmp, &big_result);
      }
    }
  }

  s21_big_set_scale(&big_result, res_scale);

  if (s21_big_get_sign(num_1) != s21_big_get_sign(num_2)) {
    s21_big_set_sign(&big_result);
  }

  if (res_scale == 0 &&
      (big_result.bits[5] || big_result.bits[4] || big_result.bits[3])) {
    if (s21_big_get_sign(big_result)) {
      res = 2;
    } else {
      res = 1;
    }
  }

  if (!res) {
    s21_big_to_dec(big_result, result);
  } else {
    result->bits[0] = 0U;
    result->bits[1] = 0U;
    result->bits[2] = 0U;
    result->bits[3] = 0U;
  }

  return res;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_dec_init(result);

  if (!s21_is_empty(value_1) && s21_is_empty(value_2)) {
    if (s21_get_sign(value_1)) {
      return 2;
    } else {
      return 1;
    }
  } else if (s21_is_empty(value_1) && s21_is_empty(value_2)) {
    return 3;
  }

  int res = 0, rem_1 = 0, rem_2 = 0;
  big_decimal num_1, num_2, big_result, cur_res, remain;
  s21_dec_to_big(value_1, &num_1);
  s21_dec_to_big(value_2, &num_2);
  s21_big_init(&big_result);
  s21_big_init(&remain);
  s21_big_init(&cur_res);

  int res_scale = s21_big_get_scale(num_1) - s21_big_get_scale(num_2);
  int scale = res_scale;

  big_decimal tmp;
  s21_big_init(&tmp);
  tmp.bits[0] = 10;

  for (int i = 0; i < 28 - scale && !s21_big_is_empty(num_1); i++) {
    num_1 = s21_big_mant_div(num_1, num_2, &cur_res);
    s21_big_mant_add(big_result, cur_res, &big_result);
    if (!s21_big_is_empty(num_1)) {
      s21_big_mant_mult(big_result, tmp, &big_result);
      s21_big_mant_mult(num_1, tmp, &num_1);
      res_scale++;
    }
  }

  while (res_scale < 0) {
    s21_big_mant_mult(big_result, tmp, &big_result);
    res_scale++;
  }

  while ((big_result.bits[5] || big_result.bits[4] || big_result.bits[3]) &&
         res_scale) {
    remain = s21_big_mant_div(big_result, tmp, &big_result);
    res_scale--;
  }

  rem_1 = remain.bits[0];

  if (s21_big_get_sign(num_1) != s21_big_get_sign(num_2)) {
    s21_big_set_sign(&big_result);
  }

  if (res_scale == 0 &&
      (big_result.bits[5] || big_result.bits[4] || big_result.bits[3])) {
    if (s21_big_get_sign(big_result)) {
      res = 2;
    } else {
      res = 1;
    }
  } else {
    if (rem_1 > 5) {
      tmp.bits[0] = 1;
      res = s21_big_mant_add(big_result, tmp, &big_result);
    } else if (rem_1 == 5) {
      remain = s21_big_mant_div(big_result, tmp, &num_1);
      rem_2 = remain.bits[0];
      if (rem_2 % 2 == 1) {
        tmp.bits[0] = 1;
        res = s21_big_mant_add(big_result, tmp, &big_result);
      }
    }
  }

  s21_big_set_scale(&big_result, res_scale);

  if (!res) {
    s21_big_to_dec(big_result, result);
  } else {
    result->bits[0] = 0U;
    result->bits[1] = 0U;
    result->bits[2] = 0U;
    result->bits[3] = 0U;
  }

  return res;
}
