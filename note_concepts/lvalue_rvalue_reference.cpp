#include <iostream>
using namespace std;

void f(int& x)  { cout << "左值引用\n"; }
void f(int&& x) { cout << "右值引用\n"; }

int main()
{
    int a = 10;
    f(a);              // 输出：左值引用
    f(20);             // 输出：右值引用
    f(a + 1);          // 输出：右值引用
    f(std::move(a));   // 输出：右值引用
    return 0;
}//左值是被提前定义,有明确地址的值.如声明的变量,数组中的某个值;右值是临时得出的,存在于临时地址中的值.如表达式结果,函数返回值,硬编码值.

