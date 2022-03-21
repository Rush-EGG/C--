#include <iostream>
#include <cstring>

using namespace std;

int main(){
    struct Student{
        char name[8];
        int born;
        bool male;
    };

    struct Student stu1;

    strcpy(stu1.name, "Lu");
    stu1.born = 2000;
    stu1.male = 1;

    // cout << stu1 << endl;
    printf("Student %s, born in %d, gender %s",
        stu1.name,
        stu1.born,
        stu1.male ? "male": "female"
    );

    return 0;
}