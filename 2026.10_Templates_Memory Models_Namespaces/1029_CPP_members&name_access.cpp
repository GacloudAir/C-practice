#include <iostream>
#include <string>

// =========================================================
// 1. 定义命名空间和类
// =========================================================
namespace STM32_HAL {
    // 命名空间内的全局变量（模拟全局寄存器/常量）
    const int MAX_FREQ = 72;
    class Timer {
    private:
        std::string name;
        int psc;
        int arr;
    public:
        // 构造函数
        Timer(std::string n, int p, int a) : name(n), psc(p), arr(a) {}
        // 成员函数声明（稍后在类外实现，以演示 ::）
        void showConfig();
        void start();
    };
}

// =========================================================
// 2. 使用作用域解析运算符 (::) 
// =========================================================
// 告诉编译器：这两个函数是属于 STM32_HAL 命名空间下的 Timer 类的。

void STM32_HAL::Timer::showConfig() {
    // 这里的 std:: 也是作用域解析符，表示调用 std 命名空间的 cout 和 endl
    std::cout << "Timer [" << name << "] Config: PSC=" << psc << ", ARR=" << arr << "\n";
}

void STM32_HAL::Timer::start() {
    std::cout << name << " is starting...\n";
}


// =========================================================
// 3. 主函数：演示 (.) 和 (->)
// =========================================================
int main() {
    std::cout << "=== 运算符演示 ===\n\n";

    // --- 演示 (::) ---
    // 使用 STM32_HAL:: 访问命名空间里的常量
    std::cout << "System Clock: " << STM32_HAL::MAX_FREQ << " MHz\n";

    // --- 演示 (.) 直接成员运算符 ---
    // 在栈上实例化一个具体的对象（实体）
    STM32_HAL::Timer timer2("TIM2", 5999, 5999);
    
    // 拿在手里的是实体，直接用 .
    timer2.showConfig(); 
    timer2.start();      

    std::cout << "\n";

    // --- 演示 (->) 间接成员运算符 ---
    // 创建一个指针，指向刚才的那个对象
    STM32_HAL::Timer * p_timer2 = &timer2;
    
    // 拿在手里的是地址（指针），必须用 ->
    p_timer2->showConfig();
    p_timer2->start();

    std::cout << "\n";

    // 模拟动态分配（在堆上创建外设对象）
    STM32_HAL::Timer * p_timer3 = new STM32_HAL::Timer("TIM3", 0, 1000);
    p_timer3->showConfig();
    p_timer3->start();
    
    delete p_timer3; // 释放内存

    return 0;
}
//由上可知,C++有三种访问成员及其名称的运算符:
//其中使用namespace声明的需要用::解引用;
//具体的对象需要用.解引用
//指向对象的指针需要用-＞解引用