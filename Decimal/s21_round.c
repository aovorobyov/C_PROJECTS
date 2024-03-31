#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result != NULL) {
    *result = value;
    s21_big_decimal value_big;
    s21_big_decimal temp = {{0}};
    s21_decimalToBigDecimal(value, &value_big);
    int scale = s21_getScale(value);
    int sign = s21_getSign(value);
    while (scale) {
      temp = s21_bigDiv10(&value_big);
      scale--;
    }
    s21_mathRounding(&value_big, temp);
    s21_bigDecimalToDecimal(value_big, result);
    s21_setSign(result, sign);
    s21_setScale(result, 0);
  } else {
    error = 1;
  }
  return error;
}