#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result != NULL) {
    int scale = GetScale(value);
    int sign = GetSign(value);
    if (IsZero(value)) {
      sign = 0;
      scale = 0;
    } else {
      while ((scale) && !(IsZero(value))) {
        div10(&value);
        scale--;
      }
    }
    *result = value;
    SetSign(result, sign);
    SetScale(result, scale);
  } else {
    error = 1;
  }
  return error;
}