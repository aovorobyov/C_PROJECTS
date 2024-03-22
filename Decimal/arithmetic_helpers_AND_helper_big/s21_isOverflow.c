#include "s21_decimal.h"

/* 
*  Функция проверяет, не переполнено ли значение s21_big_decimal, проверяя, 
*  установлены ли какие-либо биты в полях от bits[3] до bits[6]. Если какой-либо из 
*  этих битов установлен, функция возвращает 1, указывая на то, что значение переполнено
*/

int s21_isOverflow(s21_big_decimal decimal) {
  int ret = 0;
  if (decimal.bits[3] || decimal.bits[4] || decimal.bits[5] || decimal.bits[6])
    ret = 1;
  return ret;
}