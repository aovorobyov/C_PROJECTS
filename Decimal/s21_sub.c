#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  if (!(is_dec_valid(value_1) && is_dec_valid(value_2)) || (result == NULL))
    err = 1;  // infinity
  else {
    if (!(s21_getSign(value_1) ^ s21_getSign(value_2))) {
      err = s21_add_or_sub(value_1, value_2, result, 1);
    } else {
      if (s21_getSign(value_1)) {
        err = s21_add_sub_neg(value_1, value_2, result, 0);
        s21_negate(*result, result);
        if (err) err++;
      } else
        err = s21_add_sub_neg(value_2, value_1, result, 0);
    }
    if (s21_isZero(*result)) s21_setSign(result, 0);
  }
  return err;
}