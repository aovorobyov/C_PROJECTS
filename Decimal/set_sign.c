#include "s21_decimal.h"

void SetSign(s21_decimal* num, int sign) {
  if (sign)
    num->bits[3] |= 1;
  else
    num->bits[3] &= ~1;
}
