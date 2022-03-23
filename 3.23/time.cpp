#include <iostream>
#include <cstdlib>
#include <chrono>
#include "matoperation.hpp"
using namespace std;

// # define TIME_START start = std::chrono::steady_clock::now();
// # define TIME_END(NAME) end = std::chrono::steady_clock::now(); \
//             duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();\
//             cout<<(NAME)<<": result="<<result \
//             <<", duration = "<<duration<<"ms"<<endl;


#define TIME_START start=std::chrono::steady_clock::now();
#define TIME_END(NAME) end=std::chrono::steady_clock::now();\
             duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); \
             cout<<(NAME)<<": result= ..." \
             <<", duration = "<<duration<<"ms"<<endl;


int main(){
    const int n = 10;
    int i;
    int a[n], b[n], c[n];

    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    auto duration = 0L;

    TIME_START
    for(i = 0; i < n; i ++){
        a[i] = i+1;
        b[i] = i+1;
        c[i] = a[i] + b[i];
        cout << c[i] << endl;
    }
    TIME_END("cout")

    cout << "I am a pig" << endl;

    return 0;
}