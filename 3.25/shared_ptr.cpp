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
    // shared_ptr<MyTime> mt0 = new MyTime(0, 20); //Error
    // MyTime m1(20);
    // cout << m1 << endl;

    shared_ptr<MyTime> mt1(new MyTime(10));
    cout << *mt1 << endl;

    shared_ptr<MyTime> mt2 = mt1;
    shared_ptr<MyTime> mt3 = mt1;

    cout << "use_count() = " << mt1.use_count() << endl;

    {
        auto mt4 = mt3;
        *mt4 = *mt4 + 50;
        cout << "use_count() = " << mt1.use_count() << endl;
    }

    cout << "mt3: " << *mt3 << endl;
    cout << "use_count() = " << mt1.use_count() << endl;

    return 0;
}