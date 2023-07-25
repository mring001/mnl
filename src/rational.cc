/*
 rational.cc
*/
#include "mnl/rational.h"
#include <cmath>
#include <stdexcept>

namespace mnl {

// Input: positive integers a,b with a <= b
// Output: greatest common denominator of a & b
int gcd( int a, int b ) {
  if( b == 0 ) {
    return a;
  }
  else {
    return gcd( b, a % b );
  }
}

// Result: Rational is in has no common factors in numerator and
//         denominator and denominator is not negative
void Rational::simplify() {
  int a = std::abs( _numerator );
  int b = std::abs( _denominator );
  int c;

  if( _denominator < 0 ) {
    _denominator *= -1;
    _numerator *= -1;
  }
  if( a < b ) {
    c = gcd( a, b );
  }
  else {
    c = gcd( b, a );
  }

  _numerator /= c;
  _denominator /= c;
}

Rational::Rational() : _numerator{0}, _denominator{1} {
}

Rational::Rational( int n ) : _numerator{n}, _denominator{1} {
}

Rational::Rational( int n, int d ) {
  if( d == 0 ) {
    throw std::runtime_error("Math error: Rational number with zero denominator");
  }
  if( d < 0 ) {
    n *= -1;
    d *= -1;
  }
  _numerator = n;
  _denominator = d;
}

Rational::Rational( int r[2] ) {
  if( r[1] == 0 ) {
    throw std::runtime_error("Math error: Rational number with zero denominator");
  }
  if( r[1] < 0 ) {
    r[0] *= -1;
    r[1] *= -1;
  }
  _numerator = r[0];
  _denominator = r[1];
}

Rational::Rational( const Rational& r ) : _numerator{r._numerator}, _denominator{r._denominator} {
}

Rational Rational::operator-() {
  Rational retVal(-_numerator, _denominator);
  return retVal;
}

Rational Rational::operator+( const Rational& r ) {
  Rational retVal;
  retVal._numerator = (_numerator * r._denominator) + (_denominator * r._numerator);
  retVal._denominator = _denominator * r._denominator;
  retVal.simplify();
  return retVal;
}

void Rational::operator+=( const Rational& r ) {
  _numerator = (_numerator * r._denominator) + (_denominator * r._numerator);
  _denominator *= r._denominator;
  simplify();
}

Rational Rational::operator-( const Rational& r ) {
  Rational retVal;
  retVal._numerator = (_numerator * r._denominator) - (_denominator * r._numerator);
  retVal._denominator = _denominator * r._denominator;
  retVal.simplify();
  return retVal;
}

void Rational::operator-=( const Rational& r ) {
  _numerator = (_numerator * r._denominator) - (_denominator * r._numerator);
  _denominator *= r._denominator;
  simplify();
}

Rational Rational::operator*( const Rational& r ) {
  Rational retVal;
  retVal._numerator = _numerator * r._numerator;
  retVal._denominator = _denominator * r._denominator;
  retVal.simplify();
  return retVal;
}

void Rational::operator*=( const Rational& r ) {
  _numerator *= r._numerator;
  _denominator *= r._denominator;
  simplify();
}

Rational Rational::operator/( const Rational& r ) {
  if( r._numerator == 0 ) {
    throw std::runtime_error("Math error: Attempt to divide by zero");
  }
  Rational retVal;
  retVal._numerator = _numerator * r._denominator;
  retVal._denominator = _denominator * r._numerator;
  retVal.simplify();
  return retVal;
}

void Rational::operator/=( const Rational& r ) {
  if( r._numerator == 0 ) {
    throw std::runtime_error("Math error: Attempt to divide by zero");
  }
  _numerator *= r._denominator;
  _denominator *= r._numerator;
  simplify();
}

bool Rational::operator==( const Rational& r ) {
  return (_numerator * r._denominator == _denominator * r._numerator);
}

bool Rational::operator!=( const Rational& r ) {
  return (_numerator * r._denominator != _denominator * r._numerator);
}

void Rational::operator=( const int i[2] ){
  if( i[1] == 0 ) {
    throw std::runtime_error("Math error: Rational number with zero denominator");
  }
  _numerator = i[0];
  _denominator = i[1];
  simplify();
}

double Rational::toDouble() {
  return (double)_numerator / _denominator;
}

} // namespace mnl
