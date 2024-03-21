#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_big_decimal value_1_big, value_2_big, result_big = {{0}};
  int scale = 0, sign = 0, err = 0;

  if (!(IsDecValid(value_1) && IsDecValid(value_2)) || (result == NULL))
    err = 1;  // infinity
  else {
    DecimalToBigDecimal(value_1, &value_1_big);
    DecimalToBigDecimal(value_2, &value_2_big);
    sign = GetSign(value_1) ^ GetSign(value_2);
    scale = BigGetScale(value_1_big) + BigGetScale(value_2_big);
    BitwiseMultiplication(value_1_big, value_2_big, &result_big);

    if (!(BigIsZero(result_big)) || scale > 28) {
      err = CorrectOverflow(&result_big, scale, sign);
    } else
      BigSetScale(&result_big, scale);
    BigSetSign(&result_big, sign);
    BigDecimalToDecimal(result_big, result);
    if (IsZero(*result)) SetSign(result, 0);
  }
  return err;
}