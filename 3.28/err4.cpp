#include <iostream>
#include <cmath>
#include <float.h>
using namespace std;

float ratio(float a, float b){
    if(a < 0){
        throw 1;
    }else if(b < 0){
        throw 2;
    }else if(fabs(a+b) < FLT_EPSILON){
        throw "Error!";
    }

    return (a-b) / (a+b);
}

int main(){
    float a = 0.f;
    float b = 0.f;
    float c = 0.f;

    cout << "Please input two numbers <q to quit>:";
    while(cin >> a >> b){
        try{
            c = ratio(a, b);
            cout << c << endl;
        }catch(const char* msg){
            cerr << "Call ratio() failed!!! " << msg << endl;
        }catch(int eid){
            if(eid == 1){
                cerr << "The first argument should be positive" << endl;
            }else if(eid == 2){
                cerr << "The second argument should be positive" << endl;
            }else{
                cerr << "The unknown error_id!" << endl;
            }
        }
        cout << "Please input two numbers <q to quit>:";
    }

    cout << "Bye!" << endl;

    return 0;
}