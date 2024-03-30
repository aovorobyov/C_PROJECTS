#include "s21_decimal.h"

/* 
*  Функция проверяет, является ли число s21_big_decimal нулем или нет путем проверки
*  его первых семи бит.
*  Инициализируется локальная целочисленная переменная res нулем, а затем выполняется
*  итерация по первым семи битам массива битов входного числа s21_big_decimal, 
*  используя цикл for. Внутри цикла побитовый оператор | используется для установки
*  соответствующего бита res в 1, если какой-либо из битов в текущей итерации не равен 
*  нулю. Если все биты в массиве битов равны нулю, то значение res останется нулевым.
*  После цикла функция возвращает отрицание res, используя оператор !. Это означает,
*  что если все биты массива битов равны нулю, то значение res равно нулю, а
*  функция возвращает 1 (истина), указывая, что входное число равно нулю. В противном
*  случае, если какой-либо из битов не равен нулю, то значение res не равно нулю, и 
*  функция возвращает 0 (ложь), указывая, что входное число не равно нулю.
*/

int s21_bigIsZero(s21_big_decimal num) {
  int res = 0;
  for (int i = 0; i < 7 && res == 0; i++) {
    res |= num.bits[i];
  }
  return !res;
}