#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (!this->s21_IsValideMatrix() || !other.s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  bool flag = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    flag = false;
  }
  if (flag) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (EPS < fabs(this->matrix_[i][j] - other.matrix_[i][j])) {
          flag = false;
          break;
        }
      }
    }
  }
  return flag;
}