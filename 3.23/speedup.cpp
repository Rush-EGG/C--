#include <iostream>
#include <omp.h>
using namespace std;

int main(){
    int a[100], b[100], c[100];

    #pragma omp parallel for
    for(size_t i = 0; i < 100; i ++){
        a[i] = i;
    }
    #pragma omp parallel for
    for(size_t i = 0; i < 100; i ++){
        b[i] = i;
    }
    
    #pragma omp parallel for
    for(size_t i = 0; i < 100; i ++){
        c[i] = b[i] + a[i];
    }

    

    return 0;
}