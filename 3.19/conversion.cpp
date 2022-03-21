#include <iostream>

using namespace std;

int main(){
    int num = 0x7ABCDEF0;
    float f = num;
    int num2 = (int)f;

    cout << "num = " << num << endl;
    cout << "f = " << f << endl;
    cout << "num2 = " << num2 << endl;

    return 0;
}