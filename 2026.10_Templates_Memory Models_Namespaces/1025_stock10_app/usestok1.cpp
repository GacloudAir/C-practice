// usestok1.cpp -- using the Stock class
// compile with stock10.cpp
#include <iostream>
#include "stock10.h"

int main()
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);            //直接构造方式,可能会创建临时对象,如果可行应如果可行应优先使用此方案
        stock1.show();
        Stock stock2 = Stock ("Boffo Objects", 2, 2.0); //拷贝构造方式,创建临时对象并复制,若使用explicit禁用隐式转换则不可用
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);        //创建一个无名的临时对象并赋值给stock1
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    }//额外添加一个括号,使得stock1和stock2的存续期略短于整个main,可以看到析构函数的作用
    //自动变量/对象被存放与栈中,因此会出现先创建的对象后被删除的现象
    return 0;
}
//此外,对于成员函数,若对象使用const修饰,则不能调用非const成员函数,这时需要使用void Stock::show() const做出不修改对象的保证