#include "tests.h"

START_TEST(mul_1) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  a.bits[0] = 10;
  b.bits[0] = 10;

  s21_res = s21_mul(a, b, &s21_out);

  out.bits[0] = 100;

  res = 0;
  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_2) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  a.bits[0] = 10;
  b.bits[1] = 100;

  s21_res = s21_mul(a, b, &s21_out);

  out.bits[1] = 1000;

  res = 0;
  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_3) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  a.bits[0] = 1000;
  b.bits[0] = 564;
  s21_set_scale(&b, 3);

  s21_res = s21_mul(a, b, &s21_out);

  out.bits[0] = 564000;
  s21_set_scale(&out, 3);

  res = 0;
  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_4) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 0.00053134127045542888
  // b = 5194990512920245129183.796

  a.bits[0] = 1000;
  a.bits[1] = 12371253;
  b.bits[0] = 564;
  s21_set_scale(&a, 20);
  b.bits[1] = 32151;
  b.bits[2] = 281621;
  s21_set_scale(&b, 3);

  s21_res = s21_mul(a, b, &s21_out);

  out.bits[0] = 3494094530;
  out.bits[1] = 1327394782;
  out.bits[2] = 1496368599;
  s21_set_scale(&out, 10);

  res = 0;
  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_5) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 53134127045542888
  // b = 2 * 10^(-20)

  a.bits[0] = 1000;
  a.bits[1] = 12371253;
  b.bits[0] = 2;
  s21_set_scale(&b, 20);

  s21_res = s21_mul(a, b, &s21_out);

  out.bits[0] = 2000;
  out.bits[1] = 24742506;
  s21_set_scale(&out, 20);

  res = 0;
  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_6) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = b = 10^(-20)

  a.bits[0] = 1;
  b.bits[0] = 1;
  s21_set_scale(&a, 20);
  s21_set_scale(&b, 20);

  s21_res = s21_mul(a, b, &s21_out);

  s21_set_scale(&out, 28);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_7) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // overflow

  a.bits[0] = 1126;
  a.bits[1] = 1236178;
  a.bits[2] = 48736128;
  b.bits[0] = 123145;
  b.bits[1] = 57215;
  b.bits[2] = 4200000000;

  s21_res = s21_mul(a, b, &s21_out);

  res = 1;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_8) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // overflow

  a.bits[0] = 1126;
  a.bits[1] = 1236178;
  a.bits[2] = 48736128;
  b.bits[0] = 123145;
  b.bits[1] = 57215;
  b.bits[2] = 4200000000;
  s21_set_sign(&b);

  s21_res = s21_mul(a, b, &s21_out);

  res = 2;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_9) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 27148488278016
  // b = -11865276.6522122

  a.bits[1] = 6321;
  b.bits[0] = 2826;
  b.bits[1] = 27626;

  s21_set_scale(&b, 7);
  s21_set_sign(&b);

  s21_res = s21_mul(a, b, &s21_out);

  out.bits[1] = 17863146;
  out.bits[2] = 174623946;
  s21_set_scale(&out, 7);
  s21_set_sign(&out);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_10) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 264093875.04754779197847983445
  // b = -11865276.6522122

  a.bits[0] = 1431655765;
  a.bits[1] = 1431655765;
  a.bits[2] = 1431655765;
  s21_set_scale(&a, 20);
  b.bits[0] = 2826;
  b.bits[1] = 27626;
  s21_set_scale(&b, 7);
  s21_set_sign(&b);

  s21_res = s21_mul(a, b, &s21_out);
  out.bits[0] = 1596988596;
  out.bits[1] = 2755044718;
  out.bits[2] = 1698699172;
  s21_set_scale(&out, 13);
  s21_set_sign(&out);

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_11) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 26409387504754779197847983445
  // b = 1.5

  a.bits[0] = 1431655765;
  a.bits[1] = 1431655765;
  a.bits[2] = 1431655765;
  b.bits[0] = 15;
  s21_set_scale(&b, 1);

  s21_res = s21_mul(a, b, &s21_out);
  out.bits[2] = 2147483648;

  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(mul_12) {
  int res, s21_res;
  s21_decimal a, b, s21_out, out;
  s21_dec_init(&a);
  s21_dec_init(&b);
  s21_dec_init(&s21_out);
  s21_dec_init(&out);

  // a = 22269.27994753735728376691
  // b = 4313701.18878858752485752847

  a.bits[0] = 2138123123;
  a.bits[1] = 36481621;
  a.bits[2] = 120722;
  s21_set_scale(&a, 20);
  b.bits[0] = 15;
  b.bits[1] = 7256126;
  b.bits[2] = 23384621;
  s21_set_scale(&b, 20);

  s21_res = s21_mul(a, b, &s21_out);
  out.bits[0] = 3306044434;
  out.bits[1] = 2378053747;
  out.bits[2] = 520758671;
  s21_set_scale(&out, 17);
  res = 0;

  ck_assert_int_eq(s21_out.bits[0], out.bits[0]);
  ck_assert_int_eq(s21_out.bits[1], out.bits[1]);
  ck_assert_int_eq(s21_out.bits[2], out.bits[2]);
  ck_assert_int_eq(s21_out.bits[3], out.bits[3]);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_mul_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
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

START_TEST(s21_mul_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
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

START_TEST(s21_mul_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
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

START_TEST(s21_mul_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
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

START_TEST(s21_mul_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
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

START_TEST(s21_mul_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00011100110011110011101011000001;
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

START_TEST(s21_mul_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010111010001100111010001101100;
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

START_TEST(s21_mul_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010011100100010101101110010110;
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

START_TEST(s21_mul_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001100;
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

START_TEST(s21_mul_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110001;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11100110011101111000010101001111;
  origin.bits[1] = 0b00000000000000000000000000000110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_23) {
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
  value_type_result = s21_mul(src1, src2, &result);
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

START_TEST(s21_mul_24) {
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
  value_type_result = s21_mul(src1, src2, &result);
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

START_TEST(s21_mul_25) {
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
  value_type_result = s21_mul(src1, src2, &result);
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

START_TEST(s21_mul_26) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_27) {
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
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011111001100010111011110111010;
  origin.bits[1] = 0b01000100111111001101101110110001;
  origin.bits[2] = 0b00000001101011100011011100011110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_28) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000100010110100111001000111001;
  origin.bits[1] = 0b01100100100011011110110011010011;
  origin.bits[2] = 0b00000000000001001101011111010011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_33) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

Suite *suite_mul() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_mul" RESET);
  TCase *tc = tcase_create("decimal_mul_tc");

  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);
  tcase_add_test(tc, s21_mul_27);
  tcase_add_test(tc, s21_mul_28);
  tcase_add_test(tc, s21_mul_33);

  suite_add_tcase(s, tc);

  return s;
}
