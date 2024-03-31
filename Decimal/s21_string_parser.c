#include "s21_decimal.h"

int s21_stringParser(char* str, s21_decimal* dst) {
  int error = 0;
  DecimalString decStr = {6, 0, 0, 0};
  s21_big_decimal whole = {{0}}, temp1 = {{0}},
                  max_float = {{0x78e480, 0, 0, 0, 0, 0, 0, 0}};

  if (str[0] == '-') s21_setSign(dst, 1);

  for (int i = 0; str[i]; i++) {
    if (str[i] == 'e') decStr.exponent = 1;
    if (str[i] == '+') decStr.expSign = 1;
    if (str[i] >= '0' && str[i] <= '9' && !decStr.exponent) {
      temp1.bits[0] = str[i] - '0';
      s21_mul10(&whole);
      s21_bitwiseAddition(whole, temp1, &whole);
    }
    if (str[i] >= '0' && str[i] <= '9' && decStr.exponent) {
      decStr.scale = decStr.scale * 10 + (str[i] - '0');
    }
  }
  if (decStr.scale > 28 || s21_compare(whole, max_float) > 0) {
    error = 1;
    s21_toZero(dst);
  }
  if (!error) s21_transform(&whole, decStr, dst);
  return error;
}