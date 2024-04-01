#include "test.h"

START_TEST(s21_int_to_dec_1) {
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_2) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_3) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_4) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_5) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_int_to_dec_6) {
  s21_decimal *result = NULL;
  int src = 13;
  int my_error = s21_from_int_to_decimal(src, result);
  int result_error = 1;
  ck_assert_int_eq(my_error, result_error);
}
END_TEST

// START_TEST(s21_dec_to_int_1) {
//   s21_decimal src;
//   src.bits[0] = 0b00000000000000000000000000110010;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b00000000000000010000000000000000;
//   int result = 0;
//   int origin = 5;
//   int origin_error = 0;
//   int my_error = s21_from_decimal_to_int(src, &result);
//   ck_assert_int_eq(origin, result);
//   ck_assert_int_eq(origin_error, my_error);
// }
// END_TEST

START_TEST(s21_dec_to_int_2) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

// START_TEST(s21_dec_to_int_3) {
//   s21_decimal src;
//   src.bits[0] = 0b00000001011100111100000111000111;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000001110000000000000000;
//   int result = 0;
//   int origin = -2;
//   int origin_error = 0;
//   int my_error = s21_from_decimal_to_int(src, &result);
//   ck_assert_int_eq(origin, result);
//   ck_assert_int_eq(origin_error, my_error);
// }
// END_TEST

// START_TEST(s21_dec_to_int_4) {
//   s21_decimal src;
//   src.bits[0] = 0b10000111010110110010011111110011;
//   src.bits[1] = 0b00000000000000000000000000000001;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b00000000000000100000000000000000;
//   int result = 0;
//   int origin = 65658654;
//   int origin_error = 0;
//   int my_error = s21_from_decimal_to_int(src, &result);
//   ck_assert_int_eq(origin, result);
//   ck_assert_int_eq(origin_error, my_error);
// }
// END_TEST

// START_TEST(s21_dec_to_int_5) {
//   s21_decimal src;
//   src.bits[0] = 0b00010101101111011001110101001110;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b10000000000000110000000000000000;
//   int result = 0;
//   int origin = -364748;
//   int origin_error = 0;
//   int my_error = s21_from_decimal_to_int(src, &result);
//   ck_assert_int_eq(origin, result);
//   ck_assert_int_eq(origin_error, my_error);
// }
// END_TEST

// START_TEST(s21_dec_to_int_6) {
//   s21_decimal src;
//   src.bits[0] = 0b00111011100110101100100111111001;
//   src.bits[1] = 0b00000000000000000000000000000000;
//   src.bits[2] = 0b00000000000000000000000000000000;
//   src.bits[3] = 0b00000000000000010000000000000000;
//   int result = 0;
//   int origin = 99999999;
//   int origin_error = 0;
//   int my_error = s21_from_decimal_to_int(src, &result);
//   ck_assert_int_eq(origin, result);
//   ck_assert_int_eq(origin_error, my_error);
// }
// END_TEST

START_TEST(s21_dec_to_int_7) {
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int *result = NULL;
  int my_error = s21_from_decimal_to_int(src, result);
  int result_error = 1;
  ck_assert_int_eq(my_error, result_error);
}
END_TEST

START_TEST(s21_dec_to_int_8) {
  s21_decimal src;
  src.bits[0] = 0xffffffff;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0x80000000;
  int result;
  int my_error = s21_from_decimal_to_int(src, &result);
  int result_error = 1;
  ck_assert_int_eq(my_error, result_error);
}
END_TEST

// START_TEST(s21_dec_to_float_1) {
//   s21_decimal number;
//   // decimal: 2.0
//   // float: 2
//   // int: 1073741824
//   number.bits[0] = 0b00000000000000000000000000010100;
//   number.bits[1] = 0b00000000000000000000000000000000;
//   number.bits[2] = 0b00000000000000000000000000000000;
//   number.bits[3] = 0b00000000000000010000000000000000;
//   int result_int = 1073741824;
//   int result_error = 0;
//   float my_float;
//   int my_error = s21_from_decimal_to_float(number, &my_float);
//   int my_int = *(int *)(void *)&my_float;
//   ck_assert_int_eq(result_int, my_int);
//   ck_assert_int_eq(result_error, my_error);
// }
// END_TEST

