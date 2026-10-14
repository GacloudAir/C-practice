#include <iostream>
using namespace std;

double A(int);
double (*pf)(int);//声明指向A地址的函数指针,去掉括号表示一个返回指向int的指针的函数
void B(double(*pf)(int));//声明一个需要函数指针的函数,传入的正是函数地址
int main()
{
    pf = A;//如此声明的前提是指针和函数的类型与返回值类型相同
    B(A);
    B(pf);//二者等价.
    double C;
    C = (*pf)(5);
    C = pf (5);//二者等价;
    return 0;
}