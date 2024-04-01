#include "test.h"

START_TEST(s21_less_1) {
  s21_decimal first = {{4412, 5675, 1254, 0b10000000000000000000000000000000}};
  s21_decimal second = {{4412, 5675, 1254, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 1);
}
END_TEST

START_TEST(s21_less_2) {
  s21_decimal first = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal second = {{0, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(s21_is_less(first, second), 0);
}
END_TEST

// START_TEST(s21_less_3) {
//   s21_decimal first = {{4412, 5675, 1254,
//   0b00000011000000000000000000000000}}; s21_decimal second = {{4412, 5675,
//   1254, 0b00000101000000000000000000000000}};
//   ck_assert_int_eq(s21_is_less(first, second), 0);
// }
// END_TEST

// START_TEST(s21_less_4) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_less(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_less_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;
  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_less(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_equal_1) {
//   s21_decimal first = {{4412, 5675, 1254,
//   0b00000100000000000010000000000000}}; s21_decimal second = {{4412, 5675,
//   1254, 0b00000100000000000010000000000000}};
//   ck_assert_int_eq(s21_is_equal(first, second), 1);
// }
// END_TEST

START_TEST(s21_equal_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1244, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

// START_TEST(s21_equal_3) {
//   s21_decimal first = {
//       {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
//   s21_decimal second = {
//       {0x4A1D, 05675, 1254, 0b10110100111111110010000000000011}};
//   ck_assert_int_eq(s21_is_equal(first, second), 1);
// }
// END_TEST

START_TEST(s21_equal_4) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_equal(first, second), 0);
}
END_TEST

// START_TEST(s21_equal_5) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_not_equal_1) {
//   s21_decimal first = {{4412, 5675, 1254,
//   0b10110010000000001110000111000011}}; s21_decimal second = {{4412, 5675,
//   1254, 0b11001001000000000010000111111110}};
//   ck_assert_int_eq(s21_is_not_equal(first, second), 0);
// }
// END_TEST

START_TEST(s21_not_equal_2) {
  s21_decimal first = {{4412, 5675, 1254, 0b00110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_3) {
  s21_decimal first = {{4412, 5675, 1154, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

START_TEST(s21_not_equal_4) {
  s21_decimal first = {{412, 5675, 1254, 0b10110100111111110010000000000011}};
  s21_decimal second = {{4412, 5675, 1254, 0b11110100000000000010000111111110}};
  ck_assert_int_eq(s21_is_not_equal(first, second), 1);
}
END_TEST

// START_TEST(s21_not_equal_5) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_not_equal(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

// START_TEST(s21_not_equal_6) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 18446744073709551615;
//   // src2 = 18446744073709551615.000000000;
//   src1.bits[0] = 0b11111111111111111111111111111111;
//   src1.bits[1] = 0b11111111111111111111111111111111;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b11000100011001010011011000000000;
//   src2.bits[1] = 0b11111111111111111111111111111111;
//   src2.bits[2] = 0b00111011100110101100100111111111;
//   src2.bits[3] = 0b00000000000010010000000000000000;
//   int result = s21_is_not_equal(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_not_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;
  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_less_or_equal_1) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_less_or_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_less_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
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
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_less_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_less_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_less_or_equal_6) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2.7986531268974139743;
//   // src2 = 2.7986531268974139743;
//   src1.bits[0] = 0b11111110100100001101100101011111;
//   src1.bits[1] = 0b10000100011001000010000111101000;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   src2.bits[0] = 0b11111110100100001101100101011111;
//   src2.bits[1] = 0b10000100011001000010000111101000;
//   src2.bits[2] = 0b00000000000000000000000000000001;
//   src2.bits[3] = 0b00000000000100110000000000000000;
//   int result = s21_is_less_or_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

// START_TEST(s21_less_or_equal_7) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = -2156878451.8547640000000000;
//   // src2 = -2156878451.854764;
//   src1.bits[0] = 0b10010011100100010011000000000000;
//   src1.bits[1] = 0b00100110110100100010010100001001;
//   src1.bits[2] = 0b00000000000100011101011101011110;
//   src1.bits[3] = 0b10000000000100000000000000000000;
//   src2.bits[0] = 0b01100101111100100100110110101100;
//   src2.bits[1] = 0b00000000000001111010100110101011;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b10000000000001100000000000000000;
//   int result = s21_is_less_or_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

// START_TEST(s21_less_or_equal_8) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 44073709551615.0;
//   // src2 = 44073709551615.00000000;
//   src1.bits[0] = 0b00011010000001000111111111110110;
//   src1.bits[1] = 0b00000000000000011001000011011001;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   src2.bits[0] = 0b10011111010010100001111100000000;
//   src2.bits[1] = 0b11101100100011110001010001110111;
//   src2.bits[2] = 0b00000000000000000000000011101110;
//   src2.bits[3] = 0b00000000000010000000000000000000;
//   int result = s21_is_less_or_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

// START_TEST(s21_greater_1) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_greater(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_greater_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.22221200000001000;
  // src2 = 2.222212;
  src1.bits[0] = 0b00000111100011111010001111101000;
  src1.bits[1] = 0b00000011000101010111110100000001;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  src2.bits[0] = 0b00000000001000011110100010000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_greater_7) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = -9878798789.5867800;
//   // src2 = -9878798789.58678;
//   src1.bits[0] = 0b11001110100110111101100110011000;
//   src1.bits[1] = 0b00000001010111101111011100100110;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000001110000000000000000;
//   src2.bits[0] = 0b10110101010001000001111001010110;
//   src2.bits[1] = 0b00000000000000111000001001111000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b10000000000001010000000000000000;
//   int result = s21_is_greater(src1, src2);
//   origin = 0;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_greater_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -854764561465456456.9876545679;
  // src2 = -87654323456.98765456789876530;
  src1.bits[0] = 0b11000100000001000100000010001111;
  src1.bits[1] = 0b01000000100100100110001100010101;
  src1.bits[2] = 0b00011011100111100111001001011101;
  src1.bits[3] = 0b10000000000010100000000000000000;
  src2.bits[0] = 0b10110010000010100010111100110010;
  src2.bits[1] = 0b10011001010111000101110110000000;
  src2.bits[2] = 0b00011100010100101001100001111111;
  src2.bits[3] = 0b10000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_11) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.5456465465486476846545465485;
  // src2 = 45645405.456456345684654546548;
  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b01000110110111011101111001110100;
  src2.bits[1] = 0b11111110010110110111101101110010;
  src2.bits[2] = 0b10010011011111001111111010010011;
  src2.bits[3] = 0b00000000000101010000000000000000;
  int result = s21_is_greater(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

// START_TEST(s21_greater_or_equal_1) {
//   s21_decimal src1, src2;
//   int origin;
//   // src1 = 2;
//   // src2 = 2;
//   src1.bits[0] = 0b00000000000000000000000000000010;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b00000000000000000000000000000010;
//   src2.bits[1] = 0b00000000000000000000000000000000;
//   src2.bits[2] = 0b00000000000000000000000000000000;
//   src2.bits[3] = 0b00000000000000000000000000000000;
//   int result = s21_is_greater_or_equal(src1, src2);
//   origin = 1;
//   ck_assert_int_eq(origin, result);
// }
// END_TEST

START_TEST(s21_greater_or_equal_2) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 457;
  // src2 = 2.00;
  src1.bits[0] = 0b00000000000000000000000111001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000011001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_3) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2;
  // src2 = 54;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000110110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_4) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_5) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -3;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_6) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 2.222212;
  // src2 = -2.2222120002;
  src1.bits[0] = 0b00000000001000011110100010000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  src2.bits[0] = 0b00101100100010101010010001000010;
  src2.bits[1] = 0b00000000000000000000000000000101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_7) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -545454512454545.35265454545645;
  // src2 = -5.352654545456454545645464;
  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b01001000000110110001111110011000;
  src2.bits[1] = 0b11111011111111011000100101101101;
  src2.bits[2] = 0b00000000000001000110110101110111;
  src2.bits[3] = 0b10000000000110000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_8) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 0.0;
  // src2 = 0.69;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00000000000000000000000001000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_9) {
  s21_decimal src1, src2;
  int origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -79228162514264337593543950335;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b10000000000000000000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 1;
  ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(s21_greater_or_equal_10) {
  s21_decimal src1, src2;
  int origin;
  // src1 = -2.514475768684753643;
  // src2 = -2.514264337593542;
  src1.bits[0] = 0b10101100110010000011001011101011;
  src1.bits[1] = 0b00100010111001010011011001100011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  src2.bits[0] = 0b11001000101101101011010011000110;
  src2.bits[1] = 0b00000000000010001110111010110101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000011110000000000000000;
  int result = s21_is_greater_or_equal(src1, src2);
  origin = 0;
  ck_assert_int_eq(origin, result);
}
END_TEST

Suite *test_compare(void) {
  Suite *s = suite_create("S21_COMPARE");
  TCase *tc = tcase_create("compare_tc");

  tcase_add_test(tc, s21_less_1);
  tcase_add_test(tc, s21_less_2);
  // tcase_add_test(tc, s21_less_3);
  // tcase_add_test(tc, s21_less_4);
  tcase_add_test(tc, s21_less_5);
  tcase_add_test(tc, s21_less_6);
  tcase_add_test(tc, s21_less_7);
  // tcase_add_test(tc, s21_equal_1);
  tcase_add_test(tc, s21_equal_2);
  // tcase_add_test(tc, s21_equal_3);
  tcase_add_test(tc, s21_equal_4);
  // tcase_add_test(tc, s21_equal_5);
  tcase_add_test(tc, s21_equal_6);
  tcase_add_test(tc, s21_equal_7);
  // tcase_add_test(tc, s21_not_equal_1);
  tcase_add_test(tc, s21_not_equal_2);
  tcase_add_test(tc, s21_not_equal_3);
  tcase_add_test(tc, s21_not_equal_4);
  // tcase_add_test(tc, s21_not_equal_5);
  // tcase_add_test(tc, s21_not_equal_6);
  tcase_add_test(tc, s21_not_equal_7);
  // tcase_add_test(tc, s21_less_or_equal_1);
  tcase_add_test(tc, s21_less_or_equal_2);
  tcase_add_test(tc, s21_less_or_equal_3);
  tcase_add_test(tc, s21_less_or_equal_4);
  tcase_add_test(tc, s21_less_or_equal_5);
  // tcase_add_test(tc, s21_less_or_equal_6);
  // tcase_add_test(tc, s21_less_or_equal_7);
  // tcase_add_test(tc, s21_less_or_equal_8);
  // tcase_add_test(tc, s21_greater_1);
  tcase_add_test(tc, s21_greater_2);
  tcase_add_test(tc, s21_greater_3);
  tcase_add_test(tc, s21_greater_4);
  tcase_add_test(tc, s21_greater_5);
  tcase_add_test(tc, s21_greater_6);
  // tcase_add_test(tc, s21_greater_7);
  tcase_add_test(tc, s21_greater_8);
  tcase_add_test(tc, s21_greater_9);
  tcase_add_test(tc, s21_greater_10);
  tcase_add_test(tc, s21_greater_11);
  // tcase_add_test(tc, s21_greater_or_equal_1);
  tcase_add_test(tc, s21_greater_or_equal_2);
  tcase_add_test(tc, s21_greater_or_equal_3);
  tcase_add_test(tc, s21_greater_or_equal_4);
  tcase_add_test(tc, s21_greater_or_equal_5);
  tcase_add_test(tc, s21_greater_or_equal_6);
  tcase_add_test(tc, s21_greater_or_equal_7);
  tcase_add_test(tc, s21_greater_or_equal_8);
  tcase_add_test(tc, s21_greater_or_equal_9);
  tcase_add_test(tc, s21_greater_or_equal_10);
  suite_add_tcase(s, tc);
  return s;
}