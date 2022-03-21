#include <iostream>

using namespace std;

union ipv4addr{
    std::uint32_t address32;
    std::uint8_t address8[4];
};

int main(){
    ipv4addr ip;

    ip.address8[3] = 172;
    ip.address8[2] = 0;
    ip.address8[1] = 0;
    ip.address8[0] = 1;

    cout << "ip: " << +ip.address8[3] << "." 
    << +ip.address8[2] << "." 
    << +ip.address8[1] << "." 
    << +ip.address8[0] << endl;

    cout << std::hex; // 使之后的输出都为16进制
    cout <<"in hex " << ip.address32 << endl;

    // cout << "(" << ip.address8[0] << ")" << endl;

    return 0;
}