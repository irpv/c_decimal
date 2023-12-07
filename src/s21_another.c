#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  big_decimal val_copy, remain, ten;
  s21_big_init(&remain);

  s21_big_init(&val_copy);
  s21_dec_to_big(value, &val_copy);

  s21_big_init(&ten);
  ten.bits[0] = 10;

  int scale = s21_get_scale(value), is_int = 1;

  while (scale && is_int) {
    remain = s21_big_mant_div(val_copy, ten, &val_copy);
    scale--;
    if (remain.bits[0]) {
      is_int = 0;
    }
  }

  s21_truncate(value, result);
  if (!is_int && s21_get_sign(value)) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_sub(*result, one, result);
  }
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal half = {{5}};
  s21_dec_init(result);

  s21_set_scale(&half, 1);
  int scale = s21_get_scale(value);
  *result = value;

  if (scale) {
    if (s21_get_sign(value)) {
      s21_sub(value, half, result);
    } else {
      s21_add(value, half, result);
    }
  }
  s21_truncate(*result, result);
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  big_decimal ten, tmp;
  s21_big_init(&tmp);
  s21_dec_to_big(value, &tmp);

  s21_big_init(&ten);
  ten.bits[0] = 10;

  int scale = s21_get_scale(value);

  while (scale) {
    s21_big_mant_div(tmp, ten, &tmp);
    scale--;
  }

  s21_big_set_scale(&tmp, 0);
  if (s21_get_sign(value)) s21_big_set_sign(&tmp);
  s21_big_to_dec(tmp, result);
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  value.bits[3] += 1U << 31;
  s21_dec_copy(value, result);
  return 0;
}
