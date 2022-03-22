#include <iostream>

using namespace std;

int main(){
    int num = 0;

    // 相较于指针，引用更加安全，因为在定义一个引用时，必须为它赋初值
    int *p = &num;
    int &num_ref = num;

    cout << "p = " << p << endl;
    cout << "num_ref = " << &num_ref << endl;
    // cout << "pig" << endl;

}