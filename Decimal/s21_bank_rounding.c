#include "s21_decimal.h"

void bank_rounding(s21_big_decimal *decimal, s21_big_decimal rem) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  if (decimal->bits[0] & ODD) {
    if (rem.bits[0] >= 5) {
      BitwiseAddition(*decimal, one, decimal);
    }
  } else {
    if (rem.bits[0] > 5) {
      BitwiseAddition(*decimal, one, decimal);
    }
  }
}