#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (!this->s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  if (this->rows_ != this->cols_) {
    throw std::invalid_argument("Invalid matrix");
  }
  double res = 0;
  if (rows_ == 1) {
    res = this->matrix_[0][0];
  } else if (rows_ == 2) {
    res = this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[0][1] * this->matrix_[1][0];
  } else if (rows_ > 2) {
    res = 0;
    int sign = 1;
    for (int i = 0; i < rows_; i++) {
      S21Matrix minor = this->s21_getMinor(0, i);
      res += sign * this->matrix_[0][i] * minor.Determinant();
      sign *= -1;
    }
  }

  return res;
}