#include <iostream>
#include <float.h>

using namespace std;

struct Matrix{
    int rows;
    int cols;
    float* pData;
};

int main(){
    Matrix matA = {3, 4, new float[matA.rows * matA.cols]{1.f, 2.f, 3.f, 4.f}};
    // matA.pData = new float[matA.rows * matA.cols]{1.f, 2.f, 3.f};
    float maxa = FLT_MIN;

    for(int r = 0; r < matA.rows; r ++){
        for(int c = 0; c < matA.cols; c ++){
            int value = matA.pData[r*matA.rows + c];
            maxa = maxa > value ? maxa : value;
        }
    }

    cout << "the max of matA is " << maxa << endl;

    return 0;
    
}