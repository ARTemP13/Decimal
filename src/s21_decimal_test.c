#include "s21_decimal.h"

#include <check.h>
#include <time.h>
#include <unistd.h>

START_TEST(test_truncate1) {
  s21_decimal a;
  a.bits[0] = 123456;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST
START_TEST(test_truncate2) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000010110000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 4687969);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_truncate3) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000100110000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 102838082);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_truncate4) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 1883637475);
  ck_assert_uint_eq(res.bits[1], 239);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_truncate5) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 1883637475);
  ck_assert_uint_eq(res.bits[1], 239);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_truncate6) {
  s21_decimal a;
  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_truncate7) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 214955891);
  ck_assert_uint_eq(res.bits[1], 2587895406);
  ck_assert_uint_eq(res.bits[2], 5574863);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_truncate8) {
  s21_decimal a;
  a.bits[0] = 0;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal res;
  s21_truncate(a, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

///
START_TEST(test_floor1) {
  s21_decimal a;
  a.bits[0] = 123456;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST
START_TEST(test_floor2) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000010110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 4687969);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor3) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000100110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 102838082);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor4) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 1883637475);
  ck_assert_uint_eq(res.bits[1], 239);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor5) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 1883637475);
  ck_assert_uint_eq(res.bits[1], 239);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor6) {
  s21_decimal a;
  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor7) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 214955891);
  ck_assert_uint_eq(res.bits[1], 2587895406);
  ck_assert_uint_eq(res.bits[2], 5574863);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor8) {
  s21_decimal a;
  a.bits[0] = 0;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

///
////
////
START_TEST(test_floor9) {
  s21_decimal a;
  a.bits[0] = 123456;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 124);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST
START_TEST(test_floor10) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b10000000000010110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 4687970);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_floor11) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b10000000000100110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 102838083);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_floor12) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b10000000000011110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 1883637476);
  ck_assert_uint_eq(res.bits[1], 239);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_floor13) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b10000000000011110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 1883637476);
  ck_assert_uint_eq(res.bits[1], 239);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_floor14) {
  s21_decimal a;
  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_floor15) {
  s21_decimal a;
  a.bits[0] = 0b10000000000111111010101010000000;
  a.bits[1] = 0b00000110100000011000000001001100;
  a.bits[2] = 0b00000011010100101010100000011100;
  a.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 214955892);
  ck_assert_uint_eq(res.bits[1], 2587895406);
  ck_assert_uint_eq(res.bits[2], 5574863);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_floor16) {
  s21_decimal a;
  a.bits[0] = 0;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000011110000000000000000;
  s21_decimal res;
  s21_floor(a, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_from_int_to_decimal) {
  s21_decimal a;
  int value1 = 0;
  int value2 = 2147483647;
  int value3 = -2147483647;
  int value4 = 12312321;
  int value5 = -12312321;
  s21_from_int_to_decimal(value1, &a);
  ck_assert_uint_eq(a.bits[0], 0);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b00000000000000000000000000000000);

  s21_from_int_to_decimal(value2, &a);
  ck_assert_uint_eq(a.bits[0], 2147483647);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b00000000000000000000000000000000);

  s21_from_int_to_decimal(value3, &a);
  ck_assert_uint_eq(a.bits[0], 2147483647);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b10000000000000000000000000000000);

  s21_from_int_to_decimal(value4, &a);
  ck_assert_uint_eq(a.bits[0], 12312321);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b00000000000000000000000000000000);

  s21_from_int_to_decimal(value5, &a);
  ck_assert_uint_eq(a.bits[0], 12312321);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_from_decimal_to_int) {
  s21_decimal a;
  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  int value1 = 0;
  int val = 0;
  s21_from_decimal_to_int(a, &value1);
  ck_assert_int_eq(value1, 123);

  a.bits[0] = 123;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000000000000000000000;
  s21_from_decimal_to_int(a, &value1);
  ck_assert_int_eq(value1, -123);

  a.bits[0] = 123;
  a.bits[1] = 1234;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000000000000000000000;
  val = s21_from_decimal_to_int(a, &value1);
  ck_assert_int_eq(val, 1);

  a.bits[0] = 2147483647;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000000000000000000000;
  s21_from_decimal_to_int(a, &value1);
  ck_assert_int_eq(value1, -2147483647);

  a.bits[0] = 2147483647;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_from_decimal_to_int(a, &value1);
  ck_assert_int_eq(a.bits[0], 2147483647);
}
END_TEST

START_TEST(test_from_decimal_to_int1) {
  int num = 0;
  s21_decimal a = {{78293592, 0, 0, 0b00000000000000010000000000000000}};

  int res = s21_from_decimal_to_int(a, &num);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(num, 7829359);
}
END_TEST

