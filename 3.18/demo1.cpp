#include <iostream>
#include <vector>
#include <string>

//表示现在用的是std这个命名空间
//在std这个命名空间中，cout是用来输出的
using namespace std;

int main(){
    vector<string> msg{"Hello", "C++", "World", "!"};

    for (const string& word : msg){
        cout << word << " ";

    }
    cout << endl;
}
