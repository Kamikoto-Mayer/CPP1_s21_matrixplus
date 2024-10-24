#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (!this->s21_IsValideMatrix() || !other.s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix!");
  }
  if (this->cols_ != other.rows_) {
    throw std::invalid_argument("Invalid matrix!");
  }
  S21Matrix result(this->rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      for (int k = 0; k < this->cols_; k++) {
        result(i, j) += (this->matrix_[i][k] * other.matrix_[k][j]);
      }
    }
  }

  *this = std::move(result);
}