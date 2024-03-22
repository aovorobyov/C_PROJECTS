#include "s21_decimal.h"

// Функция преобразует тип s21_decimal в тип s21_big_decimal

void s21_decimalToBigDecimal(s21_decimal decimal, s21_big_decimal* big_decimal) {
  big_decimal->bits[0] = decimal.bits[0];
  big_decimal->bits[1] = decimal.bits[1];
  big_decimal->bits[2] = decimal.bits[2];
  big_decimal->bits[3] = big_decimal->bits[4] = big_decimal->bits[5] =
      big_decimal->bits[6] = 0;
  big_decimal->bits[7] = decimal.bits[3];
}