// refcube.cpp -- using a const reference argument
#include <iostream>

// 函数原型：参数为 const double 引用
double refcube(const double &ra);//const 引用,函数内部不能修改 ra,这可以避免修改数据的编程错误,
//并允许const函数传入const和非const实参
//同时可以绑定到临时变量（如 7.0、side + 10.0）以及不同类型的变量(如 long edge，会隐式转换为 double 临时量)

int main()
{
    using namespace std;

    double side = 3.0;
    double * pd = &side;
    double & rd = side;
    long edge = 5L;
    double lens[4] = { 2.0, 5.0, 10.0, 12.0 };

    // 多种调用方式，展示 const 引用可绑定的实参类型
    double c1 = refcube(side);          // ra is side
    double c2 = refcube(lens[2]);       // ra is lens[2]
    double c3 = refcube(rd);            // ra is rd is side
    double c4 = refcube(*pd);           // ra is *pd is side
    double c5 = refcube(edge);          //double不能指向long,生成临时匿名变量(如此系统不会更改传入值的原值)
    double c6 = refcube(7.0);           //临时变量值,允许被绑定
    double c7 = refcube(side + 10.0);   //同上

    // 输出计算结果
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    cout << "c6 = " << c6 << endl;
    cout << "c7 = " << c7 << endl;

    return 0;
}

// 函数定义：计算立方，使用 const 引用避免拷贝且不修改原值
double refcube(const double &ra)
{
    return ra * ra * ra;
}