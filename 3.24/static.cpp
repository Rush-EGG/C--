#include <iostream>
#include <cstring>
using namespace std;


class Student{
    private:
        char * name;
        int born;
        bool male;
        // static size_t total;如果像这样定义，那么就要在Student类外去写total的初值
        inline static size_t total = 0;// 如果说明了total这个变量是inline的，那么可以在类内定义
    public:
    // 以下两个为构造函数
        Student(){
            name = new char[1024]{0};
            born = 0;
            male = false;

            cout << "Constructor: Person()" << endl;
            
            total ++;
            cout << "The total of students is " << total << endl;
        }
        Student(const char* initName): born(0), male(true){
            name = new char[1024];
            setName(initName);

            cout << "Constructor: Person(const char*)" << endl;

            total ++;
            cout << "The total of students is " << total << endl;
        }
    // 这是一个析构函数
        ~Student(){
            cout << "To destroy object: " << name << endl;
            delete []name;

            total--;
            cout << "The total of students is " << total << endl;
        }

    // 以下为Student类内的方法
        static size_t getTotal(){
            return total;
        }
        void setName(const char *s){
            strncpy(name, s, 1024);
        }
        void setBorn(int b){
            born = b;
        }
        void setMale(bool m){
            male = m;
        }
        void printInfo(){
            cout << "Name: " << name << endl;
            cout << "Born in : " << born << endl;
            cout << "Gender: " << (male ? "Male" : "Female") << endl;
        }
};

// size_t Student::total = 0;

int main(){
    Student Lu;
    Lu.setName("LuZhongtian");

    Student Liu("Liu");

    return 0;
}