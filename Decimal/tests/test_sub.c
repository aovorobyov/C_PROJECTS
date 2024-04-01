#include "test.h"

START_TEST(s21_sub_1) {
  // -0.8405
  s21_decimal dec_1 = {{0x20d5, 0x0, 0x0, 0x80040000}};
  // -80011741074826132669.625083
  s21_decimal dec_2 = {{0x70472fb, 0x2cc52dbf, 0x422f25, 0x80060000}};
  // 80011741074826132668.784583
  s21_decimal dec_check = {{0x6f79fc7, 0x2cc52dbf, 0x422f25, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_2) {
  // -9768
  s21_decimal dec_1 = {{0x2628, 0x0, 0x0, 0x80000000}};
  // -78
  s21_decimal dec_2 = {{0x4e, 0x0, 0x0, 0x80000000}};
  // -9690
  s21_decimal dec_check = {{0x25da, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_3) {
  // -33576987.823190
  s21_decimal dec_1 = {{0xc06e8c56, 0x1e89, 0x0, 0x80060000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -33576991.823190
  s21_decimal dec_check = {{0xc0ab9556, 0x1e89, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

// START_TEST(s21_sub_4) {
//   // 79228162514264337592111699780
//   s21_decimal dec_1 = {{0xaaa19744, 0xffffffff, 0xffffffff, 0x0}};
//   // -37233066488655.67990963971034
//   s21_decimal dec_2 = {{0xb1bb23da, 0xe0618e98, 0xc07d8d9, 0x800e0000}};
//   s21_decimal result;
//   // overflow
//   int check = 1;  // Результат слишком велик или положительная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

// START_TEST(s21_sub_5) {
//   // -718134322084321757.01
//   s21_decimal dec_1 = {{0x15321a55, 0xe49c901c, 0x3, 0x80020000}};
//   // 79228162514264337593194945147
//   s21_decimal dec_2 = {{0xeb329a7b, 0xffffffff, 0xffffffff, 0x0}};
//   s21_decimal result;
//   // overflow
//   int check = 2;  // Результат слишком мал или отрицательная бесконечность.
//   int return_value = s21_sub(dec_1, dec_2, &result);
//   ck_assert_int_eq(return_value, check);
// }
// END_TEST

START_TEST(s21_sub_6) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_sub(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_sub_7) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

Suite *test_sub(void) {
  Suite *s = suite_create("S21_SUB");
  TCase *tc = tcase_create("sub");

  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  // tcase_add_test(tc, s21_sub_4);
  // tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);

  suite_add_tcase(s, tc);
  return s;
}