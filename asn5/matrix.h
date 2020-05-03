//
// Created by MingCong Zhou on 11/28/2018.
//

#ifndef ASSIGNMENT_MATRIX_H
#define ASSIGNMENT_MATRIX_H
typedef BStree Matrix;
typedef char* Index;
typedef int Value;

Matrix matrix_construction(void);
unsigned char matrix_isin(Matrix m, Index index1, Index index2);
Value *matrix_get(Matrix m, Index index1, Index index2);
void matrix_set(Matrix m, Index index1, Index index2, Value value);
void matrix_inc(Matrix m, Index index1, Index index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);
#endif //ASSIGNMENT_MATRIX_H
