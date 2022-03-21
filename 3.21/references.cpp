#include <iostream>

using namespace std;

int main(){
    int num = 0;

    int *p = &num;
    int &num_ref = num;

    cout << "p = " << p << endl;
    cout << "num_ref = " << &num_ref << endl;

}