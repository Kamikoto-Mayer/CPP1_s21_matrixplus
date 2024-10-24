#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (!this->s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }

  if (this->rows_ != this->cols_ || (this->rows_ < 2 && this->cols_ < 2)) {
    throw std::invalid_argument("Matrix must be square");
  }

  S21Matrix res(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      S21Matrix minor = this->s21_getMinor(i, j);
      double determinant = minor.Determinant();
      res(i, j) = determinant * pow(-1, i + j);
    }
  }

  return res;
}