/*
 rational.h
*/
#ifndef MNL_RATIONAL_H
#define MNL_RATIONAL_H

#include <iostream>

namespace mnl {

namespace core {

class Rational {
public:
Rational();
Rational( int n );
Rational( int n, int d );
Rational( int r[2] );
Rational( const Rational& r );

void simplify();

Rational operator-();
Rational operator+( const Rational& r );
void     operator+=( const Rational& r );
Rational operator-( const Rational& r );
void     operator-=( const Rational& r );
Rational operator*( const Rational& r );
void     operator*=( const Rational& r );
Rational operator/( const Rational& r );
void     operator/=( const Rational& r );
bool     operator==( const Rational& r );
bool     operator!=( const Rational& r );
void     operator=( const int i[2] );
void     operator=( int i );
double   toDouble();

friend std::ostream &operator<<( std::ostream &output, const Rational &r ) {
  output << r._numerator;

  if( r._denominator != 1 && r._numerator != 0 ) {
    output << "/" << r._denominator;
  }
  return output;
}

private:
  int _numerator;
  int _denominator;
}; // class Rational

} // namespace core

} // namespace mnl

#endif // MNL_RATIONAL_H