START_TEST(s21_dec_to_float_2) {
  s21_decimal number;
  // decimal: -0.8
  // float: -0.8
  // int: -1085485875
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -1085485875;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_3) {
  s21_decimal number;
  // decimal: 0
  // float: 0
  // int: 0
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_4) {
  s21_decimal number;
  // decimal: 1
  // float: 1
  // int: 1065353216
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1065353216;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_5) {
  s21_decimal number;
  // decimal: 0.0
  // float: 0
  // int: -2147483648
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// START_TEST(s21_dec_to_float_6) {
//   s21_decimal number;
//   // decimal: -1.75
//   // float: -1.75
//   // int: -1075838976
//   number.bits[0] = 0b00000000000000000000000010101111;
//   number.bits[1] = 0b00000000000000000000000000000000;
//   number.bits[2] = 0b00000000000000000000000000000000;
//   number.bits[3] = 0b10000000000000100000000000000000;
//   int result_int = -1075838976;
//   int result_error = 0;
//   float my_float;
//   int my_error = s21_from_decimal_to_float(number, &my_float);
//   int my_int = *(int *)(void *)&my_float;
//   ck_assert_int_eq(result_int, my_int);
//   ck_assert_int_eq(result_error, my_error);
// }
// END_TEST

// START_TEST(s21_dec_to_float_7) {
//   s21_decimal number;
//   // decimal: 6521
//   // float: 6521
//   // int: 1170982912
//   number.bits[0] = 0b00000000000000000001100101111001;
//   number.bits[1] = 0b00000000000000000000000000000000;
//   number.bits[2] = 0b00000000000000000000000000000000;
//   number.bits[3] = 0b00000000000000000000000000000000;
//   int result_int = 1170982912;
//   int result_error = 0;
//   float my_float;
//   int my_error = s21_from_decimal_to_float(number, &my_float);
//   int my_int = *(int *)(void *)&my_float;
//   ck_assert_int_eq(result_int, my_int);
//   ck_assert_int_eq(result_error, my_error);
// }
// END_TEST

// START_TEST(s21_dec_to_float_8) {
//   s21_decimal number;
//   // decimal: 65658654
//   // float: 6.565866E+07
//   // int: 1283094472
//   number.bits[0] = 0b00000011111010011101111100011110;
//   number.bits[1] = 0b00000000000000000000000000000000;
//   number.bits[2] = 0b00000000000000000000000000000000;
//   number.bits[3] = 0b00000000000000000000000000000000;
//   int result_int = 1283094472;
//   int result_error = 0;
//   float my_float;
//   int my_error = s21_from_decimal_to_float(number, &my_float);
//   int my_int = *(int *)(void *)&my_float;
//   ck_assert_int_eq(result_int, my_int);
//   ck_assert_int_eq(result_error, my_error);
// }
// END_TEST

START_TEST(s21_dec_to_float_9) {
  s21_decimal number = {{0}};
  // decimal: 0.0
  // float: 1E-19
  // int: 535567946
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  s21_setScale(&number, 6);
  float result_float = 1e-6;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_10) {
  s21_decimal number = {{0}};
  // decimal: 0.0000000000000000000000000001
  // float: 1E-28
  // int: 285050806
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  s21_setScale(&number, 5);
  float result_float = 1e-5;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_float_eq(result_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(s21_dec_to_float_11) {
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  float *result = NULL;
  int my_error = s21_from_decimal_to_float(src, result);
  int result_error = 1;
  ck_assert_int_eq(my_error, result_error);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_1) {
//   s21_decimal val;
//   s21_from_float_to_decimal(0.03F, &val);

//   ck_assert_int_eq(val.bits[0], 3);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 131072);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal val;
  s21_from_float_to_decimal(127.1234F, &val);
  ck_assert_int_eq(val.bits[0], 1271234);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_3) {
//   s21_decimal val;
//   s21_from_float_to_decimal(1.02E+09F, &val);
//   ck_assert_int_eq(val.bits[0], 1020000000);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal val;
  float a = 1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  s21_decimal val;
  float a = -1.0F / 0.0F;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal val;
  float a = NAN;
  int err_check = s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
  s21_decimal val;
  s21_from_float_to_decimal(0.0F, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_8) {
//   s21_decimal val;
//   s21_from_float_to_decimal(3.14836E-03F, &val);
//   ck_assert_int_eq(val.bits[0], 314836);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 524288);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_9) {
//   s21_decimal val;
//   s21_from_float_to_decimal(2E+28F, &val);
//   ck_assert_int_eq(val.bits[0], 0x20000000);
//   ck_assert_int_eq(val.bits[1], 0x7c4a04c2);
//   ck_assert_int_eq(val.bits[2], 0x409f9cbc);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_10) {
//   s21_decimal val;
//   s21_from_float_to_decimal(2E-28F, &val);
//   ck_assert_int_eq(val.bits[0], 0x2);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0x1c0000);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_11) {
  s21_decimal val;
  int err_check = s21_from_float_to_decimal(7.922817E+28F, &val);
  ck_assert_int_eq(err_check, 1);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_12) {
  s21_decimal *result = NULL;
  float src = 0.13f;
  int my_error = s21_from_float_to_decimal(src, result);
  int result_error = 1;
  ck_assert_int_eq(my_error, result_error);
}
END_TEST

Suite *test_convert(void) {
  Suite *s = suite_create("21_CONVERT");
  TCase *tc = tcase_create("convert_tc");

  tcase_add_test(tc, s21_int_to_dec_1);
  tcase_add_test(tc, s21_int_to_dec_2);
  tcase_add_test(tc, s21_int_to_dec_3);
  tcase_add_test(tc, s21_int_to_dec_4);
  tcase_add_test(tc, s21_int_to_dec_5);
  tcase_add_test(tc, s21_int_to_dec_6);
  // tcase_add_test(tc, s21_dec_to_int_1);
  tcase_add_test(tc, s21_dec_to_int_2);
  // tcase_add_test(tc, s21_dec_to_int_3);
  // tcase_add_test(tc, s21_dec_to_int_4);
  // tcase_add_test(tc, s21_dec_to_int_5);
  // tcase_add_test(tc, s21_dec_to_int_6);
  tcase_add_test(tc, s21_dec_to_int_7);
  tcase_add_test(tc, s21_dec_to_int_8);
  // tcase_add_test(tc, s21_dec_to_float_1);
  tcase_add_test(tc, s21_dec_to_float_2);
  tcase_add_test(tc, s21_dec_to_float_3);
  tcase_add_test(tc, s21_dec_to_float_4);
  tcase_add_test(tc, s21_dec_to_float_5);
  // tcase_add_test(tc, s21_dec_to_float_6);
  // tcase_add_test(tc, s21_dec_to_float_7);
  // tcase_add_test(tc, s21_dec_to_float_8);
  tcase_add_test(tc, s21_dec_to_float_9);
  tcase_add_test(tc, s21_dec_to_float_10);
  tcase_add_test(tc, s21_dec_to_float_11);
  // tcase_add_test(tc, s21_from_float_to_decimal_1);
  tcase_add_test(tc, s21_from_float_to_decimal_2);
  // tcase_add_test(tc, s21_from_float_to_decimal_3);
  tcase_add_test(tc, s21_from_float_to_decimal_4);
  tcase_add_test(tc, s21_from_float_to_decimal_5);
  tcase_add_test(tc, s21_from_float_to_decimal_6);
  tcase_add_test(tc, s21_from_float_to_decimal_7);
  // tcase_add_test(tc, s21_from_float_to_decimal_8);
  // tcase_add_test(tc, s21_from_float_to_decimal_9);
  // tcase_add_test(tc, s21_from_float_to_decimal_10);
  tcase_add_test(tc, s21_from_float_to_decimal_11);
  tcase_add_test(tc, s21_from_float_to_decimal_12);
  suite_add_tcase(s, tc);
  return s;
}