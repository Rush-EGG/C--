#include <iostream>
using namespace std;

void div2(int n){
    if(n % 2 != 0){
        cerr << "Error: The input must be an even number. Here it's " 
        << n << "." << endl;
    }else{
        int res = n / 2;
        cout << "Info: The result is " << res << "." << endl;
    }
    
    return;
}

int main(){
    for(int i = -5; i <= 5; i ++){
        div2(i);
    }

    return 0;
}
