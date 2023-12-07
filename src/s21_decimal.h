#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

typedef struct {
  unsigned int bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// ---

// same as s21_decimal, but now number contains of 6 bytes
typedef struct {
  unsigned int bits[7];
} big_decimal;

typedef union {
  float f;
  int i;
} convert;

void s21_dec_init(s21_decimal *num);
void s21_dec_copy(s21_decimal root, s21_decimal *dest);

void s21_set_sign(s21_decimal *dst);
int s21_get_sign(s21_decimal dst);
int s21_get_bit(s21_decimal dst, int idx);
int s21_get_scale(s21_decimal dst);
void s21_set_scale(s21_decimal *num, int value);
int s21_is_empty(s21_decimal value);

//  ---BIG DECIMAL---

void s21_dec_to_big(s21_decimal num, big_decimal *big_num);
void s21_big_to_dec(big_decimal big_num, s21_decimal *num);
void s21_big_init(big_decimal *num);
void s21_big_copy(big_decimal root, big_decimal *dest);
int s21_big_is_empty(big_decimal value);
int s21_big_get_scale(big_decimal dst);
void s21_big_set_scale(big_decimal *num, int value);
int s21_big_get_sign(big_decimal dst);
void s21_big_set_sign(big_decimal *dst);
void s21_equal_scales(big_decimal *num_1, big_decimal *num_2);
int compare_big_decimal_alt_sign(big_decimal var1, big_decimal var2);
int compare_big_decimal_alt_digit(big_decimal var1, big_decimal var2);
big_decimal scale_big_decimal_alt_up(big_decimal op);
big_decimal normalization_big_decimal_alt(big_decimal src, int scale);

/*
  mant_* функции работают только с мантиссами чисел (сложить мантиссы, поделить
  мантиссы и т.д.)
*/
int s21_big_mant_mult(big_decimal num_1, big_decimal num_2,
                      big_decimal *result);
int s21_big_mant_add(big_decimal value_1, big_decimal value_2,
                     big_decimal *result);
big_decimal s21_big_mant_div(big_decimal num_1, big_decimal num_2,
                             big_decimal *result);
void s21_big_mant_sub(big_decimal value_1, big_decimal value_2,
                      big_decimal *result);

int s21_mant_big_is_bigger_or_equal(big_decimal value_1, big_decimal value_2);

#endif  // SRC_S21_DECIMAL_H_
