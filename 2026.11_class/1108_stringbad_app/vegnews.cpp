// vegnews.cpp -- using new and delete with classes
// compile with stringbad.cpp
#include <iostream>
using std::cout;
#include "stringbad.h"

void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;//代码结束后自动释放内存*1
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;//初始化函数,＝(sailor.str＝sports.str)发生浅拷贝(传递地址),指针指向相同位置,内存被释放后,指针仍然指向对应位置
        cout << "sailor: " << sailor << endl;//*2双重释放,导致崩溃
        cout << "Assign one object to another:\n";
        StringBad knot;//创建时,申请了一块内存,指针指向该位置,num_strings++
        knot = headline1;//二者均被初始化,因此触发赋值函数.发生浅拷贝,指针不仅指向与headline1相同的位置,而且原来申请的内存被丢失,即内存泄漏
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";

    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)//没有拷贝构造函数,发生浅拷贝,函数执行完毕后,内存被释放,但指针仍然指向对应位置
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}