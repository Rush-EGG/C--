#include <iostream>
#include <cstring>
using namespace std;


class Student{
    private:
        char name[20];
        int born;
        bool male;
    public:
    // 以下两个为构造函数
        Student(){
            name[0] = 0;
            born = 0;
            male = false;

            cout << "Constructor: Person()" << endl;
        }
        Student(const char* initName): born(0), male(true){
            setName(initName);

            cout << "Constructor: Person(const char*)" << endl;
        }
    // 这是一个析构函数
        ~Student(){
            cout << "To destroy object: " << name << endl;
            delete [] name;
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

int main(){
    Student Lu;
    Lu.printInfo();

    Student Li("Li");
    Li.printInfo();

    return 0;
}