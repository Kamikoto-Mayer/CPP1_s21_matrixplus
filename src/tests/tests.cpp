#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// Тест для конструктора по умолчанию
TEST(S21MatrixTest, DefaultConstructor) {
  S21Matrix m;
  EXPECT_EQ(m.s21_getRows(), 0);
  EXPECT_EQ(m.s21_getCols(), 0);
}

// Тест для конструктора с параметрами
TEST(S21MatrixTest, ParameterConstructor) {
  S21Matrix m(3, 4);
  EXPECT_EQ(m.s21_getRows(), 3);
  EXPECT_EQ(m.s21_getCols(), 4);
}

// Тест для копирующего конструктора
TEST(S21MatrixTest, CopyConstructor) {
  S21Matrix m1(2, 2);
  S21Matrix m2(m1);
  EXPECT_EQ(m2.s21_getRows(), 2);
  EXPECT_EQ(m2.s21_getCols(), 2);
  EXPECT_TRUE(m1 == m2);
}

// Тест для конструктора перемещения
TEST(S21MatrixTest, MoveConstructor) {
  S21Matrix m1(2, 2);
  S21Matrix m2(std::move(m1));
  EXPECT_EQ(m2.s21_getRows(), 2);
  EXPECT_EQ(m2.s21_getCols(), 2);
  EXPECT_EQ(m1.s21_getRows(), 0);
  EXPECT_EQ(m1.s21_getCols(), 0);
}

// Тест для деструктора
TEST(S21MatrixTest, Destructor) {
  S21Matrix m(2, 2);
  EXPECT_EQ(m.s21_getRows(), 2);
  EXPECT_EQ(m.s21_getCols(), 2);
}

// Тест для оператора сложения(+)
TEST(S21MatrixTest, SumOperator) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 1);

  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(1, 2);

  S21Matrix m3 = m1 + m2;
  EXPECT_EQ(m3.s21_getRows(), 2);
  EXPECT_EQ(m3.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m3(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), 5.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), 8.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 11.0);
}

// Тест для оператора вычитания(-)
TEST(S21MatrixTest, SubOperator) {
  S21Matrix m1(3, 3);
  m1.s21_inicializeMatrix(7, 3);
  S21Matrix m2(3, 3);
  m2.s21_inicializeMatrix(4, 2);
  S21Matrix m3 = m1 - m2;
  EXPECT_EQ(m3.s21_getRows(), 3);
  EXPECT_EQ(m3.s21_getCols(), 3);
  EXPECT_DOUBLE_EQ(m3(0, 0), 3.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m3(0, 2), 5.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 7.0);
  EXPECT_DOUBLE_EQ(m3(1, 2), 8.0);
  EXPECT_DOUBLE_EQ(m3(2, 0), 9.0);
  EXPECT_DOUBLE_EQ(m3(2, 1), 10.0);
  EXPECT_DOUBLE_EQ(m3(2, 2), 11.0);
}

// Тест для оператора умножения на число(*)
TEST(S21MatrixTest, MulNumberOperator) {
  S21Matrix m1(3, 3);
  m1.s21_inicializeMatrix(7, 3);

  S21Matrix m3 = m1 * 13;
  EXPECT_EQ(m3.s21_getRows(), 3);
  EXPECT_EQ(m3.s21_getCols(), 3);
  EXPECT_DOUBLE_EQ(m3(0, 0), 91.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), 130.0);
  EXPECT_DOUBLE_EQ(m3(0, 2), 169.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), 208.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 247.0);
  EXPECT_DOUBLE_EQ(m3(1, 2), 286.0);
  EXPECT_DOUBLE_EQ(m3(2, 0), 325.0);
  EXPECT_DOUBLE_EQ(m3(2, 1), 364.0);
  EXPECT_DOUBLE_EQ(m3(2, 2), 403.0);
}

