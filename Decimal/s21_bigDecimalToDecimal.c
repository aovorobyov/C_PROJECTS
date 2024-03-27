#include "s21_decimal.h"

// Функция преобразует тип s21_big_decimal в тип s21_decimal

void s21_bigDecimalToDecimal(s21_big_decimal big_decimal,
                             s21_decimal* decimal) {
  decimal->bits[0] = big_decimal.bits[0];
  decimal->bits[1] = big_decimal.bits[1];
  decimal->bits[2] = big_decimal.bits[2];
  decimal->bits[3] = big_decimal.bits[7];
}