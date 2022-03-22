#include <iostream>

using namespace std;

/**
 * 这里仅仅只是创建了一个模板编译器进行编译时
 * 并不会对加法产生相应的机器码，因为他不知道是int加法或是float加法还是什么
 * 但是，如果在主函数当中调用了这个模板产出的函数
 * 那么，编译器会自动根据你传入的参数的类型来为你确认这个T应该是什么
 * */

template <typename T>
T sum(T x, T y){
    cout << "The input type is " << typeid(T).name() << endl;

    return x+y;
}

// 这里实例化了两种sum
template double sum<double>(double, double);
template int sum(int, int);

int main(){
    auto val = sum(4.1, 5.2);
    // val = sum(5, 6);

    cout << val << endl;

    // cout << "sum1 = " << sum<int>(3.1f, 4.2f) << endl;
    // cout << "sum2 = " << sum<float>(1, 3) << endl;

    return 0;
}