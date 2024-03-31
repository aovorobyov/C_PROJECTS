#include "s21_decimal.h"

void s21_mathRounding(s21_big_decimal *decimal, s21_big_decimal rem) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  if (rem.bits[0] >= 5) {
    s21_bitwiseAddition(*decimal, one, decimal);
  }
}