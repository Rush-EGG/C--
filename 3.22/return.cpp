#include <iostream>
#include <cmath>

using namespace std;

float norm(float x, float y, float z = 0){
    return sqrt(x*x + y*y + z*z);
}

int main(){
    cout << norm(3.f, 4.f, 5.f) << endl;

    return 0;
}