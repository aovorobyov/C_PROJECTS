#include "s21_decimal.h"

void s21_setSign(s21_decimal* num, int sign_value) {
  if (sign_value) {
    num->bits[3] |= MINUS;
  } else
    num->bits[3] &= ~MINUS;
}