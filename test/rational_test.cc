#include <iostream>
#include <mnl/rational.h>

int main() {
  mnl::Rational r1;
  mnl::Rational r2(5);
  mnl::Rational r3(3,4);
  mnl::Rational r4(r3);
  mnl::Rational r5(18,24);
  mnl::Rational r6;
  mnl::Rational r7 = {2,9};
  r2 += r1;
  r4 = r3 / r3;

  std::cout << r3 << " / " << r3 << " = " << r4 << "\n";
  std::cout << "r2 = " << r2 << "\n";
  std::string s1 = (r3 == r5) ? "true" : "false";
  std::cout << r3 << " == " << r5 << " is " << s1 << "\n";

  r6 = {3,17};
  std::cout << "r6 = " << r6 << "\n";
  return 0;
}
