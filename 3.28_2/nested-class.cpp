#include <iostream>
#include <string>
using namespace std;

class Storage{
    public:
        class Fruit{
            string name;
            int weight;
            public:
                Fruit(string name="", int weight=0):name(name), weight(weight){}
                string getInfo(){
                    return name + ", weight " + to_string(weight) + "kg.";
                }
        };
    private:
        Fruit fruit;
    public:
        Storage(Fruit f){
            this->fruit = f;
        }
        void print(){
            cout << fruit.getInfo() << endl;
        }
};

int main(){
    Storage::Fruit a("apple", 10);
    Storage mystorage(a);

    mystorage.print();

    return 0;
}