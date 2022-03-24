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

    // 为了能直接输出MyTime类型而对<<函数做的友元改变
    /***
     * friend表示友元
     * ostream &表示返回类型为一个ostream的引用
     * operator <<表示是对<<这个运算符做修改
     * */
        friend ostream &operator <<(ostream &os, const MyTime &t){
            string str = to_string(t.hours) + " hours and "
                        + to_string(t.minutes) + " minutes.";
            os << str;

            return os;
        }

    // 为了能直接把接收到的两个整型数转为MyTime类型的数据而对>>函数做的友元变换
        friend istream &operator >>(istream &is, MyTime &t){
            is >> t.hours >> t.minutes;
            t.hours += t.minutes/60;
            t.minutes %= 60;

            return is;
        }

        string getTime() const{
            return to_string(this->hours) + " hours and "
                    +to_string(this->minutes) + " minutes.";
        }
};

int main(){
    MyTime t1(2, 40);
    MyTime t2 (0, 0);

    cout << t1 << endl;

    cout << "Please input two integers for hours and minutes: " << endl;
    cin >> t2;
    cout << t2 << endl;

    return 0;
}