// twoswap.cpp -- specialization overrides a template
#include <iostream>

template <typename T>
void Swap(T &a, T &b);

struct job
{
    char name[40];
    double salary;
    int floor;
};

template <> void Swap<job>(job &j1, job &j2);//显式具体化实例,针对job这一结构体使用不同于函数模板的处理代码,实现定制化行为
void Show(job &j);

int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i,j);      // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney); // uses void Swap(job &, job &)
    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T &a, T &b)    //模板版本
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure
template <>/*这个尖括号是显式具体化的标志*/ void Swap<job>(job &j1, job &j2)  
//显式具体化的特性版本,可以避开通用模板处理结构体等的额外开销和错误风险
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
         << " on floor " << j.floor << endl;
}//相对于具体化,另一个词是实例化,这是为函数模板所需处理的对象--具有通性的同类对象准备的行为,而具体化是为处理具有特性的部分对象准备的
//除了上述显式实例化的方式,还有一种方案是隐式实例化,在函数模板处理对象时,编译器会根据对象类型写出对应代码,这便是隐式实例化过程
//也可以使用其他的显式实例化方式,如template void  Swap<int>(int ,int);

/*实例化与具体化代码对比
template <typename T> void f(T);	    通用模板定义	正常模板参数
template void f<int>(int);	            显式实例化	    template 后直接跟函数，无 <>
template <> void f<int>(int);	        显式具体化	    template <> 空尖括号
template <typename T> void f(T*);	    函数模板重载	仍是模板，不是具体化
template <typename T> class C<T*>;	    类模板偏特化	模板参数仍存在，但类型被部分限定
template <> class C<int>;	            类模板全特化	template <> 空尖括号
*/