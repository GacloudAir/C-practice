// support.cpp -- use external variable
// compile with external.cpp
#include <iostream>
extern double warming;   //从external.cpp引用声明

// function prototypes
void update(double dt);
void local();

using std::cout;
void update(double dt)       // modifies global variable
{
    extern double warming;   //在函数中也可以进行引用声明
    warming += dt;           // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()                 // uses local variable
{
    double warming = 0.8;    //在函数内定义新变量,从而遮蔽了引用声明的变量
    cout << "Local warming = " << warming << " degrees.\n";
    // Access global variable with the
    // scope resolution operator
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}