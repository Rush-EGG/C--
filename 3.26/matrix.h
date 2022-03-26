#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdbool.h> //for bool

typedef struct Matrix_{
    size_t rows;
    size_t cols;
    float* data;
} Matrix;

Matrix* createMat(size_t rows, size_t cols);
bool releaseMat(Matrix* p);
bool add(const Matrix* input1, const Matrix* input2, Matrix* output);

#endif