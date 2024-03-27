#include "s21_decimal.h"

s21_decimal div10(s21_decimal *decimal) {
  s21_decimal reminder = {{0}};
  s21_big_decimal res = {{0}};
  s21_big_decimal rem = {{0}};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal big_dec = {{0}};

  DecimalToBigDecimal(*decimal, &big_dec);
  rem = Divide(big_dec, ten, &res);
  BigDecimalToDecimal(res, decimal);
  BigDecimalToDecimal(rem, &reminder);
  return reminder;
}