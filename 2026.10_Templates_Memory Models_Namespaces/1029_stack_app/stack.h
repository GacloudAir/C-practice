// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};     //使用枚举,在类里就可以立即使用该值定义(item)
    Item items[MAX];     //定义栈的核心-item数组
    int top;             //定义表示栈顶位置的变量,是实现栈特性的核心
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    //表示栈是否满,若满则反馈无法压入,否则放行压入
    bool push(const Item & item);    //压入函数

    //表示栈是否空
    bool pop(Item & item);           //弹出函数
};
#endif