#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
T sum(T x, T y){
    cout << "The input type is " << typeid(T).name() << endl;

    return x+y;
}

struct Point{
    int x;
    int y;
};

// 为指针Point来设置一个特例
template<>
Point sum<Point>(Point p1, Point p2)
{
    cout << "The input type is " << typeid(p1).name() << endl;

    Point pt;
    pt.x = p1.x + p2.x;
    pt.y = p1.y + p2.y;

    return pt;
}

int main(){
    Point p1{1, 2};
    Point p2{2, 3};

    Point pt = sum(p1, p2);

    cout << "pt = (" << pt.x << ", " << pt.y << ")" << endl;

    return 0;
}