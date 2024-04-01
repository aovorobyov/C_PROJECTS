#include "test.h"

// START_TEST(s21_truncate_1) {
//   s21_decimal src1, origin, result;
//   // src1 = 457.000001;
//   src1.bits[0] = 0b00011011001111010100010001000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000001100000000000000000;
//   // origin = 457;
//   origin.bits[0] = 0b00000000000000000000000111001001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal src1, origin, result;
  // src1 = -3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // origin = -3;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_truncate(src1, &result);
  int check_origin = 0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// START_TEST(s21_truncate_3) {
//   s21_decimal src1, origin, result;
//   // src1 = 2.22221200000001000;
//   src1.bits[0] = 0b00000111100011111010001111101000;
//   src1.bits[1] = 0b00000011000101010111110100000001;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000100010000000000000000;
//   // origin = 2;
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_truncate_4) {
//   s21_decimal src1, origin, result;
//   // src1 = -9878798789.5867800;
//   src1.bits[0] = 0b11001110100110111101100110011000;
//   src1.bits[1] = 0b00000001010111101111011100100110;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000001110000000000000000;
//   // origin = -9878798789;
//   origin.bits[0] = 0b01001100110100101000000111000101;
//   origin.bits[1] = 0b00000000000000000000000000000010;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_truncate_5) {
//   s21_decimal src1, origin, result;
//   // src1 = 18446744073709551615.0;
//   src1.bits[0] = 0b11111111111111111111111111110110;
//   src1.bits[1] = 0b11111111111111111111111111111111;
//   src1.bits[2] = 0b00000000000000000000000000001001;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   // origin = 18446744073709551615;
//   origin.bits[0] = 0b11111111111111111111111111111111;
//   origin.bits[1] = 0b11111111111111111111111111111111;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_truncate_6) {
//   s21_decimal src1, origin, result;
//   // src1 = -545454512454545.35265454545645;
//   src1.bits[0] = 0b10000010111000100101101011101101;
//   src1.bits[1] = 0b11111001111010000010010110101101;
//   src1.bits[2] = 0b10110000001111101111000010010100;
//   src1.bits[3] = 0b10000000000011100000000000000000;
//   // origin = -545454512454545;
//   origin.bits[0] = 0b10000110011101001011101110010001;
//   origin.bits[1] = 0b00000000000000011111000000010110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_truncate_7) {
//   s21_decimal src1, origin, result;
//   // src1 = 0.0;
//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   // origin = 0;
//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

// START_TEST(s21_truncate_8) {
//   s21_decimal src1, origin, result;
//   // src1 = 0.5456465465486476846545465485;
//   src1.bits[0] = 0b00001011000011110111000010001101;
//   src1.bits[1] = 0b10010110101100000101100101010001;
//   src1.bits[2] = 0b00010001101000010111101110000001;
//   src1.bits[3] = 0b00000000000111000000000000000000;
//   // origin = 0;
//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   int check = s21_truncate(src1, &result);
//   int check_origin = 0;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
//   ck_assert_int_eq(check, check_origin);
// }
// END_TEST

Suite *test_truncate(void) {
  Suite *s = suite_create("\033[45m-=S21_TRUNCATE=-\033[0m");
  TCase *tc = tcase_create("truncate_tc");

  // tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  // tcase_add_test(tc, s21_truncate_3);
  // tcase_add_test(tc, s21_truncate_4);
  // tcase_add_test(tc, s21_truncate_5);
  // tcase_add_test(tc, s21_truncate_6);
  // tcase_add_test(tc, s21_truncate_7);
  // tcase_add_test(tc, s21_truncate_8);
  suite_add_tcase(s, tc);
  return s;
}