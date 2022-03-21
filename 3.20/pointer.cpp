#include <iostream>

using namespace std;

int main(){
    int* p1 = NULL;
    int num = 10;

    p1 = &num;
    *p1 = 20;

    cout << num << endl;

    return 0;
}