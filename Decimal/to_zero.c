#include "s21_decimal.h"

void to_zero(s21_decimal *num) {
  for (int i = 0; i < 4; i++) num->bits[i] = 0;
}