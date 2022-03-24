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

        friend ostream &operator<<(ostream &os, const MyTime &t){
            string str = to_string(t.hours) + " hours and "
                        + to_string(t.minutes) + " minutes.";
            os << str;

            return os;
        }

        friend istream &operator>>(istream &is, MyTime &t){
            is >> t.hours >> t.minutes;
            t.hours += t.minutes/60;
            t.minutes %= 60;

            return is;
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
    MyTime t1 = 101;

    cout << t1 << endl;

    return 0;
}