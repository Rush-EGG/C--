#include <iostream>
#include <cstring>
using namespace std;

class Student{
    private:
        char name[20];
        int born;
        bool male;
    public:
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

        void becamePig();
};

int main(){
    Student Lu;

    Lu.setName("LuZhongtian");
    Lu.setBorn(2000);
    Lu.setMale(1);

    Lu.printInfo();

    Lu.becamePig();

    return 0;
}

void Student::becamePig(){
    cout << name << " becomes a Pig.\nHaha!" << endl;
}