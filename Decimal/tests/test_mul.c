#include "test.h"

START_TEST(s21_mul_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_mul(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_mul_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_mul_3) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_mul_4) {
  // -2332
  s21_decimal dec_1 = {{0x91c, 0x0, 0x0, 0x80000000}};
  // -319.85
  s21_decimal dec_2 = {{0x7cf1, 0x0, 0x0, 0x80020000}};
  // 745890.20
  s21_decimal dec_check = {{0x472235c, 0x0, 0x0, 0x20000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = 0;
  return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_mul_5) {
//   // -81241800.198486010
//   s21_decimal dec_1 = {{0xa1be77fa, 0x120a0fc, 0x0, 0x80090000}};
//   // 86907244901488
//   s21_decimal dec_2 = {{0xab75f470, 0x4f0a, 0x0, 0x0}};
//   // -7060501026087580078989.1961829
//   s21_decimal dec_check = {{0x405453e5, 0xa8ff2e9b, 0xe423187b, 0x80070000}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int return_value = 0;
//   return_value = s21_mul(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

START_TEST(s21_mul_6) {
  // 191
  s21_decimal dec_1 = {{0xbf, 0x0, 0x0, 0x0}};
  // 49583.21310855542
  s21_decimal dec_2 = {{0x246a7176, 0x119d91, 0x0, 0xb0000}};
  // 9470393.70373408522
  s21_decimal dec_check = {{0x2b6aa70a, 0xd248f4a, 0x0, 0xb0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = 0;
  return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_mul_7) {
//   // 9070591255449290420862
//   s21_decimal dec_1 = {{0x6b70327e, 0xb7bda0c7, 0x1eb, 0x0}};
//   // 82.548641824596
//   s21_decimal dec_2 = {{0xda78ff54, 0x4b13, 0x0, 0xc0000}};
//   // 748764988683396035534939.23242
//   s21_decimal dec_check = {{0x90c735aa, 0xee0566e, 0xf1f06361, 0x50000}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int return_value = 0;
//   return_value = s21_mul(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
//   ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
//   ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
//   ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
// }
// END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("S21_MUL");
  TCase *tc = tcase_create("mul");

  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  // tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  // tcase_add_test(tc, s21_mul_7);

  suite_add_tcase(s, tc);
  return s;
}