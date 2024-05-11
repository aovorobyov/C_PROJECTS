#include "s21_matrix.h"

double abs_double(double src) { return src < 0 ? src * (-1) : src; }

int pow_minus_one(int rank) { return rank % 2 == 0 ? 1 : -1; }

int s21_copy_matrix(matrix_t* A, matrix_t* result) {
  int rtrn = OK;

  if (is_correct(A) || result == NULL) rtrn = INCORRECT;

  if (!rtrn) {
    rtrn = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; !rtrn && i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j];
      }
    }
  }

  return rtrn;
}

int is_correct(matrix_t* A) {
  int rtrn = INCORRECT;

  if ((A != NULL) && (A->matrix != NULL) && (A->rows > 0) && (A->columns > 0)) {
    rtrn = OK;
  }

  return rtrn;
}

int is_correct_both(matrix_t* A, matrix_t* B) {
  int rtrn = INCORRECT;

  if (!is_correct(A) && !is_correct(B)) {
    rtrn = OK;
  }

  return rtrn;
}

int calc_is_equal_size(matrix_t* A, matrix_t* B) {
  int rtrn = ERROR_CALC;

  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    rtrn = OK;
  }

  return rtrn;
}

int calc_is_compatible_size(matrix_t* A, matrix_t* B) {
  int rtrn = ERROR_CALC;

  if (A->columns == B->rows) {
    rtrn = OK;
  }

  return rtrn;
}

int calc_is_square(matrix_t* A) {
  int rtrn = ERROR_CALC;

  if (A->rows == A->columns) {
    rtrn = OK;
  }

  return rtrn;
}