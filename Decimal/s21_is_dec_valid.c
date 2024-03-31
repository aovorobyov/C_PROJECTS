#include "s21_decimal.h"

int is_dec_valid(s21_decimal decimal) {
  int ret = 1;
  if ((s21_getScale(decimal) > 28) || ((~(MINUS | SCALE) & decimal.bits[3]) != 0)) {
    ret = 0;
  }
  return ret;
}