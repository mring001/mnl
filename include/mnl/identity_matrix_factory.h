/*
 identity_matrix_factory.h
*/
#ifndef IDENTITY_MATRIX_FACTORY_H
#define IDENTITY_MATRIX_FACTORY_H

#include "mnl/matrix.h"

namespace mnl {

template<class T>
class IdentityMatrixFactory {
public:

template<int X>
static Matrix<T,X,X> create() {
  Matrix<T,X,X> retVal;
  for( int i = 0; i < X; i++ ) {
    for( int j = 0; j < X; j++ ) {
      if( i == j ) {
        retVal(i,j) = 1;
      }
      else {
        retVal(i,j) = 0;
      }
    }
  }
  return retVal;
}

private:

}; // class IdentityMatrixFactory

} // namespace mnl

#endif // IDENTITY_MATRIX_FACTORY_H