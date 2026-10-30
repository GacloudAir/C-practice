// stack.cpp -- Stack member functions
#include "stack.h"//引用上次的.h文件

Stack::Stack()      //创建一个空栈
{
    top = 0;//
}

bool Stack::isempty() const
{
    return top == 0;//判断语句,若是则返回true,否则返回false
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;//top表示的是下次压入的位置,这里先用到top再++就能压入到正确位置
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];//先--到应该弹出的位置,再弹出,就能在正确位置弹出,并且下次压入/弹出都能在正确的位置
        return true;
    }
    else
        return false;
}