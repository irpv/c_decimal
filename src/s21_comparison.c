#include "s21_decimal.h"

int s21_is_less(s21_decimal var1, s21_decimal var2) {
  int result = 0;
  big_decimal big_var1;
  big_decimal big_var2;
  s21_dec_to_big(var1, &big_var1);
  s21_dec_to_big(var2, &big_var2);

  if ((compare_big_decimal_alt_sign(big_var1, big_var2) == 2 &&
       compare_big_decimal_alt_digit(big_var1, big_var2) == -1) ||
      (compare_big_decimal_alt_sign(big_var1, big_var2) == -2 &&
       compare_big_decimal_alt_digit(big_var1, big_var2) == 1) ||
      (!s21_big_is_empty(big_var1) &&
       compare_big_decimal_alt_sign(big_var1, big_var2) == -1))
    result = 1;
  if (s21_big_is_empty(big_var1) && s21_big_is_empty(big_var2)) {
    result = 0;
  }
  return result;
}

int s21_is_less_or_equal(s21_decimal var1, s21_decimal var2) {
  return (s21_is_less(var1, var2) || s21_is_equal(var1, var2));
}

int s21_is_greater(s21_decimal var1, s21_decimal var2) {
  return (!s21_is_less(var1, var2) && !s21_is_equal(var1, var2));
}

int s21_is_greater_or_equal(s21_decimal var1, s21_decimal var2) {
  return (s21_is_greater(var1, var2) || s21_is_equal(var1, var2));
}

int s21_is_equal(s21_decimal var1, s21_decimal var2) {
  int result = 0;
  big_decimal big_var1;
  big_decimal big_var2;
  s21_dec_to_big(var1, &big_var1);
  s21_dec_to_big(var2, &big_var2);
  if (s21_big_is_empty(big_var1) && s21_big_is_empty(big_var2)) {
    result = 1;
  }
  int sign = compare_big_decimal_alt_sign(big_var1, big_var2);
  if ((sign == -2 || sign == 2) &&
      (compare_big_decimal_alt_digit(big_var1, big_var2) == 0)) {
    result = 1;
  }
  return result;
}

int s21_is_not_equal(s21_decimal var1, s21_decimal var2) {
  return !s21_is_equal(var1, var2);
}
