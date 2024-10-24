#ifndef S21MATRIX_OOP_H
#define S21MATRIX_OOP_H

#include <cmath>
#include <iostream>

class S21Matrix{
 private:
  int rows_, cols_;
  double **matrix_;
  const double EPS = 1e-7;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  // methods
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // overloaded operators
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(double number);
  S21Matrix operator*(const S21Matrix &other);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(double number);
  S21Matrix &operator*=(const S21Matrix &other);
  double &operator()(int row, int col);

  // helper
  bool s21_IsValideMatrix() const;
  int s21_getRows() const;
  int s21_getCols() const;
  S21Matrix s21_getMinor(int excluded_row, int excluded_col);
  double **getMatrix() const;
  void s21_inicializeMatrix(double start_value, double iteration_step);
  void printMatrix();
};


#endif  // S21MATRIX_OOP_H