START_TEST(test_round1) {
  s21_decimal a;
  a.bits[0] = 1234;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_round2) {
  s21_decimal a;
  a.bits[0] = 1235;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 124);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_round3) {
  s21_decimal a;
  a.bits[0] = 1238;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 124);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_round4) {
  s21_decimal a;
  a.bits[0] = 0;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b00000000000011010000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_round5) {
  s21_decimal a;
  a.bits[0] = 1235;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 124);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_round6) {
  s21_decimal a;
  a.bits[0] = 0b10000001111100010000000010100001;
  a.bits[1] = 0b00001111010000010000001001000000;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000001100000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 3945599656);
  ck_assert_uint_eq(res.bits[1], 255);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_round7) {
  s21_decimal a;
  a.bits[0] = 0b10000001111100010000000010100001;
  a.bits[1] = 0b00001111010000010000001001000000;
  a.bits[2] = 0b00001111010000010000001001000000;
  a.bits[3] = 0b00000000000110110000000000000000;
  s21_decimal res;
  s21_round(a, &res);
  ck_assert_uint_eq(res.bits[0], 5);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_is_equal_test_1) {
  s21_decimal a = {
      {7823482, 278348234, 23742342, 131072}};  // 4379689077799819450709034.18
  s21_decimal b = {
      {7238423, 2378423, 2734234, 262144}};  // 5043771484585041116151.4775

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_2) {
  s21_decimal a = {{72342, 0, 0, -2147352576}};  // -723.42
  s21_decimal b = {{72342, 0, 0, -2147352576}};  // -723.42

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_3) {
  s21_decimal a = {{8234, 238423, 23482, 65536}};  // 43316644536286667866935.4
  s21_decimal b = {{234, 2342, 0, -2147155968}};   // -100588134.07466

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_4) {
  s21_decimal a = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410
  s21_decimal b = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_5) {
  s21_decimal a = {{2124678, 0, 0, -2147287040}};  // -2124.678
  s21_decimal b = {{2124678, 0, 0, -2147155968}};  // -21.24678

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_6) {
  s21_decimal a = {{7283842, 0, 0, 720896}};  // 0.00007283842
  s21_decimal b = {{7283842, 0, 0, 720896}};  // 0.00007283842

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_7) {
  s21_decimal a = {{28342, 293942, 9123, 262144}};  // 16828964744692351634.1942
  s21_decimal b = {{823, 2234, 234234, 262144}};  // 432085465137087807016.2231

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_8) {
  s21_decimal a = {{723, 2323, 9, 983040}};  // 166020.706640594993875
  s21_decimal b = {{723, 2323, 9, 983040}};  // 166020.706640594993875

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_9) {
  s21_decimal a = {{8923, 90, 0, -2147155968}};  // -3865470.65563
  s21_decimal b = {{8923, 90, 2, -2147352576}};  // -368934885339661687.95

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_10) {
  s21_decimal a = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568
  s21_decimal b = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_11) {
  s21_decimal a = {{-234234, 932, 19231, 655360}};  // 35474933528551.5591380230
  s21_decimal b = {
      {-234823, -2387423, 237472, 655360}};  // 438060364516212.8938920633

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_12) {
  s21_decimal a = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776
  s21_decimal b = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_13) {
  s21_decimal a = {
      {823, 2387482, -23842, 1310720}};  // 792277227.07002386367524111159
  s21_decimal b = {
      {8234, 23891, -1347324, -2147221504}};  // -7920330877325207355668615.1722

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_14) {
  s21_decimal a = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441
  s21_decimal b = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_15) {
  s21_decimal a = {{28994, 2378193, -13843,
                    -2147221504}};  // -7922790715599633949337953.5170
  s21_decimal b = {
      {200023, 878323, 134234234, 0}};  // 2476184560532213568217746775

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_16) {
  s21_decimal a = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010
  s21_decimal b = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_17) {
  s21_decimal a = {
      {289293, 237823, -12391, 655360}};  // 7922793394065954170.0497402381
  s21_decimal b = {
      {82342, -234, 2838, -2147221504}};  // -5237030642425639477.2902

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_18) {
  s21_decimal a = {{237423, 23942, 0, 0}};  // 102830107238255
  s21_decimal b = {{237423, 23942, 0, 0}};  // 102830107238255

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_equal_test_19) {
  s21_decimal a = {{2, 392, 0, 0}};          // 1683627180034
  s21_decimal b = {{823, 239923, 9923, 0}};  // 183047042473881319244599

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_equal_test_20) {
  s21_decimal a = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726
  s21_decimal b = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726

  int res = s21_is_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_1) {
  s21_decimal a = {
      {7823482, 278348234, 23742342, 131072}};  // 4379689077799819450709034.18
  s21_decimal b = {
      {7238423, 2378423, 2734234, 262144}};  // 5043771484585041116151.4775

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_2) {
  s21_decimal a = {{72342, 0, 0, -2147352576}};  // -723.42
  s21_decimal b = {{72342, 0, 0, -2147352576}};  // -723.42

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_3) {
  s21_decimal a = {{8234, 238423, 23482, 65536}};  // 43316644536286667866935.4
  s21_decimal b = {{234, 2342, 0, -2147155968}};   // -100588134.07466

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_4) {
  s21_decimal a = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410
  s21_decimal b = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_5) {
  s21_decimal a = {{2124678, 0, 0, -2147287040}};  // -2124.678
  s21_decimal b = {{2124678, 0, 0, -2147155968}};  // -21.24678

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_6) {
  s21_decimal a = {{7283842, 0, 0, 720896}};  // 0.00007283842
  s21_decimal b = {{7283842, 0, 0, 720896}};  // 0.00007283842

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_7) {
  s21_decimal a = {{28342, 293942, 9123, 262144}};  // 16828964744692351634.1942
  s21_decimal b = {{823, 2234, 234234, 262144}};  // 432085465137087807016.2231

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_8) {
  s21_decimal a = {{723, 2323, 9, 983040}};  // 166020.706640594993875
  s21_decimal b = {{723, 2323, 9, 983040}};  // 166020.706640594993875

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_9) {
  s21_decimal a = {{8923, 90, 0, -2147155968}};  // -3865470.65563
  s21_decimal b = {{8923, 90, 2, -2147352576}};  // -368934885339661687.95

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_10) {
  s21_decimal a = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568
  s21_decimal b = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_11) {
  s21_decimal a = {{-234234, 932, 19231, 655360}};  // 35474933528551.5591380230
  s21_decimal b = {
      {-234823, -2387423, 237472, 655360}};  // 438060364516212.8938920633

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_12) {
  s21_decimal a = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776
  s21_decimal b = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_13) {
  s21_decimal a = {
      {823, 2387482, -23842, 1310720}};  // 792277227.07002386367524111159
  s21_decimal b = {
      {8234, 23891, -1347324, -2147221504}};  // -7920330877325207355668615.1722

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_14) {
  s21_decimal a = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441
  s21_decimal b = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_15) {
  s21_decimal a = {{28994, 2378193, -13843,
                    -2147221504}};  // -7922790715599633949337953.5170
  s21_decimal b = {
      {200023, 878323, 134234234, 0}};  // 2476184560532213568217746775

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_16) {
  s21_decimal a = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010
  s21_decimal b = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_17) {
  s21_decimal a = {
      {289293, 237823, -12391, 655360}};  // 7922793394065954170.0497402381
  s21_decimal b = {
      {82342, -234, 2838, -2147221504}};  // -5237030642425639477.2902

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_18) {
  s21_decimal a = {{237423, 23942, 0, 0}};  // 102830107238255
  s21_decimal b = {{237423, 23942, 0, 0}};  // 102830107238255

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_19) {
  s21_decimal a = {{2, 392, 0, 0}};          // 1683627180034
  s21_decimal b = {{823, 239923, 9923, 0}};  // 183047042473881319244599

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_20) {
  s21_decimal a = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726
  s21_decimal b = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726

  int res = s21_is_greater_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_1) {
  s21_decimal a = {
      {7823482, 278348234, 23742342, 131072}};  // 4379689077799819450709034.18
  s21_decimal b = {
      {7238423, 2378423, 2734234, 262144}};  // 5043771484585041116151.4775

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_2) {
  s21_decimal a = {{72342, 0, 0, -2147352576}};  // -723.42
  s21_decimal b = {{72342, 0, 0, -2147352576}};  // -723.42

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_3) {
  s21_decimal a = {{8234, 238423, 23482, 65536}};  // 43316644536286667866935.4
  s21_decimal b = {{234, 2342, 0, -2147155968}};   // -100588134.07466

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_4) {
  s21_decimal a = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410
  s21_decimal b = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_5) {
  s21_decimal a = {{2124678, 0, 0, -2147287040}};  // -2124.678
  s21_decimal b = {{2124678, 0, 0, -2147155968}};  // -21.24678

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_6) {
  s21_decimal a = {{7283842, 0, 0, 720896}};  // 0.00007283842
  s21_decimal b = {{7283842, 0, 0, 720896}};  // 0.00007283842

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_7) {
  s21_decimal a = {{28342, 293942, 9123, 262144}};  // 16828964744692351634.1942
  s21_decimal b = {{823, 2234, 234234, 262144}};  // 432085465137087807016.2231

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_8) {
  s21_decimal a = {{723, 2323, 9, 983040}};  // 166020.706640594993875
  s21_decimal b = {{723, 2323, 9, 983040}};  // 166020.706640594993875

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_9) {
  s21_decimal a = {{8923, 90, 0, -2147155968}};  // -3865470.65563
  s21_decimal b = {{8923, 90, 2, -2147352576}};  // -368934885339661687.95

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_10) {
  s21_decimal a = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568
  s21_decimal b = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_11) {
  s21_decimal a = {{-234234, 932, 19231, 655360}};  // 35474933528551.5591380230
  s21_decimal b = {
      {-234823, -2387423, 237472, 655360}};  // 438060364516212.8938920633

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_12) {
  s21_decimal a = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776
  s21_decimal b = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_13) {
  s21_decimal a = {
      {823, 2387482, -23842, 1310720}};  // 792277227.07002386367524111159
  s21_decimal b = {
      {8234, 23891, -1347324, -2147221504}};  // -7920330877325207355668615.1722

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_14) {
  s21_decimal a = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441
  s21_decimal b = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_15) {
  s21_decimal a = {{28994, 2378193, -13843,
                    -2147221504}};  // -7922790715599633949337953.5170
  s21_decimal b = {
      {200023, 878323, 134234234, 0}};  // 2476184560532213568217746775

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_16) {
  s21_decimal a = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010
  s21_decimal b = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_17) {
  s21_decimal a = {
      {289293, 237823, -12391, 655360}};  // 7922793394065954170.0497402381
  s21_decimal b = {
      {82342, -234, 2838, -2147221504}};  // -5237030642425639477.2902

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_18) {
  s21_decimal a = {{237423, 23942, 0, 0}};  // 102830107238255
  s21_decimal b = {{237423, 23942, 0, 0}};  // 102830107238255

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_19) {
  s21_decimal a = {{2, 392, 0, 0}};          // 1683627180034
  s21_decimal b = {{823, 239923, 9923, 0}};  // 183047042473881319244599

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_20) {
  s21_decimal a = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726
  s21_decimal b = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726

  int res = s21_is_greater(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_1) {
  s21_decimal a = {
      {7823482, 278348234, 23742342, 131072}};  // 4379689077799819450709034.18
  s21_decimal b = {
      {7238423, 2378423, 2734234, 262144}};  // 5043771484585041116151.4775

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_2) {
  s21_decimal a = {{72342, 0, 0, -2147352576}};  // -723.42
  s21_decimal b = {{72342, 0, 0, -2147352576}};  // -723.42

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_3) {
  s21_decimal a = {{8234, 238423, 23482, 65536}};  // 43316644536286667866935.4
  s21_decimal b = {{234, 2342, 0, -2147155968}};   // -100588134.07466

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_4) {
  s21_decimal a = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410
  s21_decimal b = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_6) {
  s21_decimal a = {{7283842, 0, 0, 720896}};  // 0.00007283842
  s21_decimal b = {{7283842, 0, 0, 720896}};  // 0.00007283842

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_7) {
  s21_decimal a = {{28342, 293942, 9123, 262144}};  // 16828964744692351634.1942
  s21_decimal b = {{823, 2234, 234234, 262144}};  // 432085465137087807016.2231

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_8) {
  s21_decimal a = {{723, 2323, 9, 983040}};  // 166020.706640594993875
  s21_decimal b = {{723, 2323, 9, 983040}};  // 166020.706640594993875

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_9) {
  s21_decimal a = {{8923, 90, 0, -2147155968}};  // -3865470.65563
  s21_decimal b = {{8923, 90, 2, -2147352576}};  // -368934885339661687.95

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_10) {
  s21_decimal a = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568
  s21_decimal b = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_11) {
  s21_decimal a = {{-234234, 932, 19231, 655360}};  // 35474933528551.5591380230
  s21_decimal b = {
      {-234823, -2387423, 237472, 655360}};  // 438060364516212.8938920633

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_12) {
  s21_decimal a = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776
  s21_decimal b = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_13) {
  s21_decimal a = {
      {823, 2387482, -23842, 1310720}};  // 792277227.07002386367524111159
  s21_decimal b = {
      {8234, 23891, -1347324, -2147221504}};  // -7920330877325207355668615.1722

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_14) {
  s21_decimal a = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441
  s21_decimal b = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_15) {
  s21_decimal a = {{28994, 2378193, -13843,
                    -2147221504}};  // -7922790715599633949337953.5170
  s21_decimal b = {
      {200023, 878323, 134234234, 0}};  // 2476184560532213568217746775

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_16) {
  s21_decimal a = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010
  s21_decimal b = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_17) {
  s21_decimal a = {
      {289293, 237823, -12391, 655360}};  // 7922793394065954170.0497402381
  s21_decimal b = {
      {82342, -234, 2838, -2147221504}};  // -5237030642425639477.2902

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_18) {
  s21_decimal a = {{237423, 23942, 0, 0}};  // 102830107238255
  s21_decimal b = {{237423, 23942, 0, 0}};  // 102830107238255

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_19) {
  s21_decimal a = {{2, 392, 0, 0}};          // 1683627180034
  s21_decimal b = {{823, 239923, 9923, 0}};  // 183047042473881319244599

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_20) {
  s21_decimal a = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726
  s21_decimal b = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726

  int res = s21_is_less_or_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_test_1) {
  s21_decimal a = {
      {7823482, 278348234, 23742342, 131072}};  // 4379689077799819450709034.18
  s21_decimal b = {
      {7238423, 2378423, 2734234, 262144}};  // 5043771484585041116151.4775

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_2) {
  s21_decimal a = {{72342, 0, 0, -2147352576}};  // -723.42
  s21_decimal b = {{72342, 0, 0, -2147352576}};  // -723.42

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_3) {
  s21_decimal a = {{8234, 238423, 23482, 65536}};  // 43316644536286667866935.4
  s21_decimal b = {{234, 2342, 0, -2147155968}};   // -100588134.07466

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_4) {
  s21_decimal a = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410
  s21_decimal b = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_7) {
  s21_decimal a = {{28342, 293942, 9123, 262144}};  // 16828964744692351634.1942
  s21_decimal b = {{823, 2234, 234234, 262144}};  // 432085465137087807016.2231

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_test_8) {
  s21_decimal a = {{723, 2323, 9, 983040}};  // 166020.706640594993875
  s21_decimal b = {{723, 2323, 9, 983040}};  // 166020.706640594993875

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_9) {
  s21_decimal a = {{8923, 90, 0, -2147155968}};  // -3865470.65563
  s21_decimal b = {{8923, 90, 2, -2147352576}};  // -368934885339661687.95

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_10) {
  s21_decimal a = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568
  s21_decimal b = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_11) {
  s21_decimal a = {{-234234, 932, 19231, 655360}};  // 35474933528551.5591380230
  s21_decimal b = {
      {-234823, -2387423, 237472, 655360}};  // 438060364516212.8938920633

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_test_12) {
  s21_decimal a = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776
  s21_decimal b = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_13) {
  s21_decimal a = {
      {823, 2387482, -23842, 1310720}};  // 792277227.07002386367524111159
  s21_decimal b = {
      {8234, 23891, -1347324, -2147221504}};  // -7920330877325207355668615.1722

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_14) {
  s21_decimal a = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441
  s21_decimal b = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_15) {
  s21_decimal a = {{28994, 2378193, -13843,
                    -2147221504}};  // -7922790715599633949337953.5170
  s21_decimal b = {
      {200023, 878323, 134234234, 0}};  // 2476184560532213568217746775

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_test_16) {
  s21_decimal a = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010
  s21_decimal b = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_17) {
  s21_decimal a = {
      {289293, 237823, -12391, 655360}};  // 7922793394065954170.0497402381
  s21_decimal b = {
      {82342, -234, 2838, -2147221504}};  // -5237030642425639477.2902

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_18) {
  s21_decimal a = {{237423, 23942, 0, 0}};  // 102830107238255
  s21_decimal b = {{237423, 23942, 0, 0}};  // 102830107238255

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_less_test_19) {
  s21_decimal a = {{2, 392, 0, 0}};          // 1683627180034
  s21_decimal b = {{823, 239923, 9923, 0}};  // 183047042473881319244599

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_less_test_20) {
  s21_decimal a = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726
  s21_decimal b = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726

  int res = s21_is_less(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_1) {
  s21_decimal a = {
      {7823482, 278348234, 23742342, 131072}};  // 4379689077799819450709034.18
  s21_decimal b = {
      {7238423, 2378423, 2734234, 262144}};  // 5043771484585041116151.4775

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_2) {
  s21_decimal a = {{72342, 0, 0, -2147352576}};  // -723.42
  s21_decimal b = {{72342, 0, 0, -2147352576}};  // -723.42

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_3) {
  s21_decimal a = {{8234, 238423, 23482, 65536}};  // 43316644536286667866935.4
  s21_decimal b = {{234, 2342, 0, -2147155968}};   // -100588134.07466

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_4) {
  s21_decimal a = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410
  s21_decimal b = {
      {7234, 238423, -234723, -2147483648}};  // -79223832639156148285447609410

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_5) {
  s21_decimal a = {{2124678, 0, 0, -2147287040}};  // -2124.678
  s21_decimal b = {{2124678, 0, 0, -2147155968}};  // -21.24678

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_6) {
  s21_decimal a = {{7283842, 0, 0, 720896}};  // 0.00007283842
  s21_decimal b = {{7283842, 0, 0, 720896}};  // 0.00007283842

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_7) {
  s21_decimal a = {{28342, 293942, 9123, 262144}};  // 16828964744692351634.1942
  s21_decimal b = {{823, 2234, 234234, 262144}};  // 432085465137087807016.2231

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_8) {
  s21_decimal a = {{723, 2323, 9, 983040}};  // 166020.706640594993875
  s21_decimal b = {{723, 2323, 9, 983040}};  // 166020.706640594993875

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_9) {
  s21_decimal a = {{8923, 90, 0, -2147155968}};  // -3865470.65563
  s21_decimal b = {{8923, 90, 2, -2147352576}};  // -368934885339661687.95

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_10) {
  s21_decimal a = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568
  s21_decimal b = {{0, 0, 23423, 720896}};  // 4320780864384.98827501568

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_11) {
  s21_decimal a = {{-234234, 932, 19231, 655360}};  // 35474933528551.5591380230
  s21_decimal b = {
      {-234823, -2387423, 237472, 655360}};  // 438060364516212.8938920633

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_12) {
  s21_decimal a = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776
  s21_decimal b = {
      {0, 83423, 23423, -2147287040}};  // -432078086796797884235.776

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_13) {
  s21_decimal a = {
      {823, 2387482, -23842, 1310720}};  // 792277227.07002386367524111159
  s21_decimal b = {
      {8234, 23891, -1347324, -2147221504}};  // -7920330877325207355668615.1722

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_14) {
  s21_decimal a = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441
  s21_decimal b = {
      {-7238423, 0, 923423, -2147024896}};  // -1703414775277709956.9630441

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_15) {
  s21_decimal a = {{28994, 2378193, -13843,
                    -2147221504}};  // -7922790715599633949337953.5170
  s21_decimal b = {
      {200023, 878323, 134234234, 0}};  // 2476184560532213568217746775

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_16) {
  s21_decimal a = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010
  s21_decimal b = {
      {7234, 234923, 23423, -2147483648}};  // -432078087447485429587010

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_17) {
  s21_decimal a = {
      {289293, 237823, -12391, 655360}};  // 7922793394065954170.0497402381
  s21_decimal b = {
      {82342, -234, 2838, -2147221504}};  // -5237030642425639477.2902

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_18) {
  s21_decimal a = {{237423, 23942, 0, 0}};  // 102830107238255
  s21_decimal b = {{237423, 23942, 0, 0}};  // 102830107238255

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_19) {
  s21_decimal a = {{2, 392, 0, 0}};          // 1683627180034
  s21_decimal b = {{823, 239923, 9923, 0}};  // 183047042473881319244599

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_20) {
  s21_decimal a = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726
  s21_decimal b = {
      {2734, -23874283, 2384234, -2147221504}};  // -4398137275404162809672.7726

  int res = s21_is_not_equal(a, b);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_sub1) {
  s21_decimal a;
  a.bits[0] = 1238;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 238;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1000);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub2) {
  s21_decimal a;
  a.bits[0] = 2147483647;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 2147483647;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub3) {
  s21_decimal a;
  a.bits[0] = 2147483647;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 5;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2147483652);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub4) {
  s21_decimal a;
  a.bits[0] = 2147483647;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal b;
  b.bits[0] = 5;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 2147483642);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_sub5) {
  s21_decimal a;
  a.bits[0] = 0b00111111110001101111001111100110;
  a.bits[1] = 0b00000000000001010100000010111110;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 0b11111111111111101101010011101000;
  b.bits[1] = 0b00000000000000001100001101001111;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1070079742);
  ck_assert_uint_eq(res.bits[1], 294254);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub6) {
  s21_decimal a;
  a.bits[0] = 0b00111111110001101111001111100110;
  a.bits[1] = 0b00000000000001010100000010111110;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 0b11111111111111101101010011101000;
  b.bits[1] = 0b00000000000000001100001101001111;
  b.bits[2] = 0;
  b.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1069926606);
  ck_assert_uint_eq(res.bits[1], 394254);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub7) {
  s21_decimal a;
  a.bits[0] = 0b00111111110001101111001111100110;
  a.bits[1] = 0b00000000000001010100000010111110;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 0;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1070003174);
  ck_assert_uint_eq(res.bits[1], 344254);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub8) {
  s21_decimal a;
  a.bits[0] = 0b00111111110001101111001111100110;
  a.bits[1] = 0b00000000000001010100000010111110;
  a.bits[2] = 0;
  a.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal b;
  b.bits[0] = 0b11111111111111101101010011101000;
  b.bits[1] = 0b00000000000000001100001101001111;
  b.bits[2] = 0;
  b.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 1070079742);
  ck_assert_uint_eq(res.bits[1], 294254);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(test_sub9) {
  s21_decimal a;
  a.bits[0] = 0b00000000000000011110101010101001;
  a.bits[1] = 0b00111101011100001010000000000000;
  a.bits[2] = 0b00000000000000000000000000001010;
  a.bits[3] = 0;
  s21_decimal b;
  b.bits[0] = 0b11111111111111101101010011101000;
  b.bits[1] = 0b00000000000000001100001101001111;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_decimal res;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(res.bits[0], 202177);
  ck_assert_uint_eq(res.bits[1], 1030741168);
  ck_assert_uint_eq(res.bits[2], 10);
  ck_assert_uint_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_sub10) {
  s21_decimal a = {.bits = {999999999, 0, 0, 0}};
  s21_decimal b = {.bits = {999999999, 0, 0, 0}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

START_TEST(test_sub11) {
  s21_decimal a = {.bits = {292342, 0, 0, -2147155968}};
  s21_decimal b = {.bits = {781413, 0, 0, -2147483648}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)831596330);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)18);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)327680);
}
END_TEST

