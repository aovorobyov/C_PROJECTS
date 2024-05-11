#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  // Проверяем корректность входных параметров
  int res = OK;
  if (result == NULL || rows <= 0 || columns <= 0) {
    res = INCORRECT;
  } else {
    // Инициализируем нулями все поля структуры
    result->matrix = NULL;
    result->rows = rows;
    result->columns = columns;

    // Выделяем память для массива указателей
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      // Выделяем память для каждой строки
      res = OK;
      for (int i = 0; i < rows && res == OK; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          res = INCORRECT;
        }
      }

      // Очищаем выделенную память в случае ошибки
      if (res == INCORRECT) {
        for (int i = 0; i < rows; i++) {
          free(result->matrix[i]);
        }
        free(result->matrix);
        result->matrix = NULL;
      }
    } else {
      res = INCORRECT;
    }
  }
  return res;
}