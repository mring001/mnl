#include <iostream>
#include <mnl/core/rational.h>

int main() {
  mnl::core::Rational r1;
  mnl::core::Rational r2(5);
  mnl::core::Rational r3(3,4);
  mnl::core::Rational r4(r3);
  mnl::core::Rational r5(18,24);
  mnl::core::Rational r6;
  mnl::core::Rational r7 = {2,9};
  mnl::core::Rational r8 = {3,-8};
  mnl::core::Rational r9 = {0,9};
  r2 += r1;
  r4 = r3 / r3;

  std::cout << r3 << " / " << r3 << " = " << r4 << "\n";
  std::cout << "r2 = " << r2 << "\n";
  std::string s1 = (r3 == r5) ? "true" : "false";
  std::cout << r3 << " == " << r5 << " is " << s1 << "\n";

  r6 = {3,17};
  std::cout << "r6 = " << r6 << "\n";
  std::cout << "r8 = " << r8 << "\n";
  std::cout << "r9 = " << r9 << "\n";
  return 0;
}
