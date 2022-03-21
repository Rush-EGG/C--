#include <iostream>

using namespace std;

int main(){
    int *p = NULL;

    for(int i = 0; i< 1024; i ++){
        p = (int *) malloc(1024*1024*1024);
    }

    printf("END\n");

    return 0;
}