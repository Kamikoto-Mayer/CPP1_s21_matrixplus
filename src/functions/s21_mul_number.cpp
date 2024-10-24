#include "../s21_matrix_oop.h"

void S21Matrix::MulNumber(const double num) {
  if (!this->matrix_) {
    throw std::invalid_argument("Invalid matrix");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}