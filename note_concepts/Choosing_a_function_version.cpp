// trailing_return.cpp -- 演示 decltype 与后置返回类型
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

// ============================================================
// 1. 传统模板函数：返回类型写在函数名前面
//    问题：当返回类型依赖参数运算结果时，难以提前写出
// ============================================================
template <typename T1, typename T2>
T1 add_old(T1 a, T2 b)   // 返回类型固定为 T1，可能丢失精度
{
    return a + b;
}

// ============================================================
// 2. C++11 后置返回类型：用 auto + ->
//    语法：auto 函数名(参数) -> 返回类型
//    返回类型写在参数列表之后，可以用参数名推导
// ============================================================
template <typename T1, typename T2>
auto add_new(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;   //也就是先算,再决定类型来返回
}

// ============================================================
// 3. decltype 单独使用：推导表达式的类型
// ============================================================
void demo_decltype()
{
    int x = 10;
    double y = 3.14;

    // decltype(表达式) 得到表达式的类型，不计算表达式的值
    decltype(x) a = 100;            // a 是 int
    decltype(y) b = 2.71;           // b 是 double
    decltype(x + y) c = 13.14;      // c 是 double（int + double -> double）

    std::cout << "decltype(x) -> " << typeid(a).name() << "  value=" << a << "\n";
    std::cout << "decltype(y) -> " << typeid(b).name() << "  value=" << b << "\n";
    std::cout << "decltype(x+y) -> " << typeid(c).name() << "  value=" << c << "\n";
}

// ============================================================
// 4. decltype 推导规则详解
// ============================================================
void demo_decltype_rules()
{
    int n = 5;
    int &ref = n;

    // 规则一：decltype(变量)      -> 变量的声明类型（保留引用）
    decltype(n)   a = 1;    // int
    decltype(ref) b = n;    // int&（引用类型）

    // 规则二：decltype(表达式)    -> 表达式的值类别
    //        若表达式是左值，结果是引用类型
    //        若表达式是右值，结果是非引用类型
    decltype((n)) c = n;    // (n) 是左值 -> int&
    decltype(n+1) d = 6;    // n+1 是右值 -> int

    c = 99;                 // 修改 c 就是修改 n
    std::cout << "n = " << n << "  (被 c 修改)\n";
    (void)a; (void)b; (void)d;
}

// ============================================================
// 5. 后置返回类型的经典应用：完美转发
// ============================================================
template <typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a * b)
{
    return a * b;
}

// ============================================================
// 6. 返回值依赖多个参数的复杂场景
// ============================================================
template <typename T1, typename T2>
auto max_of(T1 a, T2 b) -> decltype(a > b ? a : b)
{
    return a > b ? a : b;
}

// ============================================================
// 7. C++14 简化版：只用 auto 让编译器自动推导
//    （这里也列出，方便对比）
// ============================================================
template <typename T1, typename T2>
auto add_cpp14(T1 a, T2 b)   // C++14 起可以省略 -> decltype(...)
{
    return a + b;
}

// ============================================================
// 8. 通用模板函数：容器遍历输出
// ============================================================
template <typename Container>
void print_container(const Container &c, const std::string &label)
{
    std::cout << label << ": ";
    for (const auto &item : c)
        std::cout << item << " ";
    std::cout << "\n";
}

int main()
{
    std::cout << "========== 1. 传统模板 vs 后置返回类型 ==========\n";
    // add_old 返回 int（T1），丢失小数部分
    std::cout << "add_old(2, 3.9)   = " << add_old(2, 3.9)   << "  (int，丢失精度)\n";
    // add_new 返回 double（a+b 的真实类型）
    std::cout << "add_new(2, 3.9)   = " << add_new(2, 3.9)   << "  (double，保留精度)\n";

    std::cout << "\n========== 2. decltype 基本用法 ==========\n";
    demo_decltype();

    std::cout << "\n========== 3. decltype 推导规则 ==========\n";
    demo_decltype_rules();

    std::cout << "\n========== 4. 后置返回类型处理混合运算 ==========\n";
    std::cout << "multiply(3, 4.5)  = " << multiply(3, 4.5)  << "\n";
    std::cout << "multiply(2.5, 4)  = " << multiply(2.5, 4)  << "\n";

    std::cout << "\n========== 5. 返回类型依赖比较结果 ==========\n";
    std::cout << "max_of(10, 20.5)  = " << max_of(10, 20.5)  << "\n";
    std::cout << "max_of(3.14, 2)   = " << max_of(3.14, 2)   << "\n";

    std::cout << "\n========== 6. C++14 省略写法 ==========\n";
    std::cout << "add_cpp14(1, 2.5) = " << add_cpp14(1, 2.5) << "\n";

    std::cout << "\n========== 7. 通用容器遍历 ==========\n";
    std::vector<int> vi = {1, 2, 3, 4, 5};
    std::vector<double> vd = {1.1, 2.2, 3.3};
    std::vector<std::string> vs = {"apple", "banana", "cherry"};
    print_container(vi, "int   容器");
    print_container(vd, "double容器");
    print_container(vs, "string容器");

    return 0;
}