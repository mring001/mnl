/*
 matrix_test.cc
*/
#include <iostream>
#include <mnl/matrix.h>
#include <mnl/rational.h>
#include <mnl/identity_matrix_factory.h>

int main() {
  mnl::Matrix<int, 2, 3> m1;
  mnl::Matrix<int, 2, 3> m2(m1);
  int v[2][2] = { {1,2}, {3,4} };
  int w[3][2] = { {4,5}, {6,7}, {8,9} };
  mnl::Matrix<int,2,2> m3(v);
  mnl::Matrix<int,2,2> m4 = v;
  int x = m3(1,0);
  m3(0,0) = 7;
  mnl::Matrix<int,2,3> m5 = m1 + m2;
  mnl::Matrix<int,3,2>m6 = w;
  mnl::Matrix<int,2,2>m7;

  int p[2][3] = { {2,3,4}, {3,4,5} };
  m2 = p;
  m7 =  m2 * m6;

  std::cout << "m2 = \n";
  std::cout << m2;
  std::cout << "m6 = \n";
  std::cout << m6;
  std::cout << "m2 * m6 = \n";
  std::cout << m7;

  mnl::Rational rat[2][2] = { {{3,5}, {2,9}}, {{1,4}, {5,6}} };
  mnl::Matrix<mnl::Rational,2,2> m8 = rat;
  std::cout << "m8 as Rational matrix:\n";
  std::cout << m8 << "\n";
  mnl::Matrix<double,2,2> m9 = mnl::Matrix<double,2,2>::approximate(m8);
  std::cout << "m8 as double approximation:\n";
  std::cout << m9 << "\n";

  mnl::Matrix<int,4,4> i4;
  i4 = mnl::IdentityMatrixFactory<int>::create<4>();
  std::cout << "I4:\n";
  std::cout << i4 << "\n";
  return 0;
}
