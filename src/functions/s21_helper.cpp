// helper functions
#include "../s21_matrix_oop.h"

bool S21Matrix::s21_IsValideMatrix() const {
  return matrix_ != nullptr && rows_ > 0 && cols_ > 0;
}

int S21Matrix::s21_getCols() const { return cols_; }

int S21Matrix::s21_getRows() const { return rows_; }

S21Matrix S21Matrix::s21_getMinor(int excluded_row, int excluded_col) {
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  int minor_row = 0, minor_col = 0;

  for (int i = 0; i < this->rows_; i++) {
    if (i == excluded_row) continue;
    minor_col = 0;
    for (int j = 0; j < this->cols_; j++) {
      if (j == excluded_col) continue;
      minor(minor_row, minor_col) = this->matrix_[i][j];
      minor_col++;
    }
    minor_row++;
  }

  return minor;
}

double** S21Matrix::getMatrix() const { return matrix_; }

void S21Matrix::s21_inicializeMatrix(double start_value,
                                     double iteration_step) {
  if (!this->s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  double value = start_value;
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = value;
      value += iteration_step;
    }
  }
}

void S21Matrix::printMatrix() {
  if (!this->s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      std::cout << this->matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}