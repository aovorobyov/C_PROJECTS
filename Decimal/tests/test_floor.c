#include "test.h"

// START_TEST(s21_floor_1) {
//   s21_decimal src, origin, result;
//   // src = 5.0;
//   src.bits[0] = 0b00000000000000000000000000110010;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b00000000000000010000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = 5;
//   origin.bits[0] = 0b00000000000000000000000000000101;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(s21_floor_2) {
  s21_decimal src, origin, result;
  // src = 3.4;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal src, origin, result;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(s21_floor_4) {
//   s21_decimal src, origin, result;
//   // src = -2.4363463;
//   src.bits[0] = 0b00000001011100111100000111000111;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000001110000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = -3;
//   origin.bits[0] = 0b00000000000000000000000000000011;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_floor_5) {
//   s21_decimal src, origin, result;
//   // src = 652.34631;
//   src.bits[0] = 0b00000011111000110110011011000111;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b00000000000001010000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = 652;
//   origin.bits[0] = 0b00000000000000000000001010001100;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_floor_6) {
//   s21_decimal src, origin, result;
//   // src = -364748.110;
//   src.bits[0] = 0b00010101101111011001110101001110;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000000110000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = -364749;
//   origin.bits[0] = 0b00000000000001011001000011001101;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_floor_7) {
//   s21_decimal src, origin, result;
//   // src = -545454512454545.35265454545645;
//   src.bits[0] = 0b10000010111000100101101011101101;
//   src.bits[1] = 0b11111001111010000010010110101101;
//   src.bits[2] = 0b10110000001111101111000010010100;
//   src.bits[3] = 0b10000000000011100000000000000000;
//   int check = s21_floor(src, &result);
//   int check_origin = 0;
//   // origin = -545454512454546;
//   origin.bits[0] = 0b10000110011101001011101110010010;
//   origin.bits[1] = 0b00000000000000011111000000010110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(s21_floor_8) {
  s21_decimal src, origin, result;
  // src = -15456451234534;
  src.bits[0] = 0b10111100010010010000101011100110;
  src.bits[1] = 0b00000000000000000000111000001110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_floor(src, &result);
  int check_origin = 0;
  // origin = -15456451234534;
  origin.bits[0] = 0b10111100010010010000101011100110;
  origin.bits[1] = 0b00000000000000000000111000001110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("S21_FLOOR");
  TCase *tc = tcase_create("floor_tc");

  // tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  // tcase_add_test(tc, s21_floor_4);
  // tcase_add_test(tc, s21_floor_5);
  // tcase_add_test(tc, s21_floor_6);
  // tcase_add_test(tc, s21_floor_7);
  tcase_add_test(tc, s21_floor_8);
  suite_add_tcase(s, tc);
  return s;
}