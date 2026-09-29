// swaps.cpp -- swapping with references and with pointers
#include <iostream>

void swapr(int & a, int & b);    // a, b are aliases for ints
void swap(int * p, int * q);    // p, q are addresses of ints
void swapv(int a, int b);       // a, b are new variables

int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);    // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swap(&wallet1, &wallet2);   // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);    // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    return 0;
}

void swapr(int & a, int & b)    // use references
{
    int temp;

    temp = a;       //引用,可以修改原值
    a = b;
    b = temp;
}

void swap(int * p, int * q)    // use pointers
{
    int temp;

    temp = *p;      //指针,可以修改原值
    *p = *q;        //需要解引用,另外两个不需要
    *q = temp;
}

void swapv(int a, int b)        // try using values
{
    int temp;

    temp = a;       //按值传递,原值的拷贝进入函数,修改对原值无效
    a = b;
    b = temp;
}