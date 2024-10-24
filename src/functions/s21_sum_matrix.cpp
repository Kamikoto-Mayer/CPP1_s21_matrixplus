#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!this->s21_IsValideMatrix() || !other.s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid matrix size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}