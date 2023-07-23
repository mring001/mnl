/*
 rational.h
*/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace mnl {

class Rational {
public:
Rational();
Rational( int n );
Rational( int n, int d );
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

friend std::ostream &operator<<( std::ostream &output, const Rational &r ) {
  output << r._numerator;
  if( r._denominator != 1 ) {
    output << "/" << r._denominator;
  }
  return output;
}

private:
  int _numerator;
  int _denominator;
}; // class Rational

} // namespace mnl

#endif // RATIONAL_H
