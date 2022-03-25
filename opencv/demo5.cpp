#include <iostream>
#include <string>
// #include <opencv2/opencv.hpp>
using namespace std;

class MyTime{
    private:
        int hours;
        int minutes;
    public:
        MyTime(): hours(0), minutes(0) {}
        MyTime(int h, int m){
            hours = h;
            minutes = m;
        }
        // 将一个整数型的数据转为MyTime类型的数据可以利用构造函数
        MyTime(int i){
            minutes = i;
            hours = minutes / 60;
            minutes %= 60;
        }

        MyTime operator+(const MyTime &t) const{
            MyTime sum;

            sum.minutes = this->minutes + t.minutes;
            sum.hours = this->hours + t.hours;
            sum.hours += sum.minutes / 60;
            sum.minutes %= 60;

            return sum;
        }
        MyTime operator+(int m) const{
            MyTime sum;

            sum.minutes = this->minutes + m;
            sum.hours = this->hours + sum.minutes / 60;
            sum.minutes = sum.minutes % 60;

            return sum;
        }

    // 用友元函数来解决前一个操作数不是MyTime类的问题
        friend MyTime operator+(int m, const MyTime &t){
            return t+m;
        }

        friend ostream& operator<<(ostream &os, const MyTime &t){
            string str = to_string(t.hours) + " hours and "
                        + to_string(t.minutes) + " minutes.";
            os << str;

            return os;
        }

        friend istream& operator>>(istream &is, MyTime &t){
            is >> t.hours >> t.minutes;
            t.hours += t.minutes/60;
            t.minutes %= 60;

            return is;
        }

    // 对MyTime++进行重构
        MyTime& operator++(){
            this->minutes += 1;
            this->hours += this->minutes/60;
            this->minutes %= 60;

            return *this;
        }

    // 对++MyTime进行重构
        MyTime operator++(int){
            MyTime old = *this;
            this->operator++();

            return old;
        }

        string getTime() const{
            return to_string(this->hours) + " hours and "
                    +to_string(this->minutes) + " minutes.";
        }

        operator int() const{
            return this->hours * 60 + this->minutes;
        }
};

int main(){
    MyTime t1 = 59;
    // t1 = t1.operator+(5);

    MyTime t2 = t1++;
    MyTime t3 = ++t1;

    cout << "t1 is " << t1 << endl;
    cout << "t2 is " << t2 << endl;
    cout << "t3 is " << t3 << endl;

    return 0;
}