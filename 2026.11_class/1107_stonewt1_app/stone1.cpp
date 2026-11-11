// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

int main()
{
    using std::cout;
    Stonewt poppins(9, 2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;       //因为目标类型是double,所以会在无显式强制转换直接触发向double的隐式转换
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";//对于一个可以转换为两种类型中的任意一种的对象，必须使用显式强制转换
    return 0;
}