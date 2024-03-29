#include "s21_decimal.h"

/* 
*  Функция выполняет побитовое сложение двух чисел s21_big_decimal и сохраняет результат
*  в третьем числе s21_big_decimal.
*  Функция инициализирует переменную переноса значением 0, которое будет использоваться 
*  для хранения любых битов переноса, сгенерированных во время сложения. Цикл выполняется 
*  32 * 7 раз, что эквивалентно количеству битов, необходимых для хранения числа
*  s21_big_decimal. Внутри цикла функция сначала извлекает i-й бит двух входных чисел с 
*  помощью функции s21_bigGetBit. Затем он складывает два полученных бита вместе с текущим 
*  значением переноса и сохраняет результат в переменной result_bit. Затем функция
*  вычисляет бит переноса для текущего сложения, разделив result_bit на 2 и взяв остаток.
*  Затем частное присваивается биту result_bit. Наконец, функция устанавливает i-й бит 
*  параметра результата в result_bit с помощью функции s21_bigSetBit
*/

void s21_bitwiseAddition(s21_big_decimal a, s21_big_decimal b,
                         s21_big_decimal* result) {
  unsigned carry = 0;
  for (int i = 0; i < 32 * 7; i++) {
    unsigned result_bit = s21_bigGetBit(a, i) + s21_bigGetBit(b, i) + carry;
    carry = result_bit / 2;
    result_bit %= 2;
    s21_bigSetBit(result, i, result_bit);
  }
}