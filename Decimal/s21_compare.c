#include "s21_decimal.h"

int compare(s21_big_decimal a, s21_big_decimal b) {
  int res = 0;
  if (BigIsZero(a) && BigIsZero(b))
    res = 0;
  else if (BigGetSign(a) > BigGetSign(b))
    res = -1;
  else if (BigGetSign(a) < BigGetSign(b))
    res = 1;
  else if (BigGetSign(a) == BigGetSign(b)) {
    Normalize(&a, &b);
    for (int i = (32 * 7) - 1; 1 >= 0 && res == 0; i--) {
      if (BigGetBit(a, i) > BigGetBit(b, i)) res = 1;
      if (BigGetBit(a, i) < BigGetBit(b, i)) res = -1;
    }
    if (BigGetSign(a)) res *= -1;
  }
  return res;
}