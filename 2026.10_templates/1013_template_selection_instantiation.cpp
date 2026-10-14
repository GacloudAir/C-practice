// choices.cpp -- choosing a template
#include <iostream>

template<class T>  // or template <typename T>
T lesser(T a, T b)            // #1
{
    return a < b ? a : b;
}

int lesser (int a, int b)  // #2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;        // 编译器判定,使用模板#2
    cout << lesser(x, y) << endl;        // 编译器判定,使用模板#1
    cout << lesser<>(m, n) << endl;      // 显式指定空参数列表<>,强制使用模板函数(#1)
    cout << lesser<int>(x, y) << endl;   // 显式指定模板以及参数int,强制转换xy为int后传入模板函数
    return 0;
}