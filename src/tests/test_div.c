#include "tests.h"

START_TEST(div_1) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 2
  // b = 1

  a.bits[0] = 2;
  b.bits[0] = 1;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 2;

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_2) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 2 * 2^64
  // b = 1 * 2^64

  a.bits[2] = 2;
  b.bits[2] = 1;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 2;

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_3) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 11
  // b = 110

  a.bits[0] = 11;
  b.bits[0] = 110;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 1;
  s21_set_scale(&out, 1);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_4) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 1
  // b = -3

  a.bits[0] = 1;
  b.bits[0] = 3;

  s21_set_sign(&b);

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 89478482;
  out.bits[1] = 347537611;
  out.bits[2] = 180700362;
  s21_set_scale(&out, 28);
  s21_set_sign(&out);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_5) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 10^(-10) * 2^32
  // b = -3 * 2^32

  a.bits[1] = 1;
  b.bits[1] = 3;

  s21_set_scale(&a, 10);

  s21_set_sign(&b);

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 2367771986;
  out.bits[1] = 77610214;
  s21_set_scale(&out, 28);
  s21_set_sign(&out);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_6) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 169371769086518165913564024
  // b = 3

  a.bits[0] = 2716536;
  a.bits[1] = 282651;
  a.bits[2] = 9181662;
  b.bits[0] = 3;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 905512;
  out.bits[1] = 94217;
  out.bits[2] = 3060554;

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_7) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 169371769086518165913564024
  // b = 3

  a.bits[0] = 2716537;
  a.bits[1] = 282651;
  a.bits[2] = 9181662;
  b.bits[0] = 3;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 905512333;
  out.bits[1] = 94217000;
  out.bits[2] = 3060554000;
  s21_set_scale(&out, 3);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_8) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 169371769086518165913564025
  // b = 0

  a.bits[0] = 2716537;
  a.bits[1] = 282651;
  a.bits[2] = 9181662;
  b.bits[0] = 0;

  s21_res = s21_div(a, b, &s21_out);

  res = 1;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_9) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = -169371769086518165913564025
  // b = 0

  a.bits[0] = 2716537;
  a.bits[1] = 282651;
  a.bits[2] = 9181662;
  s21_set_sign(&a);
  b.bits[0] = 0;

  s21_res = s21_div(a, b, &s21_out);

  res = 2;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_10) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 0
  // b = 0

  a.bits[0] = 0;
  b.bits[0] = 0;

  s21_res = s21_div(a, b, &s21_out);

  res = 3;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_11) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 79228160761823650183114653600
  // b = 10^(-20)

  a.bits[0] = 4294967200;
  a.bits[1] = 4294967200;
  a.bits[2] = 4294967200;

  b.bits[0] = 1;
  s21_set_scale(&b, 20);

  s21_res = s21_div(a, b, &s21_out);

  res = 1;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_12) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 79228160761823650183114653600
  // b = 10^(-20)

  a.bits[0] = 4294967200;
  a.bits[1] = 4294967200;
  a.bits[2] = 4294967200;

  b.bits[0] = 1;
  s21_set_scale(&b, 20);
  s21_set_sign(&b);

  s21_res = s21_div(a, b, &s21_out);

  res = 2;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_13) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 79228160761823650187409620897
  // b = 2

  a.bits[0] = 4294967201;
  a.bits[1] = 4294967201;
  a.bits[2] = 4294967200;

  b.bits[0] = 2;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 4294967248;
  out.bits[1] = 2147483600;
  out.bits[2] = 2147483600;
  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(div_14) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 79228160761823650187409620895
  // b = 2

  a.bits[0] = 4294967199;
  a.bits[1] = 4294967201;
  a.bits[2] = 4294967200;

  b.bits[0] = 2;

  s21_res = s21_div(a, b, &s21_out);

  out.bits[0] = 4294967248;
  out.bits[1] = 2147483600;
  out.bits[2] = 2147483600;
  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_div_1) {
  s21_decimal src1, src2, result, origin;
  // 30064771176
  // 3
  // 10021590392
  src1.bits[0] = 0b00000000000000000000000001101000;
  src1.bits[1] = 0b00000000000000000000000000000111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  origin.bits[0] = 0b01010101010101010101010101111000;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal src1, src2, result;
  int a = 32768;
  int b = -2;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -16384;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  s21_from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal src1, src2, result;
  int a = 32768;
  int b = 2;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 16384;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  s21_from_decimal_to_int(result, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal src1, src2, result, origin;
  // 0
  // 0.015
  // 0
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal src1, src2, result;
  float a = 1.0 / 0.0;
  float b = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  int check = s21_div(src1, src2, &result);
  int check_origin = 3;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(s21_div_11) {
  s21_decimal src1, src2, result;
  src1.bits[0] = 0x0006BFD0;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000028;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;

  int check = s21_div(src1, src2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check_origin, check);
  ck_assert_int_eq(result.bits[3], 0x00000000);
  ck_assert_int_eq(result.bits[2], 0x00000000);
  ck_assert_int_eq(result.bits[1], 0x00000000);
  ck_assert_int_eq(result.bits[0], 0x00002B32);
}
END_TEST

Suite *suite_div() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_div" RESET);
  TCase *tc = tcase_create("decimal_div_tc");

  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_8);
  tcase_add_test(tc, s21_div_11);

  suite_add_tcase(s, tc);

  return s;
}
