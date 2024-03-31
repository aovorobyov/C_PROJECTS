#include "s21_decimal.h"

int s21_isZero(s21_decimal num) {
  return !num.bits[0] && !num.bits[1] && !num.bits[2];
}