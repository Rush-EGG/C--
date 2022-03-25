#include <iostream>
#include <string>
#include <memory>
using namespace std;

class MyTime
{
    int hours;
    int minutes;
  public:
    MyTime(): hours(0), minutes(0)
    {
        std::cout << "Constructor MyTime()" << std::endl;
    }
    MyTime(int m): hours(0), minutes(m)
    {
        std::cout << "Constructor MyTime(int)" << std::endl;
        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
    }
    MyTime(int h, int m): hours(h), minutes(m)
    {
        std::cout << "Constructor MyTime(int,int)" << std::endl;
        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
    }
    ~MyTime()
    {
        std::cout << "Destructor MyTime(). Bye!" << std::endl;
    }
    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }
    friend std::ostream & operator<<(std::ostream & os, const MyTime & t)
    {
        std::string str = std::to_string(t.hours) + " hours and " 
                        + std::to_string(t.minutes) + " minutes.";
        os << str;
        return os;
    }
};

int main(){
    unique_ptr<MyTime> mt1(new MyTime(20));

    // unique表示这个位置只能由这个指针来指
    // unique_ptr<MyTime> mt3 = mt1;// Error
    // 如果想要让一个新的指针指向这个位置，那么可以用move函数
    // 且，这个原指针会被释放掉
    unique_ptr<MyTime> mt3 = move(mt1);
    // shared_ptr<MyTime> mt3 = mt1;// Error

    cout << "mt3: " << *mt3 << endl;
    // 因为mt1被释放，所以这个指针会指向内存的任意一个位置，进程会被杀死
    // cout << "mt1: " << *mt1 << endl;// Error

    return 0;
}