START_TEST(test_sub12) {
  s21_decimal a = {.bits = {7938402, 0, 0, 0}};
  s21_decimal b = {.bits = {1830490002, 0, 0, -2147155968}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1101740242);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)185);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)327680);
}
END_TEST

START_TEST(test_sub13) {
  s21_decimal a = {.bits = {2024072662, 184830, 0, 589824}};
  s21_decimal b = {.bits = {1265466682, 55512, 0, 524288}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)2040659566);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)370292);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2146893824);
}
END_TEST

START_TEST(test_sub14) {
  s21_decimal a = {{809805404, 16957601, 0, -2147483648}};
  s21_decimal b = {.bits = {-1998155945, 28268, 0, 196608}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)353396407);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)-222239727);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)3);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147287040);
}
END_TEST

START_TEST(test_sub15) {
  s21_decimal a = {{809805404, 16957601, 0, -2147483648}};
  s21_decimal b = {.bits = {652204261, 150968, 0, -2147221504}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1388482779);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)2072136373);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)39);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147221504);
}
END_TEST

START_TEST(test_sub16) {
  s21_decimal a = {.bits = {-1318475665, 151177, 0, 0}};
  s21_decimal b = {.bits = {652206196, 150968, 0, -2147221504}};
  s21_decimal res_bits = {.bits = {0, 0, 0, 0}};

  int res = s21_sub(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1445154916);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)1511927898);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)262144);
}
END_TEST

