#include "s21_decimal.h"

void transform(s21_big_decimal *whole, DecimalString decStr, s21_decimal *dst) {
  s21_big_decimal temp1 = {{0}};
  s21_big_decimal temp2 = {{0}};
  s21_big_decimal fract = {{0}};
  s21_big_decimal mil = {{
      0xf4240,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
  }};
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};

  fract = Divide(*whole, mil, whole);

  for (; decStr.length && BigIsZero(temp1);) {
    temp1 = Divide(fract, ten, &temp2);
    if (BigIsZero(temp1)) {
      temp1 = Divide(fract, ten, &fract);
      decStr.length--;
    }
  }
  int temp = decStr.length;
  while (temp--) {
    Mul10(whole);
  }
  BitwiseAddition(*whole, fract, whole);

  if (decStr.expSign) {
    while (decStr.scale > decStr.length) {
      Mul10(whole);
      decStr.scale--;
    }
    while (decStr.scale < decStr.length && decStr.scale > 0) {
      decStr.length--;
      decStr.scale--;
    }
    if (decStr.scale == decStr.length) decStr.scale = decStr.length = 0;
  }
  decStr.scale += decStr.length;

  BigDecimalToDecimal(*whole, dst);
  SetScale(dst, decStr.scale);
}