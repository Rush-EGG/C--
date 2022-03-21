#include <iostream>

using namespace std;

enum color {WHITE, BLACK, RED, GREEN, BLUE, YELLOW, BROWN, NUM_COLORS};
enum datatype {TYPE_INT8 = 1, TYPE_INT16 = 2, TYPE_INT32 = 4, TYPE_INT64 = 8};

struct Point{
    enum datatype type;
    union{
        std::int8_t data8[3];
        std::int16_t data16[3];
        std::int32_t data32[3];
        std::int64_t data64[3];
    };
};

size_t datawidth(struct Point pt){
    return size_t(pt.type * 3);
}

int64_t l1norm(struct Point pt){
    int64_t result = 0;
    switch (pt.type)
    {
    case TYPE_INT8:
        result = abs(pt.data8[0]) + abs(pt.data8[1]) + abs(pt.data8[2]);
        break;
        
    case TYPE_INT16:
        result = abs(pt.data16[0]) + abs(pt.data16[1]) + abs(pt.data16[2]);
        break;

    case TYPE_INT32:
        result = abs(pt.data32[0]) + abs(pt.data32[1]) + abs(pt.data32[2]);
        break;

    case TYPE_INT64:
        result = abs(pt.data64[0]) + abs(pt.data64[1]) + abs(pt.data64[2]);
        break;
    }

    return result;
}

int main(){
    // color pen_color = RED;
    enum color pen_color;
    // pen_color = color(3);

    // int i = color::BLACK;

    // cout << pen_color << endl;

    // cout << "We have " << NUM_COLORS << " pens." << endl;

    struct Point pt1 = {.type=TYPE_INT8, .data8={-1, 3, 4}};
    struct Point pt2 = {.type=TYPE_INT32, .data32={1, 2, 3}};

    cout << datawidth(pt1) << endl;
    cout << datawidth(pt2) << endl;

    cout << "The l1norm of pt1 is: " << l1norm(pt1) << endl;
    cout << "The l1norm of pt2 is: " << l1norm(pt2) << endl;

    return 0;

}