START_TEST(div_test_1) {
  int num1 = 100;
  int num2 = 50;
  int res_origin = 2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_2) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -16384;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_3) {
  int num1 = 2;
  int num2 = 2;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_4) {
  int num1 = 0;
  int num2 = 5;
  int res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_5) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_6) {
  float num1 = -9403.0e2;
  float num2 = -2020.29;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_7) {
  float num1 = -9403.0e2;
  float num2 = 2020.29;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_8) {
  float num1 = -9403.0e2;
  float num2 = 2.28e17;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_9) {
  float num1 = -0.9;
  float num2 = 30.323;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(s21_div_11) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  float tmp2 = 999.99;
  float res_s21 = 0.0;
  float res = 0.100001;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_float_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_12) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  float res_s21 = 0;
  float res = 0.00100001;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_13) {
  s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
  s21_decimal dec2 = {{2.00e2, 0, 0, 0}};

  int res_s21 = 0;
  int res = 50;

  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_null_14) {
  s21_decimal dec1 = {{1110, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};

  s21_decimal res1;
  int res = s21_div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(div_test_15) {
  float num1 = -0.9e3;
  float num2 = 30.32;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_16) {
  float num1 = -0.9;
  float num2 = 0.000076;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

///
///
///

START_TEST(test_comp1) {  // 1337 < 1338 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, s21_is_less(num1, num2));
}
END_TEST

START_TEST(test_comp2) {  // -1337 < 1338 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(-1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, s21_is_less(num1, num2));
}
END_TEST

START_TEST(test_comp3) {  // 1337 < -1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, s21_is_less(num1, num2));
}
END_TEST

START_TEST(test_comp4) {  // -1337 < -1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(-1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, s21_is_less(num1, num2));
}
END_TEST

// === is_greater === //
START_TEST(test_comp5) {  // 1337 > 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, s21_is_greater(num1, num2));
}
END_TEST

START_TEST(test_comp6) {  // -1337 > 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(-1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, s21_is_greater(num1, num2));
}
END_TEST

START_TEST(test_comp7) {  // 1337 > -1338 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(1, s21_is_greater(num1, num2));
}
END_TEST

START_TEST(test_comp8) {  // -1337 > -1338 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(-1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(1, s21_is_greater(num1, num2));
}
END_TEST

// === is_less_or_equal === //
START_TEST(test_comp9) {  // 1337 <= 1338 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, s21_is_less_or_equal(num1, num2));
}
END_TEST

START_TEST(test_comp10) {  // 1338 <= 1337 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1338, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(0, s21_is_less_or_equal(num1, num2));
}
END_TEST

START_TEST(test_comp11) {  // 1337 <= 1337 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, s21_is_less_or_equal(num1, num2));
}
END_TEST

// === is_greater_or_equal === //
START_TEST(test_comp12) {  // 1337 >= 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, s21_is_greater_or_equal(num1, num2));
}
END_TEST

START_TEST(test_comp13) {  // 1338 >= 1337 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1338, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, s21_is_greater_or_equal(num1, num2));
}
END_TEST

START_TEST(test_comp14) {  // 1337 >= 1337 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, s21_is_greater_or_equal(num1, num2));
}
END_TEST

// === is_equal === //
START_TEST(test_comp15) {  // 1337 = 1337 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(1, s21_is_equal(num1, num2));
}
END_TEST

START_TEST(test_comp16) {  // 1337 = 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, s21_is_equal(num1, num2));
}
END_TEST

START_TEST(test_comp17) {  // 1337 = 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(-1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(0, s21_is_equal(num1, num2));
}
END_TEST

START_TEST(test_comp18) {  // 1337 = 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, s21_is_equal(num1, num2));
}
END_TEST

START_TEST(test_comp19) {  // 1337 = 1338 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(-1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(-1338, &num2);
  ck_assert_int_eq(0, s21_is_equal(num1, num2));
}
END_TEST

// === is_not_equal === //
START_TEST(test_comp20) {  // 1337 != 1338 == 1 yes
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1338, &num2);
  ck_assert_int_eq(1, s21_is_not_equal(num1, num2));
}
END_TEST

START_TEST(test_comp21) {  // 1337 != 1337 == 0 no
  s21_decimal num1 = {0};
  s21_from_int_to_decimal(1337, &num1);
  s21_decimal num2 = {0};
  s21_from_int_to_decimal(1337, &num2);
  ck_assert_int_eq(0, s21_is_not_equal(num1, num2));
}
END_TEST

START_TEST(dec_to_float_1) {
  s21_decimal number;
  number.bits[0] = 11;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000010000000000000000;
  int result_error = 0;
  float my_float;
  float res = 1.1;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_2) {
  s21_decimal number;
  number.bits[0] = 7;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_error = 0;
  float my_float;
  float res = -0.7;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_3) {
  s21_decimal number;
  number.bits[0] = 0;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float my_float;
  float res = 0;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_4) {
  s21_decimal number;
  number.bits[0] = 1;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float my_float;
  float res = 1;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_5) {
  s21_decimal number;
  number.bits[0] = 175;
  number.bits[0] = 0b00000000000000000000000010101111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000100000000000000000;
  int result_error = 0;
  float my_float;
  float res = -1.75;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_6) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000001100101111001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  float my_float;
  float res = 6521;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_7) {
  s21_decimal number;
  number.bits[0] = 0b00000000000001011001000011001100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  float my_float;
  float res = -364748;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_8) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000000011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000110000000000000000;
  int result_error = 0;
  float my_float;
  float res = 0.003;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_9) {
  s21_decimal number;
  number.bits[0] = 0b01001100110100101000000111000101;
  number.bits[1] = 0b00000000000000000000000000000010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  float my_float;
  float res = -9878798789;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_10) {
  s21_decimal number;
  number.bits[0] = 0b10010001000010101111010011001010;
  number.bits[1] = 0b11000000010001011101010111110010;
  number.bits[2] = 0b00100111111001000001101100000000;
  number.bits[3] = 0b00000000000110010000000000000000;
  int result_error = 0;
  float my_float;
  float res = 1234.5677987654345678987654346;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_11) {
  s21_decimal number;
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000110100000000000000000;
  int result_error = 0;
  float my_float;
  float res = -792.28162514264337593543950335;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_12) {
  s21_decimal number;
  number.bits[0] = 0b11111110100100001101100101011111;
  number.bits[1] = 0b10000100011001000010000111101000;
  number.bits[2] = 0b00000000000000000000000000000001;
  number.bits[3] = 0b00000000000100110000000000000000;
  int result_error = 0;
  float my_float;
  float res = 2.7986531268974139743f;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_13) {
  s21_decimal number;
  number.bits[0] = 0b00000000000001001111001110101100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000001100000000000000000;
  int result_error = 0;
  float my_float;
  float res = 0.324524;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(res, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal value;
  s21_from_float_to_decimal(0.03, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 131072);

  s21_from_float_to_decimal(127.1234, &value);
  ck_assert_int_eq(value.bits[0], 1271234);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 262144);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal value;
  s21_from_float_to_decimal(22.148368f, &value);
  ck_assert_int_eq(value.bits[0], 2214837);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 327680);

  s21_from_float_to_decimal(-1.02f, &value);
  ck_assert_int_eq(value.bits[0], 102);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 2147614720);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal value;
  s21_from_float_to_decimal(79228162.514264337593543950334f, &value);
  ck_assert_int_eq(value.bits[0], 79228160);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);

  s21_from_float_to_decimal(0, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal value;
  float a = 1.0f / 0.0f;
  int err_check = s21_from_float_to_decimal(a, &value);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  s21_decimal value;
  float a = -1.0f / 0.0f;
  int err_check = s21_from_float_to_decimal(a, &value);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal value;
  float a = S21_NAN;
  int err_check = s21_from_float_to_decimal(a, &value);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
  s21_decimal value;
  float a = 1e-29;
  int err_check = s21_from_float_to_decimal(a, &value);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal value;
  // value = 3.543;
  value.bits[0] = 3543;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 3543;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 2147680256;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value;
  // value = 834.000001;
  value.bits[0] = 834;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 834;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 2147483648;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal value;
  // value = 76.0f;
  value.bits[0] = 76;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 76;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 2147483648;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal value;
  // value = 0.0f;
  value.bits[0] = 0;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 0;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_5) {
  s21_decimal value;
  // value = 2.7986531268974139743f;
  value.bits[0] = 0b11111110100100001101100101011111;
  value.bits[1] = 0b10000100011001000010000111101000;
  value.bits[2] = 0b00000000000000000000000000000001;
  value.bits[3] = 0b00000000000100110000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 0b11111110100100001101100101011111;
  my_result.bits[1] = 0b10000100011001000010000111101000;
  my_result.bits[2] = 0b00000000000000000000000000000001;
  my_result.bits[3] = 2148728832;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_6) {
  s21_decimal value;
  // value = -345.6;
  value.bits[0] = 3456;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 3456;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 65536;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_7) {
  s21_decimal value;
  // value = -3;
  value.bits[0] = 3;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 3;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_8) {
  s21_decimal value;
  // value = 987456543210.0;
  value.bits[0] = 0b00011001111101110000001100100100;
  value.bits[1] = 0b00000000000000000000100011111011;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 0b00011001111101110000001100100100;
  my_result.bits[1] = 0b00000000000000000000100011111011;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 2147549184;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_9) {
  s21_decimal value;
  // value = -9878798789.5867800;
  value.bits[0] = 0b11001110100110111101100110011000;
  value.bits[1] = 0b00000001010111101111011100100110;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 0b11001110100110111101100110011000;
  my_result.bits[1] = 0b00000001010111101111011100100110;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 458752;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_negate_10) {
  s21_decimal value;
  // value = -2.514475768684753643;
  value.bits[0] = 0b10101100110010000011001011101011;
  value.bits[1] = 0b00100010111001010011011001100011;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000100100000000000000000;
  s21_decimal my_result;
  my_result.bits[0] = 0b10101100110010000011001011101011;
  my_result.bits[1] = 0b00100010111001010011011001100011;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 1179648;
  int err_check_my_result = 0;
  s21_decimal result;
  int err_check = s21_negate(value, &result);
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_1) {
  s21_decimal value_1, value_2, my_result, result;
  value_1.bits[0] = 4;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 5;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int err_check = s21_add(value_1, value_2, &result);
  int err_check_my_result = 0;
  my_result.bits[0] = 9;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  value_1.bits[0] = 120;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 14;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 134;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  value_1.bits[0] = 0;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 10;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 10;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 11;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 11;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_5) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 6521;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 74121;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 80642;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_6) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 3;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 7654246;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 7654249;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  // value_1 = -43;
  value_1.bits[0] = 43;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  value_2.bits[0] = 1;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 42;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  // -456;
  value_1.bits[0] = 456;
  value_1.bits[1] = 0b00000000000000000000000000000010;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;
  // -43
  value_2.bits[0] = 43;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 499;
  my_result.bits[1] = 0b00000000000000000000000000000010;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_9) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  // 9999999999999999999;
  value_1.bits[0] = 0b10001001111001111111111111111111;
  value_1.bits[1] = 0b10001010110001110010001100000100;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 1;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0b10001001111010000000000000000000;
  my_result.bits[1] = 0b10001010110001110010001100000100;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  // 18446744073709551615;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 1;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0b00000000000000000000000000000000;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000001;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 0;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_add(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_1) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 5;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 4;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 20;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 45;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 56;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 2520;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 0;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 5;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 10;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_5) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 0;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 5733;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 68999;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 395571267;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 93;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  value_2.bits[0] = 34;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 3162;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 40;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 7;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 280;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;

  value_1.bits[0] = 10;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  value_2.bits[0] = 11;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 110;
  my_result.bits[1] = 0b00000000000000000000000000000000;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

