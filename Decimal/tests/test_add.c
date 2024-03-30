#include "test.h"

START_TEST(s21_add_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_add(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_add_2) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_add_3) {
  // Ноль с разными порядками при сложении
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x00050000}};
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x80030000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x00050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_4) {
  // 19.1
  s21_decimal dec_1 = {{0xbf, 0x0, 0x0, 0x10000}};
  // -6837557637910909182927056
  s21_decimal dec_2 = {{0x6fe5e0d0, 0xbe05cafd, 0x5a7e8, 0x80000000}};
  // -6837557637910909182927036.9
  s21_decimal dec_check = {{0x5efac761, 0x6c39ede6, 0x388f17, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_5) {
  // -4468043493801015852785324252
  s21_decimal dec_1 = {{0x492dd0dc, 0x230e7340, 0xe6fe103, 0x80000000}};
  // 909357367.4179
  s21_decimal dec_2 = {{0x433a84c3, 0x845, 0x0, 0x40000}};
  // -4468043493801015851875966884.6
  s21_decimal dec_check = {{0xbdc53c6e, 0x5e908080, 0x905eca1f, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_6) {
  // 98452
  s21_decimal dec_1 = {{0x18094, 0x0, 0x0, 0x0}};
  // 54172435
  s21_decimal dec_2 = {{0x33a9b13, 0x0, 0x0, 0x0}};
  // 54270887
  s21_decimal dec_check = {{0x33c1ba7, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_7) {
  // -163624672743
  s21_decimal dec_1 = {{0x18ca5de7, 0x26, 0x0, 0x80000000}};
  // 295359.2
  s21_decimal dec_2 = {{0x2d1178, 0x0, 0x0, 0x10000}};
  // -163624377383.8
  s21_decimal dec_check = {{0xf7ba998e, 0x17c, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *test_add(void) {
  Suite *s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  TCase *tc = tcase_create("add");

  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);

  suite_add_tcase(s, tc);
  return s;
}