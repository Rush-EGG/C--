#include <iostream>
#include <float.h>
#include <math.h>

using namespace std;

int main(){
    float f1 = 2.34E+10f;
    float f2 = f1 + 5;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    if(fabs(f1-f2) < FLT_EPSILON){
        cout << "不相等" << endl;
    }
}