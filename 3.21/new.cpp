#include <iostream>

using namespace std;

int main(){
    int *p = new int[16]{1, 2, 3};

    for(int i = 0; p[i] != '\0'; i++){
        cout << "p[" << i << "] = " << p[i] << endl;
    }

    cout << p[4] << endl;

    return 0;
}