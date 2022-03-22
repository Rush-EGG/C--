#include <iostream>

using namespace std;

int sum(int x, int y){
    return x + y;
}

float sum(float x, float y){
    return x + y;
}

long sum(long x, long y){
    return x + y;
}

// 无法重载仅按返回类型不同区分的函数
// long sum(int x, int y){
//     return x + y;
// }

int main(){
    int x = 1;
    float y = 1.1f;
    int a = 1;
    int b = 2;

    // 无法调用函数，因为传入的参数无法和任何一个重载的函数匹配
    // float z = sum(x, y);

    int z = sum(a, b);

    cout << "z = " << z << endl;

    return 0;
}