// Тест для оператора умножения на матрицу(*)
TEST(S21MatrixTest, MulMatrixOperator) {
  S21Matrix m1(3, 3);
  m1.s21_inicializeMatrix(7, 3);
  S21Matrix m2(3, 3);
  m2.s21_inicializeMatrix(4, 2);

  S21Matrix m3 = m1 * m2;

  EXPECT_EQ(m3.s21_getRows(), 3);
  EXPECT_EQ(m3.s21_getCols(), 3);
  EXPECT_DOUBLE_EQ(m3(0, 0), 336.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), 396.0);
  EXPECT_DOUBLE_EQ(m3(0, 2), 456.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), 606.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 720.0);
  EXPECT_DOUBLE_EQ(m3(1, 2), 834.0);
  EXPECT_DOUBLE_EQ(m3(2, 0), 876.0);
  EXPECT_DOUBLE_EQ(m3(2, 1), 1044.0);
  EXPECT_DOUBLE_EQ(m3(2, 2), 1212.0);
}

// Тест для оператора равенства(==)
TEST(S21MatrixTest, EqualOperator) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 1);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(1, 1);
  EXPECT_TRUE(m1 == m2);
}

// Тест для оператора неравенства(==)
TEST(S21MatrixTest, NotEqualOperator) {
  S21Matrix m1(2, 3);
  m1.s21_inicializeMatrix(1, 1);
  S21Matrix m2(2, 6);
  m2.s21_inicializeMatrix(1, 1);
  EXPECT_FALSE(m1 == m2);
}

// Тест для оператора присваивания
TEST(S21MatrixTest, AssignmentOperator) {
  S21Matrix m1(2, 2);
  S21Matrix m2;
  m2 = m1;
  EXPECT_EQ(m2.s21_getRows(), 2);
  EXPECT_EQ(m2.s21_getCols(), 2);
  EXPECT_TRUE(m1 == m2);
}

// Тест для оператора сложения с присваиванием(+=)
TEST(S21MatrixTest, SumAssignmentOperator) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 1);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(1, 2);
  m1 += m2;
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 5.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 8.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 11.0);
}

// Тест для оператора вычитания с присваиванием(-=)
TEST(S21MatrixTest, SubAssignmentOperator) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(3, 4);
  m1 -= m2;
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), -1.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 1.0);
}

// Тест для оператора умножения с присваиванием чисел(*=)
TEST(S21MatrixTest, MulNumberAssignmentOperator) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  m1 *= 248;
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 248.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 1488.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 2728.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 3968.0);
}

// Тест для оператора умножения с присваиванием матриц(*=)
TEST(S21MatrixTest, MulMatrixAssignmentOperator) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(3, 4);
  m1 *= m2;
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 69.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 97.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 209.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 317.0);
}

// Тест для оператора доступа
TEST(S21MatrixTest, AccessOperator) {
  S21Matrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(m(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m(1, 1), 4.0);
}

// Тест для метода сложения матриц
TEST(S21MatrixTest, SumMatrix) {
  S21Matrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(2, 2);
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  m1.SumMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 12.0);
}

// Тест для оператора вычитания mатриц
TEST(S21MatrixTest, SubMatrix) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(3, 4);
  m1.SubMatrix(m2);
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), -1.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 1.0);
}

// Тест для оператора сравнения mатриц
TEST(S21MatrixTest, NotEqalMatrix) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(3, 4);
  bool rc = m1.EqMatrix(m2);
  EXPECT_FALSE(rc);
}
TEST(S21MatrixTest, EqalMatrix) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(3, 5);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(3, 5);
  bool rc = m1.EqMatrix(m2);
  EXPECT_TRUE(rc);
}

// Тест для функции умножения чисел
TEST(S21MatrixTest, MulNumber) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  m1.MulNumber(248);
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 248.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 1488.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 2728.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 3968.0);
}

// Тест для метода умножения матриц
TEST(S21MatrixTest, MulMatrix) {
  S21Matrix m1(2, 2);
  m1.s21_inicializeMatrix(1, 5);
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(3, 4);
  m1.MulMatrix(m2);
  EXPECT_EQ(m1.s21_getRows(), 2);
  EXPECT_EQ(m1.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 69.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 97.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 209.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 317.0);
}

