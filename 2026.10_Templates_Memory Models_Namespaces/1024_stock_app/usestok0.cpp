// usestok0.cpp -- the client program
// compile with stock00.cpp
#include <iostream>
#include "stock00.h"
#include <cstdlib>//用于windows系统调试,其他系统需要注释此句
int main()
{
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    system("pause");//其他系统也需要注释此句
    return 0;
}