START_TEST(s21_mul_ten) {
  s21_decimal value_1, value_2, my_result, result;
  int err_check, err_check_my_result;
  // 9999999999999999999;
  value_1.bits[0] = 0b10001001111001111111111111111111;
  value_1.bits[1] = 0b10001010110001110010001100000100;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 1;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  err_check = s21_mul(value_1, value_2, &result);
  err_check_my_result = 0;
  my_result.bits[0] = 0b10001001111001111111111111111111;
  my_result.bits[1] = 0b10001010110001110010001100000100;
  my_result.bits[2] = 0b00000000000000000000000000000000;
  my_result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(my_result.bits[3], result.bits[3]);
  ck_assert_int_eq(my_result.bits[2], result.bits[2]);
  ck_assert_int_eq(my_result.bits[1], result.bits[1]);
  ck_assert_int_eq(my_result.bits[0], result.bits[0]);
  ck_assert_int_eq(err_check, err_check_my_result);
}
END_TEST

Suite* my_tests_suite() {
  Suite* suite;
  TCase* tc_core;

  suite = suite_create("Decimal Tests");

  tc_core = tcase_create("TESTS");

  tcase_add_test(tc_core, test_truncate1);
  tcase_add_test(tc_core, test_truncate2);
  tcase_add_test(tc_core, test_truncate3);
  tcase_add_test(tc_core, test_truncate4);
  tcase_add_test(tc_core, test_truncate5);
  tcase_add_test(tc_core, test_truncate6);
  tcase_add_test(tc_core, test_truncate7);
  tcase_add_test(tc_core, test_truncate8);

  tcase_add_test(tc_core, test_floor1);
  tcase_add_test(tc_core, test_floor2);
  tcase_add_test(tc_core, test_floor3);
  tcase_add_test(tc_core, test_floor4);
  tcase_add_test(tc_core, test_floor5);
  tcase_add_test(tc_core, test_floor6);
  tcase_add_test(tc_core, test_floor7);
  tcase_add_test(tc_core, test_floor8);
  tcase_add_test(tc_core, test_floor9);
  tcase_add_test(tc_core, test_floor10);
  tcase_add_test(tc_core, test_floor11);
  tcase_add_test(tc_core, test_floor12);
  tcase_add_test(tc_core, test_floor13);
  tcase_add_test(tc_core, test_floor14);
  tcase_add_test(tc_core, test_floor15);
  tcase_add_test(tc_core, test_floor16);

  tcase_add_test(tc_core, test_round1);
  tcase_add_test(tc_core, test_round2);
  tcase_add_test(tc_core, test_round3);
  tcase_add_test(tc_core, test_round4);
  tcase_add_test(tc_core, test_round5);
  tcase_add_test(tc_core, test_round6);
  tcase_add_test(tc_core, test_round7);

  tcase_add_test(tc_core, s21_is_equal_test_1);
  tcase_add_test(tc_core, s21_is_equal_test_2);
  tcase_add_test(tc_core, s21_is_equal_test_3);
  tcase_add_test(tc_core, s21_is_equal_test_4);
  tcase_add_test(tc_core, s21_is_equal_test_5);
  tcase_add_test(tc_core, s21_is_equal_test_6);
  tcase_add_test(tc_core, s21_is_equal_test_7);
  tcase_add_test(tc_core, s21_is_equal_test_8);
  tcase_add_test(tc_core, s21_is_equal_test_9);
  tcase_add_test(tc_core, s21_is_equal_test_10);
  tcase_add_test(tc_core, s21_is_equal_test_11);
  tcase_add_test(tc_core, s21_is_equal_test_12);
  tcase_add_test(tc_core, s21_is_equal_test_13);
  tcase_add_test(tc_core, s21_is_equal_test_14);
  tcase_add_test(tc_core, s21_is_equal_test_15);
  tcase_add_test(tc_core, s21_is_equal_test_16);
  tcase_add_test(tc_core, s21_is_equal_test_17);
  tcase_add_test(tc_core, s21_is_equal_test_18);
  tcase_add_test(tc_core, s21_is_equal_test_19);
  tcase_add_test(tc_core, s21_is_equal_test_20);

  tcase_add_test(tc_core, s21_is_greater_or_equal_test_1);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_2);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_3);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_4);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_5);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_6);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_7);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_8);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_9);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_10);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_11);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_12);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_13);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_14);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_15);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_16);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_17);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_18);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_19);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_20);

  tcase_add_test(tc_core, s21_is_greater_test_1);
  tcase_add_test(tc_core, s21_is_greater_test_2);
  tcase_add_test(tc_core, s21_is_greater_test_3);
  tcase_add_test(tc_core, s21_is_greater_test_4);
  tcase_add_test(tc_core, s21_is_greater_test_5);
  tcase_add_test(tc_core, s21_is_greater_test_6);
  tcase_add_test(tc_core, s21_is_greater_test_7);
  tcase_add_test(tc_core, s21_is_greater_test_8);
  tcase_add_test(tc_core, s21_is_greater_test_9);
  tcase_add_test(tc_core, s21_is_greater_test_10);
  tcase_add_test(tc_core, s21_is_greater_test_11);
  tcase_add_test(tc_core, s21_is_greater_test_12);
  tcase_add_test(tc_core, s21_is_greater_test_13);
  tcase_add_test(tc_core, s21_is_greater_test_14);
  tcase_add_test(tc_core, s21_is_greater_test_15);
  tcase_add_test(tc_core, s21_is_greater_test_16);
  tcase_add_test(tc_core, s21_is_greater_test_17);
  tcase_add_test(tc_core, s21_is_greater_test_18);
  tcase_add_test(tc_core, s21_is_greater_test_19);
  tcase_add_test(tc_core, s21_is_greater_test_20);

  tcase_add_test(tc_core, s21_is_less_or_equal_test_1);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_2);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_3);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_4);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_6);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_7);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_8);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_9);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_10);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_11);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_12);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_13);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_14);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_15);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_16);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_17);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_18);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_19);
  tcase_add_test(tc_core, s21_is_less_or_equal_test_20);

  tcase_add_test(tc_core, s21_is_less_test_1);
  tcase_add_test(tc_core, s21_is_less_test_2);
  tcase_add_test(tc_core, s21_is_less_test_3);
  tcase_add_test(tc_core, s21_is_less_test_4);
  tcase_add_test(tc_core, s21_is_less_test_7);
  tcase_add_test(tc_core, s21_is_less_test_8);
  tcase_add_test(tc_core, s21_is_less_test_9);
  tcase_add_test(tc_core, s21_is_less_test_10);
  tcase_add_test(tc_core, s21_is_less_test_11);
  tcase_add_test(tc_core, s21_is_less_test_12);
  tcase_add_test(tc_core, s21_is_less_test_13);
  tcase_add_test(tc_core, s21_is_less_test_14);
  tcase_add_test(tc_core, s21_is_less_test_15);
  tcase_add_test(tc_core, s21_is_less_test_16);
  tcase_add_test(tc_core, s21_is_less_test_17);
  tcase_add_test(tc_core, s21_is_less_test_18);
  tcase_add_test(tc_core, s21_is_less_test_19);
  tcase_add_test(tc_core, s21_is_less_test_20);

  tcase_add_test(tc_core, s21_is_not_equal_test_1);
  tcase_add_test(tc_core, s21_is_not_equal_test_2);
  tcase_add_test(tc_core, s21_is_not_equal_test_3);
  tcase_add_test(tc_core, s21_is_not_equal_test_4);
  tcase_add_test(tc_core, s21_is_not_equal_test_5);
  tcase_add_test(tc_core, s21_is_not_equal_test_6);
  tcase_add_test(tc_core, s21_is_not_equal_test_7);
  tcase_add_test(tc_core, s21_is_not_equal_test_8);
  tcase_add_test(tc_core, s21_is_not_equal_test_9);
  tcase_add_test(tc_core, s21_is_not_equal_test_10);
  tcase_add_test(tc_core, s21_is_not_equal_test_11);
  tcase_add_test(tc_core, s21_is_not_equal_test_12);
  tcase_add_test(tc_core, s21_is_not_equal_test_13);
  tcase_add_test(tc_core, s21_is_not_equal_test_14);
  tcase_add_test(tc_core, s21_is_not_equal_test_15);
  tcase_add_test(tc_core, s21_is_not_equal_test_16);
  tcase_add_test(tc_core, s21_is_not_equal_test_17);
  tcase_add_test(tc_core, s21_is_not_equal_test_18);
  tcase_add_test(tc_core, s21_is_not_equal_test_19);
  tcase_add_test(tc_core, s21_is_not_equal_test_20);

  tcase_add_test(tc_core, test_sub1);
  tcase_add_test(tc_core, test_sub2);
  tcase_add_test(tc_core, test_sub3);
  tcase_add_test(tc_core, test_sub4);
  tcase_add_test(tc_core, test_sub5);
  tcase_add_test(tc_core, test_sub6);
  tcase_add_test(tc_core, test_sub7);
  tcase_add_test(tc_core, test_sub8);
  tcase_add_test(tc_core, test_sub9);
  tcase_add_test(tc_core, test_sub10);
  tcase_add_test(tc_core, test_sub11);
  tcase_add_test(tc_core, test_sub12);
  tcase_add_test(tc_core, test_sub13);
  tcase_add_test(tc_core, test_sub14);
  tcase_add_test(tc_core, test_sub15);
  tcase_add_test(tc_core, test_sub16);

  tcase_add_test(tc_core, div_test_1);
  tcase_add_test(tc_core, div_test_2);
  tcase_add_test(tc_core, div_test_3);
  tcase_add_test(tc_core, div_test_4);
  tcase_add_test(tc_core, div_test_5);
  tcase_add_test(tc_core, div_test_6);
  tcase_add_test(tc_core, div_test_7);
  tcase_add_test(tc_core, div_test_8);
  tcase_add_test(tc_core, div_test_9);
  tcase_add_test(tc_core, s21_div_11);
  tcase_add_test(tc_core, s21_div_12);
  tcase_add_test(tc_core, s21_div_13);
  tcase_add_test(tc_core, s21_div_null_14);
  tcase_add_test(tc_core, div_test_15);
  tcase_add_test(tc_core, div_test_16);

  tcase_add_test(tc_core, test_comp1);
  tcase_add_test(tc_core, test_comp2);
  tcase_add_test(tc_core, test_comp3);
  tcase_add_test(tc_core, test_comp4);
  tcase_add_test(tc_core, test_comp5);
  tcase_add_test(tc_core, test_comp6);
  tcase_add_test(tc_core, test_comp7);
  tcase_add_test(tc_core, test_comp8);
  tcase_add_test(tc_core, test_comp9);
  tcase_add_test(tc_core, test_comp10);
  tcase_add_test(tc_core, test_comp11);
  tcase_add_test(tc_core, test_comp12);
  tcase_add_test(tc_core, test_comp13);
  tcase_add_test(tc_core, test_comp14);
  tcase_add_test(tc_core, test_comp15);
  tcase_add_test(tc_core, test_comp16);
  tcase_add_test(tc_core, test_comp17);
  tcase_add_test(tc_core, test_comp18);
  tcase_add_test(tc_core, test_comp19);
  tcase_add_test(tc_core, test_comp20);
  tcase_add_test(tc_core, test_comp21);

  tcase_add_test(tc_core, test_from_int_to_decimal);
  tcase_add_test(tc_core, test_from_decimal_to_int);
  tcase_add_test(tc_core, test_from_decimal_to_int1);

  tcase_add_test(tc_core, dec_to_float_1);
  tcase_add_test(tc_core, dec_to_float_2);
  tcase_add_test(tc_core, dec_to_float_3);
  tcase_add_test(tc_core, dec_to_float_4);
  tcase_add_test(tc_core, dec_to_float_5);
  tcase_add_test(tc_core, dec_to_float_6);
  tcase_add_test(tc_core, dec_to_float_7);
  tcase_add_test(tc_core, dec_to_float_8);
  tcase_add_test(tc_core, dec_to_float_9);
  tcase_add_test(tc_core, dec_to_float_10);
  tcase_add_test(tc_core, dec_to_float_11);
  tcase_add_test(tc_core, dec_to_float_12);
  tcase_add_test(tc_core, dec_to_float_13);

  tcase_add_test(tc_core, s21_from_float_to_decimal_1);
  tcase_add_test(tc_core, s21_from_float_to_decimal_2);
  tcase_add_test(tc_core, s21_from_float_to_decimal_3);
  tcase_add_test(tc_core, s21_from_float_to_decimal_4);
  tcase_add_test(tc_core, s21_from_float_to_decimal_5);
  tcase_add_test(tc_core, s21_from_float_to_decimal_6);
  tcase_add_test(tc_core, s21_from_float_to_decimal_7);

  tcase_add_test(tc_core, s21_negate_1);
  tcase_add_test(tc_core, s21_negate_2);
  tcase_add_test(tc_core, s21_negate_3);
  tcase_add_test(tc_core, s21_negate_4);
  tcase_add_test(tc_core, s21_negate_5);
  tcase_add_test(tc_core, s21_negate_6);
  tcase_add_test(tc_core, s21_negate_7);
  tcase_add_test(tc_core, s21_negate_8);
  tcase_add_test(tc_core, s21_negate_9);
  tcase_add_test(tc_core, s21_negate_10);

  tcase_add_test(tc_core, s21_add_1);
  tcase_add_test(tc_core, s21_add_2);
  tcase_add_test(tc_core, s21_add_3);
  tcase_add_test(tc_core, s21_add_4);
  tcase_add_test(tc_core, s21_add_5);
  tcase_add_test(tc_core, s21_add_6);
  tcase_add_test(tc_core, s21_add_7);
  tcase_add_test(tc_core, s21_add_8);
  tcase_add_test(tc_core, s21_add_9);
  tcase_add_test(tc_core, s21_add_10);
  tcase_add_test(tc_core, s21_add_12);

  tcase_add_test(tc_core, s21_mul_1);
  tcase_add_test(tc_core, s21_mul_2);
  tcase_add_test(tc_core, s21_mul_3);
  tcase_add_test(tc_core, s21_mul_4);
  tcase_add_test(tc_core, s21_mul_5);
  tcase_add_test(tc_core, s21_mul_6);
  tcase_add_test(tc_core, s21_mul_7);
  tcase_add_test(tc_core, s21_mul_8);
  tcase_add_test(tc_core, s21_mul_9);
  tcase_add_test(tc_core, s21_mul_ten);
  suite_add_tcase(suite, tc_core);

  return suite;
}
int main() {
  int number_failed = 0;
  Suite* suite;
  SRunner* srunner;

  suite = my_tests_suite();
  srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_NORMAL);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
