// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    // 核心演示 1：运算符表示法 (Operator notation)
    total = coding + fixing; //使用重载对+进行针对类成员的重载
    
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    // 核心演示 2：函数表示法 (Function notation)
    total = morefixing.operator+(total); //直接使用函数进行处理,说明重载本质是允许特定符号调用指定函数
    
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    return 0;
}