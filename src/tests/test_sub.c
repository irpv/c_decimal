#include "tests.h"

START_TEST(s21_sub_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 5;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 6;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 787891;
  // src2 = 238471;
  src1.bits[0] = 0b00000000000011000000010110110011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000111010001110000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000110001000101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9;
  // src2 = 18571145;
  src1.bits[0] = 0b00000000000000000000000000001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000110110101111110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000110110101111110000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1849687;
  // src2 = 6;
  src1.bits[0] = 0b00000000000111000011100101010111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000111000011100101010001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -3187878;
  // src2 = 1;
  src1.bits[0] = 0b00000000001100001010010010100110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000001100001010010010100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 18768768;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000001000111100110001110000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000001000111100110001101111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615.0;
  // src2 = 3556877454;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b11010100000000011010010010001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10110111111011111001001001101010;
  origin.bits[1] = 0b11111111111111111111111111110111;
  origin.bits[2] = 0b00000000000000000000000000001001;
  origin.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -54896651557845.352654545456455;
  // src2 = 21465;
  src1.bits[0] = 0b01110001100100011000110101000111;
  src1.bits[1] = 0b00001111010011100000001101011111;
  src1.bits[2] = 0b10110001011000010111001000100100;
  src1.bits[3] = 0b10000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000101001111011001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01111001010101000000110101000111;
  origin.bits[1] = 0b00111001001100010000001100100101;
  origin.bits[2] = 0b10110001011000010111001000100101;
  origin.bits[3] = 0b10000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;
  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001110111001000011100101110110;
  origin.bits[1] = 0b01001011001101011010000111011001;
  origin.bits[2] = 0b00011001101110010111010010111111;
  origin.bits[3] = 0b00000000000011110000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_22) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_23) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_24) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011011000111100101100000001101;
  origin.bits[1] = 0b01101101111100110111111101100111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;
  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00001110111111111010100000101010;
  origin.bits[1] = 0b00101001110101100000001000110100;
  origin.bits[2] = 0b00000000000001011111000010100001;
  origin.bits[3] = 0b10000000000110000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_30) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011010101111100101111101110011;
  origin.bits[1] = 0b00101101001111010011000001101000;
  origin.bits[2] = 0b00000100101010001101010101010111;
  origin.bits[3] = 0b10000000000111000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_35) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01001111101101000110000001100101;
  origin.bits[1] = 0b01000010001101101011011001100001;
  origin.bits[2] = 0b01111010101111011000110010011010;
  origin.bits[3] = 0b00000000000011000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_36) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162513351883030198514100;
  // src2 = -912454563345436235;
  src1.bits[0] = 0b10110110000111000111000110110100;
  src1.bits[1] = 0b11110011010101100100111101101000;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001001111000111000111001001011;
  src2.bits[1] = 0b00001100101010011011000010010111;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_39) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = 79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_51) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_52) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 1;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_sub_53) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

Suite *suite_sub() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_sub" RESET);
  TCase *tc = tcase_create("decimal_sub_tc");

  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_22);
  tcase_add_test(tc, s21_sub_23);
  tcase_add_test(tc, s21_sub_24);
  tcase_add_test(tc, s21_sub_26);
  tcase_add_test(tc, s21_sub_28);
  tcase_add_test(tc, s21_sub_30);
  tcase_add_test(tc, s21_sub_35);
  tcase_add_test(tc, s21_sub_36);
  tcase_add_test(tc, s21_sub_39);
  tcase_add_test(tc, s21_sub_51);
  tcase_add_test(tc, s21_sub_52);
  tcase_add_test(tc, s21_sub_53);

  suite_add_tcase(s, tc);

  return s;
}
