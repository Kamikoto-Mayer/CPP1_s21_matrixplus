#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  if (!this->s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  S21Matrix res(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      res(i, j) = (*this)(j, i);
    }
  }
  return res;
}