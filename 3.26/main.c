#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix* matA = createMat(2, 3);
    Matrix* matB = createMat(2, 3);
    Matrix* matC = createMat(2, 3);
    Matrix* matD = createMat(3, 2);
    Matrix* matnull = NULL;

    matA->data[3] = 2.3f;
    matB->data[3] = 5.8f;

    if(!add(matA, matB, matC)){
        fprintf(stderr, "Matrix addition failed!\n");
    }else{
        printf("result = %f\n", matC->data[3]);
    }

    add(matD, matA, matC);

    add(matnull, matA, matB);

    return 0;
}