#include <iostream>
using namespace std;

int main(){
    size_t length = 800000000L;
    int* p = NULL;

    try{
        cout << "Trying to allocate a big block of memeory" << endl;
        // p = new int[length];
        p = new(nothrow) int[length];
        cout << "No exception." << endl;
    }catch(bad_alloc & ba){
        cout << "bad_alloc exception!" << endl;
        cout << ba.what() << endl;
    }

    if(p){
        cout << "Memory successfully allocated!" << endl;
    }else{
        cout << "So bad, null pointer." << endl;
    }

    if(p){
        delete []p;
    }

    return 0;
}