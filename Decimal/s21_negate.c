#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result != NULL) {
    result->bits[3] = value.bits[3];
    s21_setSign(result, !(s21_getSign(*result)));
    for (int i = 0; i < 96; i++) {
      s21_setBit(result, i, s21_getBit(value, i));
    }
  } else
    error = 1;
  return error;
}