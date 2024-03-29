#include "test.h"

START_TEST(s21_strncat_test1) {
  char s21_str1[9] = "abcde";
  char s21_str2[] = "ABC";
  char str1[9] = "abcde";
  char str2[] = "ABC";
  ck_assert_str_eq(s21_strncat(s21_str1, s21_str2, 3), strncat(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncat_test2) {
  char s21_str1[10] = "12345";
  char s21_str2[] = "ABC";
  char str1[10] = "12345";
  char str2[] = "ABC";
  ck_assert_str_eq(s21_strncat(s21_str1, s21_str2, 3), strncat(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncat_test3) {
  char s21_str1[10] = "abcde";
  char s21_str2[] = "123";
  char str1[10] = "abcde";
  char str2[] = "123";
  ck_assert_str_eq(s21_strncat(s21_str1, s21_str2, 3), strncat(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncat_test4) {
  char s21_str1[8] = "abcde";
  char s21_str2[] = "ABC";
  char str1[8] = "abcde";
  char str2[] = "ABC";
  ck_assert_str_eq(s21_strncat(s21_str1, s21_str2, 1), strncat(str1, str2, 1));
}
END_TEST

START_TEST(s21_strncat_test5) {
  char s21_str1[100] = "abcde";
  char s21_str2[] = "ABC";
  char str1[100] = "abcde";
  char str2[] = "ABC";
  int n = 2;
  ck_assert_str_eq(s21_strncat(s21_str1, s21_str2, n), strncat(str1, str2, n));
}
END_TEST

Suite *make_strncat_suite(void) {
  Suite *s = suite_create("strncat");
  TCase *tc_strncat = tcase_create("strncat_test");
  suite_add_tcase(s, tc_strncat);
  tcase_add_test(tc_strncat, s21_strncat_test1);
  tcase_add_test(tc_strncat, s21_strncat_test2);
  tcase_add_test(tc_strncat, s21_strncat_test3);
  tcase_add_test(tc_strncat, s21_strncat_test4);
  tcase_add_test(tc_strncat, s21_strncat_test5);
  return s;
}
