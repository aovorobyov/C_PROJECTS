#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 1;
  for (int i = 3; i >= 0; i--) {
    if (value_1.bits[i] != value_2.bits[i]) {
      res = 0;
      break;
    }
  }
  return res;
}