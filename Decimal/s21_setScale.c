#include "s21_decimal.h"

void s21_setScale(s21_decimal* num, int scale_value) {
  num->bits[3] &= MINUS;
  num->bits[3] |= (scale_value << 16);
}