#include <iostream>
#include <cmath>

int main()
{
    // 右值引用绑定到临时值（std::sqrt 返回临时结果）
    double && rref = std::sqrt(36.00);   // not allowed for double &
    
    double j = 15.0;
    
    // 右值引用绑定到表达式产生的临时值
    //右值引用可以获取临时值,并允许对其修改
    double && jref = 2.0 * j + 18.5;     // not allowed for double &
    
    std::cout << rref << '\n';           // display 6.0
    std::cout << jref << '\n';           // display 48.5
    
    return 0;
}