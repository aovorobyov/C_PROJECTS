#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0;
  if (!(IsDecValid(value_1) && IsDecValid(value_2)) ||
      (result ==
       NULL))  // проверка на корректность чисел и не NULL в результате
    err = 1;   // infinity
  else {
    if (!(GetSign(value_1) ^ GetSign(value_2))) {  // если знаки равны
      err = AddOrSub(value_1, value_2, result, 0);
    } else {
      if (GetSign(value_1))
        err = AddSubNeg(value_1, value_2, result, 1);
      else
        err = AddSubNeg(value_2, value_1, result, 1);
    }
    if (IsZero(*result)) SetSign(result, 0);
  }
  return err;
}