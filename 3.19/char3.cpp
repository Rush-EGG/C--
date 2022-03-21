#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char name[] = "woshizhu";
    // 相较于字符串数组，string这个类自带一些函数来完成连接、比大小、查长度等操作
    // 但是string类和字符串数组一样，不会有越界检查
    std::string str1 = "Hello";

    // cout << "the length of name[] is: " << strlen(name) << endl;

    cout << str1.length() << endl;

    return 0;
}