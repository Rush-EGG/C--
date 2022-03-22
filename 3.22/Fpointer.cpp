#include <iostream>
#include <cmath>
using namespace std;

float norm_1(float x, float y);
float norm_2(float x, float y);
float (*norm_ptr)(float x, float y);

int main(){
    norm_ptr = norm_1;
    cout << "norm_1 of (-3, 4) = " << norm_ptr(-3.f, 4.f) << endl;

    norm_ptr = &norm_2;
    cout << "norm_2 of (-3, 4) = " << (*norm_ptr)(-3.f, 4.f) << endl;

    // float len1 = norm_ptr(-3.f, 4.f);
    // float len2 = (*norm_ptr)(-3.f, 4.f);

    return 0;
}

float norm_1(float x, float y){
    return fabs(x) + fabs(y);
}

float norm_2(float x, float y){
    return sqrt(x*x + y*y);
}