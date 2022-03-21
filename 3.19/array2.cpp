#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char name[16] = {'T', 'i', 'b', 'o'};
    
    cout << "the length of name[] is:" << strlen(name) << endl;

    for(int i = 0; i < 16; i ++){
        cout << i << ":" << +name[i] << "(" << name[i] << ")" << endl;
    }

    char bad_name[5] = {'T', 'i', 'b', 'o', '\0'};
    cout <<"the bad_name[] is: " << "("<<bad_name << ")" << endl;

}