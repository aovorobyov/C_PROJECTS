#include "s21_decimal.h"

/* 
*  Функция выполняет побитовое вычитание двух входных чисел, перебирая каждый бит чисел
*  и вычисляя бит результата на основе текущих битов a и b и значения переноса. Значение
*  переноса рассчитывается как частное бита результата, деленного на 2, а бит результата
*  вычисляется как остаток бита результата, разделенный на 2.
*  Функция использует временное число s21_big_decimal temp1 для хранения промежуточного
*  результата побитового вычитания.
*  Функция использует константу one, которая определяется как {{1, 0, 0, 0, 0, 0, 0, 0}},
*  которая представляет собой число s21_big_decimal со значением 1
*/

void s21_bitwiseSubtraction(s21_big_decimal a, s21_big_decimal b,
                            s21_big_decimal* result) {
  s21_big_decimal temp1 = {{0}}, one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  unsigned carry = 0;
  for (int i = 0; i < 32 * 7; i++) {
    unsigned result_bit = s21_bigGetBit(a, i) + !(s21_bigGetBit(b, i)) + carry;
    carry = result_bit / 2;
    result_bit %= 2;
    s21_bigSetBit(&temp1, i, result_bit);
  }
  s21_bitwiseAddition(temp1, one, result);
}