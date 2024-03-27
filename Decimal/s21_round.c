#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result != NULL) {
    *result = value;
    s21_big_decimal value_big;
    s21_big_decimal temp = {{0}};
    DecimalToBigDecimal(value, &value_big);
    int scale = GetScale(value);
    int sign = GetSign(value);
    while (scale) {
      temp = BigDiv10(&value_big);
      scale--;
    }
    MathRounding(&value_big, temp);
    BigDecimalToDecimal(value_big, result);
    SetSign(result, sign);
    SetScale(result, 0);
  } else {
    error = 1;
  }
  return error;
}