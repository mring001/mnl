/*
 matrix.h
*/
#ifndef MATRIX_H
#define MATRIX_H

#include "mnl/rational.h"
#include <iostream>

namespace mnl {

template<class T, int X, int Y>
class Matrix {
public:
const int rows = X;
const int cols = Y;

friend std::ostream &operator<<( std::ostream &output, const Matrix<T,X,Y> &m ) {
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      output << m.get(i,j) << "\t";
    }
    output << "\n";
  }
  return output;
}

Matrix<T,X,Y>(){
}

Matrix<T, X, Y>( const Matrix<T,X,Y> &m ) {
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      _values[i][j] = m._values[i][j];
    }
  }
}

Matrix<T, X, Y>( T vals[X][Y] ) {
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      _values[i][j] = vals[i][j];
    }
  }
}

T& operator()(int i, int j) {
  return _values[i][j];
}

Matrix<T,X,Y> operator+( Matrix<T,X,Y> &m ) {
  Matrix<T,X,Y> retVal;

  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      retVal._values[i][j] = _values[i][j] + m._values[i][j];
    }
  }
  return retVal;
}

void operator+=( Matrix<T,X,Y> &m ) {
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      _values[i][j] += m._values[i][j];
    }
  }
}

Matrix<T,X,Y> operator-( Matrix<T,X,Y> &m ) {
  Matrix<T,X,Y> retVal;

  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      retVal._values[i][j] = _values[i][j] - m._values[i][j];
    }
  }
  return retVal;
}

void operator-=( Matrix<T,X,Y> &m ) {
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      _values[i][j] -= m._values[i][j];
    }
  }
}

Matrix<T,X,Y> operator=( const Matrix<T,X,Y>& m ) {
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      _values[i][j] = m.get(i,j);
    }
  }
}

template<int Z>
Matrix<T,X,Z> operator*( const Matrix<T,Y,Z>& m ) {
  Matrix<T,X,Z> retVal;

  for( int i = 0; i < Y; i++ ) {
    for( int j = 0; j < Z; j++ ) {
      retVal(i,j) = 0;
    }
  }

  for( int k = 0; k < Y; k++ ) {
    for( int i = 0; i < X; i++ ) {
      for( int j = 0; j < Z; j++ ) {
        retVal(i,j) += _values[i][k] * m.get(k,j);
      }
    }
  }
  return retVal;
}

T get(int i, int j) const {
  return _values[i][j];
}

Matrix<double,X,Y> static approximate( Matrix<Rational,X,Y> m ) {
  Matrix<double,X,Y> retVal;
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < Y; j++ ) {
      retVal(i,j) = m(i,j).toDouble();
    }
  }
  return retVal;
}

private:
  T _values[X][Y];

}; // class Matrix

} // namespace mnl

#endif // MATRIX_H
