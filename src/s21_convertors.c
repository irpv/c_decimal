#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int errorFlag = 0;

  if (dst == NULL) {
    errorFlag = 1;
    dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
  } else {
    dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
    if (src < 0) {
      s21_set_sign(dst);
      src = abs(src);
    }

    if (src > INT_MAX) {
      errorFlag = 1;
    } else {
      dst->bits[0] = src;
    }
  }

  return errorFlag;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int errorFlag = 0;

  if (dst == NULL || isnan(src) || isinf(src)) {
    errorFlag = 1;
    dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
  } else {
    dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;

    // sign is 0 or -1, scale is (x is aprox = 2**scale)
    int sign = *(int *)&src >> 31;
    int scale = ((*(int *)&src & ~0x80000000) >> 23) - 127;
    double tmp = fabs(src);
    int offset = 0;

    // 28 is max exp we can have
    while (offset < 28 && (int)tmp / (int)pow(2, 21) == 0) {
      tmp *= 10;
      offset++;
    }

    tmp = round(tmp);

    // +-95 is max for exp
    if (offset <= 28 && (scale > -94 && scale < 96)) {
      convert mnts = {0};

      while (fmod(tmp, 10) == 0 && offset > 0) {
        tmp /= 10;
        offset--;
      }

      mnts.f = tmp;
      scale = ((*(int *)&mnts.f & ~0x80000000) >> 23) - 127;
      dst->bits[scale / 32] |= 1 << scale % 32;

      // fills [0..2] arrays with "main number", 23 is our mantiassa number
      int b = scale - 1;
      for (int x = 22; x >= 0; x--) {
        if ((mnts.i & (1 << x)) != 0) {
          dst->bits[b / 32] |= 1 << b % 32;
        }
        b--;
      }

      // fills "extra" info in bits[3] (sign and scale)
      dst->bits[3] = (sign << 31) | (offset << 16);
    }
  }

  return errorFlag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int errorFlag = 0;

  if (dst == NULL) {
    errorFlag = 1;
  } else {
    int result = s21_truncate(src, &src);

    if (result || src.bits[1] || src.bits[2]) {
      errorFlag = 1;
    } else {
      *dst = src.bits[0];
    }

    if (s21_get_sign(src)) {
      *dst *= -1;
    }
  }

  return errorFlag;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int errorFlag = 0;

  if (dst == NULL) {
    errorFlag = 1;
  } else {
    double tmp = 0;
    for (int i = 0; i < 96; i++) {
      tmp += s21_get_bit(src, i) * pow(2, i);
    }
    tmp *= pow(10, -s21_get_scale(src));

    if (s21_get_sign(src)) {
      tmp *= -1;
    }

    *dst = (float)tmp;
  }

  return errorFlag;
}
