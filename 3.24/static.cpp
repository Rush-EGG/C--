#include <iostream>
#include <cstring>
using namespace std;


class Student{
    private:
        char name[20];
        int born;
        bool male;
        static size_t total;// 在这里只是一个定义，赋值应该放到外面去
    public:
    // 以下两个为构造函数
        Student(){
            name[0] = 0;
            born = 0;
            male = false;

            cout << "Constructor: Person()" << endl;
            
            total ++;
            cout << "The total of students is " << total << endl;
        }
        Student(const char* initName): born(0), male(true){
            setName(initName);

            cout << "Constructor: Person(const char*)" << endl;

            total ++;
            cout << "The total of students is " << total << endl;
        }
    // 这是一个析构函数
        ~Student(){
            cout << "To destroy object: " << name << endl;

            total--;
            cout << "The total of students is " << total << endl;
        }

        static size_t getTotal(){
            return total;
        }

        void setName(const char *s){
            strncpy(name, s, sizeof(name));
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

size_t Student::total = 0;

int main(){
    Student Lu;
    Lu.setName("LuZhongtian");

    Student Liu("Liu");

    return 0;
}