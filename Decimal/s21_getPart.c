#include "s21_decimal.h"

int s21_getPart(int num) {
  int part;
  if (num < 32) part = 0;
  if (num >= 32 && num < 64) part = 1;
  if (num >= 64 && num < 96) part = 2;
  return part;
}