#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  if (!this->s21_IsValideMatrix()) {
    throw std::invalid_argument("Invalid matrix");
  }
  if (this->rows_ != this->cols_) {
    throw std::logic_error("Matrix must be square");
  }

  double determinant = this->Determinant();
  if (determinant == 0) {
    throw std::logic_error("Determinant is zero");
  }

  S21Matrix calc = CalcComplements();
  S21Matrix res = calc.Transpose();
  res *= (1 / determinant);

  return res;
}