// usestok2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "stock20.h"

const int STKS = 4;
int main()
{
//创建一个四对象数组,并且为每个对象都调用了构造函数
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();//数组中每个对象都可以使用定义中的完整成员函数

//声明const指针,其可读取数组中的对象
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);

//最终top将指向对象数组中的最大值
    std::cout << "\nMost valuable holding:\n";
    top->show();
    return 0;
}