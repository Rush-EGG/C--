#include <iostream>
using namespace std;

// 定义一个类模板
template<typename T>
class Mat{
    size_t rows;
    size_t cols;
    T* data;

    public:
        Mat(size_t r, size_t c): rows(r), cols(c){
            data = new T[r * c * sizeof(T)]{};
        }
        ~Mat(){
            delete []data;
        }

        Mat(const Mat&) = delete;
        Mat& operator=(const Mat&) = delete;

        T getElement(size_t r, size_t c);
        bool setElemet(size_t r, size_t c, T value);
};

template<typename T>
T Mat<T>::getElement(size_t r, size_t c){
    if(r >= this->rows || c >= this->cols){
        cerr << "Indices are out of range!" << endl;
        return 0;
    }

    return data[this->cols*r + c];
}

template<typename T>
bool Mat<T>::setElemet(size_t r, size_t c, T value){
    if(r >= this->rows || c >= this->cols){
        cerr << "Indices are out of range!" << endl;
        return false;
    }
    data[this->cols*r + c] = value;

    return true;
}

// 实例化一个int类型的Mat
template class Mat<int>;

int main(){
    Mat<int> imat(2, 3);
    Mat<double> dmat(4, 5);
    Mat<float> fmat(5, 8);

    imat.setElemet(0, 0, 100);
    dmat.setElemet(3, 3, 2.36598741);

    cout << dmat.getElement(3, 3) << endl;
    // cout << fmat.getElement(0, 0) << endl;

    return 0;
}