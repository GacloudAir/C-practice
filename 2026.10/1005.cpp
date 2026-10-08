// funtemp.cpp -- using a function template
#include <iostream>
// function template prototype
template <typename T>  // or class T
void Swap(T &a, T &b);//函数模板,会自动根据实际参数确定函数类型

int main()
{
    using namespace std;

    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i,j);  // 创建Swap(&int a,&int b)并执行
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x,y);  // 创建Swap(&double a,&double b)并执行
    cout << "Now x, y = " << x << ", " << y << ".\n";
    // cin.get();
    return 0;
}

//函数模板在下方定义
template <typename T>  // =<class T>
void Swap(T &a, T &b)
{
    T temp;   //T会在传参时被替换为变量类型,从而快速创造出新模板
    temp = a;
    a = b;
    b = temp;//a,b替换
}