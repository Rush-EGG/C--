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

        string getTime() const{
            return to_string(this->hours) + " hours and "
                    +to_string(this->minutes) + " minutes.";
        }
};

int main(){
    // string s("Hello");
    MyTime t1(2, 40);
    MyTime t2(1, 30);

    cout << (t1+t2).getTime() << endl;

    cout << (t1+20).getTime() << endl;

    return 0;
}