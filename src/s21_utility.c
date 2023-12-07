#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

void s21_dec_copy(s21_decimal root, s21_decimal* dest) {
  dest->bits[0] = root.bits[0];
  dest->bits[1] = root.bits[1];
  dest->bits[2] = root.bits[2];
  dest->bits[3] = root.bits[3];
}

void s21_dec_init(s21_decimal* num) {
  num->bits[0] = num->bits[1] = num->bits[2] = num->bits[3] = 0;
}

void s21_set_sign(s21_decimal* dst) { dst->bits[3] = dst->bits[3] | 1U << 31; }

int s21_get_sign(s21_decimal dst) {
  int sign = (dst.bits[3] & 1U << 31) != 0;

  return sign;
}

int s21_get_bit(s21_decimal dst, int idx) {
  unsigned mask = 1U << (idx % 32);
  int bit = (dst.bits[idx / 32] & mask) != 0;

  return bit;
}

int s21_get_scale(s21_decimal dst) {
  int mask = 0b11111111 << 16;
  int scale = (dst.bits[3] & mask) >> 16;

  return scale;
}

void s21_set_scale(s21_decimal* num, int value) {
  value <<= 16;
  char sign = s21_get_sign(*num);
  num->bits[3] = value;
  if (sign) s21_set_sign(num);
}

int s21_is_empty(s21_decimal value) {
  int res = 1;
  if (value.bits[0] || value.bits[1] || value.bits[2]) {
    res = 0;
  }
  return res;
}
