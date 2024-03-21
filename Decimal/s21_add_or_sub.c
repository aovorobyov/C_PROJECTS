#include "s21_decimal.h"

int AddOrSub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result,
             int is_sub) {  // сложение или вычитание (в зависимости от флага
                            // 0-сложение, 1-вычитание)
  s21_big_decimal value_1_big, value_2_big, result_big = {{0}};
  int negate = 0, scale = 0, err = 0,
      sign = GetSign(
          value_1);  // флаг необхожимости изм знака, , , знак результата

  DecimalToBigDecimal(value_1, &value_1_big);
  DecimalToBigDecimal(value_2, &value_2_big);
  Normalise(&value_1_big, &value_2_big);

  if (is_sub) {  // если вычитание
    if ((s21_is_greater(value_1, value_2) && !sign) ||
        (s21_is_less(value_1, value_2) &&
         sign)) {  // первое число >|< второго и знак рез окажется полож
      BitwiseSubtraction(value_1_big, value_2_big, &result_big);
    } else {
      BitwiseSubtraction(value_2_big, value_1_big, &result_big);
      negate = 1;
    }
  } else
    BitwiseAddition(value_1_big, value_2_big, &result_big);  // сложение
  scale = BigGetScale(value_1_big);
  sign = GetSign(value_1);
  // проверка не превышает ли масштаб максимум и не является ли рез 0
  if (!(BigIsZero(result_big)) || scale > 28) {
    err = CorrectOverflow(&result_big, scale, sign);  // коррекция переполнения
  } else
    BigSetScale(&result_big, scale);
  BigSetSign(&result_big, sign);
  BigDecimalToDecimal(result_big, result);  // обратно в дец. формат
  if (negate) s21_negate(*result, result);  // инверт знака  если нужно
  return err;
}