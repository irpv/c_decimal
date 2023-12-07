#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define RESET "\x1b[0m"
#define YELLOW_BG "\x1b[103m"
#define BLACK "\x1b[30m"
#define WHITE "\x1b[97m"

#define RED_BG "\x1b[41m"
#define GREEN_BG "\x1b[42m"
#define WHITE_BG "\x1b[47m"
#define GRAY_BG "\x1b[100m"

Suite *suite_add();
Suite *suite_sub();
Suite *suite_mul();
Suite *suite_div();

Suite *suite_is_less();
Suite *suite_is_less_or_equal();
Suite *suite_is_greater();
Suite *suite_is_greater_or_equal();
Suite *suite_is_equal();
Suite *suite_is_not_equal();

Suite *suite_from_int_to_decimal();
Suite *suite_from_float_to_decimal();
Suite *suite_from_decimal_to_int();
Suite *suite_from_decimal_to_float();

Suite *suite_floor();
Suite *suite_round();
Suite *suite_truncate();
Suite *suite_negate();

void run();

#endif  // SRC_TESTS_TESTS_H_
