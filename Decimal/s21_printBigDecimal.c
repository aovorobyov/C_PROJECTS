#include "s21_decimal.h"

/* 
*  Функция использует функцию printf для печати содержимого каждого элемента массива
*  битов cтруктуры s21_big_decimal в виде шестнадцатеричного числа, разделенного пробелами
*  Спецификатор формата %x используется для печати чисел в шестнадцатеричном формате.
*/

void s21_printBigDecimal(s21_big_decimal decimal) {
  printf("%x %x %x %x %x %x %x %x\n", decimal.bits[0], decimal.bits[1],
         decimal.bits[2], decimal.bits[3], decimal.bits[4], decimal.bits[5],
         decimal.bits[6], decimal.bits[7]);
}