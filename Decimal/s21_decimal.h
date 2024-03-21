#ifndef S21_DECIMAL
#define S21_DECIMAL

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#include <stdio.h>
#include <stdlib.h>

s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int AddSubNeg(s21_decimal negative, s21_decimal positive, s21_decimal* result,
              int is_sub);
int AddOrSub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result,
             int is_sub);
int CorrectOverflow(s21_big_decimal* result_big, int scale, int sign);

#endif  // S21_DECIMAL