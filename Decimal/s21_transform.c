#include "s21_decimal.h"

void s21_transform(s21_big_decimal *whole, DecimalString decStr, s21_decimal *dst) {
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

  fract = s21_divide(*whole, mil, whole);

  for (; decStr.length && s21_bigIsZero(temp1);) {
    temp1 = s21_divide(fract, ten, &temp2);
    if (s21_bigIsZero(temp1)) {
      temp1 = s21_divide(fract, ten, &fract);
      decStr.length--;
    }
  }
  int temp = decStr.length;
  while (temp--) {
    s21_mul10(whole);
  }
  s21_bitwiseAddition(*whole, fract, whole);

  if (decStr.expSign) {
    while (decStr.scale > decStr.length) {
      s21_mul10(whole);
      decStr.scale--;
    }
    while (decStr.scale < decStr.length && decStr.scale > 0) {
      decStr.length--;
      decStr.scale--;
    }
    if (decStr.scale == decStr.length) decStr.scale = decStr.length = 0;
  }
  decStr.scale += decStr.length;

  s21_bigDecimalToDecimal(*whole, dst);
  s21_setScale(dst, decStr.scale);
}