// overload_conversion.cpp -- 演示重载解析中的标准类型转换与二义性
#include <iostream>
using namespace std;

// 重载函数集 1：演示精确匹配、整型提升、浮点提升
void show(int i)    { cout << "show(int): "    << i << endl; }
void show(double d) { cout << "show(double): " << d << endl; }

// 重载函数集 2：演示二义性（int 到 long 和 int 到 double 都是标准转换，等级相同）
void print(long l)   { cout << "print(long): "   << l << endl; }
void print(double d) { cout << "print(double): " << d << endl; }
void print(double & d) { cout << "print(double): " << d << endl; }//对于特征标某一类型及其引用的函数,将被直接视为同一函数,而不触发重载
//int print(double d) { cout << "print(double): " << d << endl; return 0; }//不允许只改变返回值不改变特征标的函数重载,但可以同时修改两者
int main()
{
    // ---------- 1. 能直接运行：精确匹配 ----------
    show(10);       // 实参 int   -> 精确匹配 show(int)
    show(3.14);     // 实参 double-> 精确匹配 show(double)

    // ---------- 2. 需要进行标准类型转换 ----------
    // char -> int 是“整型提升”（promotion），等级优于 char -> double 的“转换”（conversion）
    show('A');      // 输出 show(int): 65

    // float -> double 是“浮点提升”（promotion），等级优于 float -> int 的“转换”
    show(2.5f);     // 输出 show(double): 2.5

    // ---------- 3. 二义性错误示例（取消注释将编译失败） ----------
    // print(10);   // 错误：int -> long 和 int -> double 都是标准转换，发生歧义，编译器无法抉择而报错
    // 正确做法是提供精确类型，或只保留一个重载：
    print(10L);     // 精确匹配 print(long)
    print(3.14);    // 精确匹配 print(double)

    return 0;
}//除此之外,函数重载还支持对const和非const参数匹配调用
