#include <iostream>

using namespace std;

int main(){
    float f1 = 2.0f / 0.0f;
    float f2 = 0.0f / 0.0f;

    // f1会输出为inf，即无穷大
    // f2会输出为nan，即这不是一个可定义的数
    cout << "f1 = "<< f1 << endl;
    cout << "f2 = " << f2 << endl;
}