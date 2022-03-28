#include <iostream>
#include <cmath>
#include <float.h>
using namespace std;

float ratio(float a, float b){
    if(fabs(a+b) < FLT_EPSILON){
        throw "Error! The sum of two arguments are too close!!";
    }

    return (a-b)/(a+b);
}

int main(){
    float a = 1.11111111111111111112;
    float b = -1.11111111111111111119;
    float z;

    try{
        z = ratio(a, b);
        cout << z << endl;
    }catch(const char * msg){
        cerr << "call ratio is failed..." << endl;
        cerr << msg << endl;
    }

    return 0;
}