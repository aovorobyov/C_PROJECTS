#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  if (!(IsDecValid(value_1) && IsDecValid(value_2)) || (result == NULL))
    err = 1;  // infinity
  else {
    if (!(GetSign(value_1) ^ GetSign(value_2))) {
      err = AddOrSub(value_1, value_2, result, 1);
    } else {
      if (GetSign(value_1)) {
        err = AddSubNeg(value_1, value_2, result, 0);
        s21_negate(*result, result);
        if (err) err++;
      } else
        err = AddSubNeg(value_2, value_1, result, 0);
    }
    if (IsZero(*result)) SetSign(result, 0);
  }
  return err;
}