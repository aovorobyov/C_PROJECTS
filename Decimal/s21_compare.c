#include "s21_decimal.h"

int s21_compare(s21_big_decimal a, s21_big_decimal b) {
  int res = 0;
  if (s21_bigIsZero(a) && s21_bigIsZero(b))
    res = 0;
  else if (s21_bigGetSign(a) > s21_bigGetSign(b))
    res = -1;
  else if (s21_bigGetSign(a) < s21_bigGetSign(b))
    res = 1;
  else if (s21_bigGetSign(a) == s21_bigGetSign(b)) {
    s21_normalise(&a, &b);
    for (int i = (32 * 7) - 1; 1 >= 0 && res == 0; i--) {
      if (s21_bigGetBit(a, i) > s21_bigGetBit(b, i)) res = 1;
      if (s21_bigGetBit(a, i) < s21_bigGetBit(b, i)) res = -1;
    }
    if (s21_bigGetSign(a)) res *= -1;
  }
  return res;
}