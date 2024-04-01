#include "test.h"

START_TEST(s21_div_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_div_2) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

// START_TEST(s21_div_3) {
//   // -45722432124
//   s21_decimal dec_1 = {{0xa544f27c, 0xa, 0x0, 0x80000000}};
//   // 39184.131290807198
//   s21_decimal dec_2 = {{0x826bbb9e, 0x8b35c2, 0x0, 0xc0000}};
//   // -1166860.9362465749380655374280
//   s21_decimal dec_check = {{0x765a5fc8, 0x893a907, 0x25b40c25, 0x80160000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_4) {
//   // 89901421002301944958145051
//   s21_decimal dec_1 = {{0x1d19d21b, 0xcc4a7b13, 0x4a5d5d, 0x0}};
//   // -57887076872868519129510
//   s21_decimal dec_2 = {{0x20eb1a6, 0x1091d4ff, 0xc42, 0x80000000}};
//   // -1553.0482079746963817369624505
//   s21_decimal dec_check = {{0x1d7edfb9, 0x87cb1729, 0x322e8380, 0x80190000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_5) {
//   // 6485071667708572980
//   s21_decimal dec_1 = {{0x88b83534, 0x59ff9a52, 0x0, 0x0}};
//   // -8883930.4921355529043279843
//   s21_decimal dec_2 = {{0x99977fe3, 0x5eb13a7b, 0x497c74, 0x80130000}};
//   // -729977758543.86123834325780243
//   s21_decimal dec_check = {{0x8344c713, 0x6592817f, 0xebde584e, 0x80110000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_6) {
//   // -208466
//   s21_decimal dec_1 = {{0x32e52, 0x0, 0x0, 0x80000000}};
//   // -7544.16300934
//   s21_decimal dec_2 = {{0xa6b73386, 0xaf, 0x0, 0x80080000}};
//   // 27.632753924048311038532541635
//   s21_decimal dec_check = {{0x24065cc3, 0xcf7ea728, 0x5949473f, 0x1b0000}};
//   s21_decimal result;
//   int return_value = s21_div(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_7) {
  // Деление на 0
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 3);
}
END_TEST

START_TEST(s21_div_8) {
  // Деление на -0
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 3);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\033[45m-=S21_DIV=-\033[0m");
  TCase *tc = tcase_create("div");

  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  // tcase_add_test(tc, s21_div_3);
  // tcase_add_test(tc, s21_div_4);
  // tcase_add_test(tc, s21_div_5);
  // tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);

  suite_add_tcase(s, tc);
  return s;
}