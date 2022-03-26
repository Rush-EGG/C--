#include <iostream>
using namespace std;

class Base{
    public:
        int a;
        int b;
        Base(int a = 0, int b = 0){
            this->a = a;
            this->b = b;
            cout << "Constructor Base::Base(" << a << ", " << b << ")" << endl;
        }
        ~Base(){
            cout << "Destruction Base::~Base()" << endl;
        }

        int product(){
            return a*b;
        }
        friend ostream& operator<<(ostream& os, const Base& obj){
            os << "Base: a = " << obj.a << ", b = " << obj.b;
            return os;
        }
};

class Derived: public Base{
    public:
        int c;
        // 这个构造函数表明调用父类Base的构造函数，并传入参数c-2, c-1
        // 再把c初始化为c
        // 再在构造函数内部对a加3
        Derived(int c): Base(c-2, c-1), c(c){
            this->a += 3;
            cout << "Constructor Derived::Derived(" << c << ")" << endl;
        }
        ~Derived(){
            cout << "Destruction Derived::~Derived()" << endl;
        }

        int product(){
            return Base::product() * c;
        }
        friend ostream& operator<<(ostream& os, const Derived& obj){
            // static_cast<const Base&>(obj)表示把obj强制转换为父类
            os << static_cast<const Base&>(obj) << endl;

            os << "Derived: c = " << obj.c;
            return os;
        }
};

int main(){
    {
        Base base(1, 2);
        cout << base << endl;
    }
    cout << "--------------------" << endl;
    {
        Derived derived(10);
        cout << derived << endl;
        cout << "Product = " << derived.product() << endl;
    }

    return 0;
}