// Тест для метода транспонирования матриц
TEST(S21MatrixTest, TransposeMatrix) {
  S21Matrix m2(3, 3);
  m2.s21_inicializeMatrix(1, 5);
  S21Matrix m1 = m2.Transpose();
  EXPECT_EQ(m1.s21_getRows(), 3);
  EXPECT_EQ(m1.s21_getCols(), 3);
  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 16.0);
  EXPECT_DOUBLE_EQ(m1(0, 2), 31.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 21.0);
  EXPECT_DOUBLE_EQ(m1(1, 2), 36.0);
  EXPECT_DOUBLE_EQ(m1(2, 0), 11.0);
  EXPECT_DOUBLE_EQ(m1(2, 1), 26.0);
  EXPECT_DOUBLE_EQ(m1(2, 2), 41.0);
}

// Тест для метода алгебраической дополнительной матриц
TEST(S21MatrixTest, CalcComplementsMatrix) {
  S21Matrix m2(3, 3);
  m2.s21_inicializeMatrix(1, 2);
  S21Matrix complements = m2.CalcComplements();
  EXPECT_EQ(complements.s21_getRows(), 3);
  EXPECT_EQ(complements.s21_getCols(), 3);
  EXPECT_DOUBLE_EQ(complements(0, 0), -12.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 24.0);
  EXPECT_DOUBLE_EQ(complements(0, 2), -12.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), 24.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), -48.0);
  EXPECT_DOUBLE_EQ(complements(1, 2), 24.0);
  EXPECT_DOUBLE_EQ(complements(2, 0), -12.0);
  EXPECT_DOUBLE_EQ(complements(2, 1), 24.0);
  EXPECT_DOUBLE_EQ(complements(2, 2), -12.0);
}

// Тест для метода детерминанта матриц
TEST(S21MatrixTest, DeterminantMatrix) {
  S21Matrix m2(3, 3);
  m2.s21_inicializeMatrix(1, 5);
  double d = m2.Determinant();
  EXPECT_DOUBLE_EQ(d, 0.0);
}

// Тест для метода инвертирования матриц
TEST(S21MatrixTest, InversMatrix) {
  S21Matrix m2(2, 2);
  m2.s21_inicializeMatrix(1, 1);
  S21Matrix inversion = m2.InverseMatrix();
  EXPECT_EQ(inversion.s21_getRows(), 2);
  EXPECT_EQ(inversion.s21_getCols(), 2);
  EXPECT_DOUBLE_EQ(inversion(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(inversion(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(inversion(1, 0), 1.5);
  EXPECT_DOUBLE_EQ(inversion(1, 1), -0.5);
}

// Тест для метода неинвертирования матриц
// TEST(S21MatrixTest, NotInversMatrix) {
//   S21Matrix m2(2, 3);
//   m2.s21_inicializeMatrix(1, 1);
//   S21Matrix inversion = m2.InverseMatrix();
//   EXPECT_EQ(inversion.s21_getRows(), 2);
//   EXPECT_EQ(inversion.s21_getCols(), 2);
//   EXPECT_DOUBLE_EQ(inversion(0, 0), -2.0);
//   EXPECT_DOUBLE_EQ(inversion(0, 1), 1.0);
//   EXPECT_DOUBLE_EQ(inversion(1, 0), 1.5);
//   EXPECT_DOUBLE_EQ(inversion(1, 1), -0.5);
// }

// TEST(S21MatrixTest, InversMatrix) {
//   S21Matrix m2(2, 2);
//   m2.s21_inicializeMatrix(2, 12);
//   S21Matrix inversion = m2.InverseMatrix();
//   EXPECT_EQ(inversion.s21_getRows(), 2);
//   EXPECT_EQ(inversion.s21_getCols(), 2);
//   EXPECT_DOUBLE_EQ(inversion(0, 0), -2.0);
//   EXPECT_DOUBLE_EQ(inversion(0, 1), 1.0);
//   EXPECT_DOUBLE_EQ(inversion(1, 0), 1.5);
//   EXPECT_DOUBLE_EQ(inversion(1, 1), -0.5);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}
