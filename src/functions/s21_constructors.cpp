#include "../s21_matrix_oop.h"

// default constructor
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

// param constructor
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 1 || cols_ < 1) {
    throw std::length_error("Invalid matrix size");
  } else {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0;
      }
    }
  }
}

// copy constructor
S21Matrix::S21Matrix(const S21Matrix &other) {
  if (this != &other) {
    this->cols_ = other.cols_;
    this->rows_ = other.rows_;
    this->matrix_ = new double *[this->rows_];
    for (int i = 0; i < this->rows_; i++) {
      this->matrix_[i] = new double[this->cols_];
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

// move constructor
S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

// destructor
S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}