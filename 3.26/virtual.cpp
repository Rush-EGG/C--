#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        string name;
        Person(string n): name(n){}
        // 虚函数：使变量调用函数时是动态绑定的
        virtual void print(){
            cout << "Name: " << name << endl;
        }
};

class Person2{
    // 这种类一般不会有相关的变量
    // 因为这里面的print函数是一个纯的虚函数，没法被调用
    // 只是用来给子函数提供接口的
    public:
        string name;
        Person2(string n): name(n){}
        virtual void print() = 0;
};

class Student: public Person{
    public:
        string id;
        Student(string n, string i = "0"): Person(n), id(i){}
        void print(){
            cout << "Name: " << name;
            cout << ". ID: " << id << endl;
        }
};

void printObjectInfo(Person& p){
    p.print();
}

int main(){
    {
        Student stu("Lu", "20182109");
        printObjectInfo(stu);
    }

    {
        Person* p = new Student("Zhong", "20182100");
        p->print();
        delete p;
    }

    return 0;
}