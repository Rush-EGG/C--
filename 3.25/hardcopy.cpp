#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    int buf_len;
    char* characters;

    public:
        MyString(int buf_len = 64, const char* data = NULL){
            this->buf_len = 0;
            this->characters = NULL;
            create(buf_len, data);
        }
        MyString(const MyString& ms){
            cout << "Constructor(MyString&)" << endl;
            this->buf_len = 0;
            this->characters = NULL;
            create(ms.buf_len, ms.characters);
        }
        ~MyString(){
            delete []this->characters;
        }

        bool create(int buf_len, const char* data){
            release();

            this->buf_len = buf_len;

            if(this->buf_len != 0){
                this->characters = new char[this->buf_len]{};
                if(data){
                    strncpy(this->characters, data, this->buf_len);
                }
            }

            return true;
        }

        friend ostream& operator<<(ostream& os, const MyString& ms){
            os << "buf_len = " << ms.buf_len;
            // 下面这行用来打印输出这个结构体内字符串在内存存的位置
            os << ", characters = " << static_cast<void*>(ms.characters);
            os << " [" << ms.characters << "]";

            return os;
        }

        MyString& operator=(const MyString& ms){
            // this->buf_len = ms.buf_len;
            // this->characters = ms.characters;
            create(ms.buf_len, ms.characters);

            return *this;
        }

        int release(){
            this->buf_len = 0;
            if(this->characters != NULL){
                delete []this->characters;
                this->characters = NULL;
            }

            return 0;
        }
};

int main(){
    MyString str1(10, "Shenzhen");
    cout << "str1: " << str1 << endl;

    MyString str2 = str1;
    cout << "str2: " << str2 << endl;

    MyString str3;
    cout << "str3: " << str3 << endl;
    str3 = str1;
    cout << "str3: " << str3 << endl;

    return 0;
}