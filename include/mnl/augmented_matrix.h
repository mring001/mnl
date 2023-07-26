/*
 augmented_matrix.h
*/
#ifndef AUGMENTED_MATRIX_H
#define AUGMENTED_MATRIX_H

namespace mnl {

template<class T, int X, int Y, int Z>
class AugmentedMatrix {
public:
const int rows = X;
const int leftCols = Y;
const int rightCols = Z;

AugmentedMatrix( Matrix<T,X,Y> l, Matrix<T,X,Z> r ) :
   _left{l}, _right{r} {
}

private:
  Matrix<T,X,Y> _left;
  Matrix<T,X,Z> _right;
}; // class AugmentedMatrix

} // namespace mnl

#endif // AUGMENTED_MATRIX_H
