/*
 matrix_test.cc
*/
#include <iostream>
#include <mnl/matrix.h>

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

  return 0;
}
