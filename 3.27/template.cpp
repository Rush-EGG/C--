#include <iostream>
using namespace std;

class intMat{
    int rows;
    int cols;
    int* data;

    public:
        intMat(size_t rows, size_t cols): rows(rows), cols(cols){
            data = new int[rows * cols * sizeof(int)]{};
        }
        ~intMat(){
            delete []data;
        }

        // 本来编译器会自动提供一个默认的copy construction
        // 现在让这个默认的复制构造函数"=delete"表示我不要
        // 为的是防止内存泄漏
        intMat(const intMat&) = delete;
        intMat& operator=(const intMat&) = delete;

        int getElement(size_t r, size_t c);
        bool setElement(size_t r, size_t c, int value);
};
int intMat::getElement(size_t r, size_t c){
    if(r >= this->rows || c >= this->cols){
        cerr << "Indices are out of range!" << endl;
        return 0;
    }

    return data[this->cols*r + c];
}
bool intMat::setElement(size_t r, size_t c, int value){
    if(r >= this->rows || c >= this->cols){
        cerr << "Indices are out of range!" << endl;
        return false;
    }
    data[this->cols*r + c] = value;

    return true;
}

int main(){
    intMat imat(3, 4);
    imat.setElement(1, 2, 256);
    // imat.setElement(3, 5, 255);

    cout << imat.getElement(1, 2) << endl;

    return 0;
}