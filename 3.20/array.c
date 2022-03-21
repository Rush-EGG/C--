#include <stdio.h>

struct Student{
    char name[8];
    int born;
    char gender;
    char class_num0;
    char class_num1;
    char class_num2;
    // char class_num3;
};

int main(){
    struct Student students[100];
    char a = ';';

    struct Student *p1 = &students[0];
    struct Student *p2 = &students[1];

    p1->born = 2000;

    printf("%d\n", sizeof(a));
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);

    return 0;
}