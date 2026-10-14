// strgfun.cpp -- functions with a string argument
#include <iostream>
unsigned int c_in_str(const char * str, char ch);
int main()
{
    using namespace std;
    char mmm[15] = "minimum";    //char数组
// some systems require preceding char with static to
// enable array initialization

    char *wail = "ululate";      // 指向字符串的指针

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    return 0;
}

// this function counts the number of ch characters
// in the string str
unsigned int c_in_str(const char * str, char ch)//char数组不能被修改,这里声明为指向const char(数组)的指针
{
    unsigned int count = 0;

    while (*str)        //读取字符时输出的值非0,不触发循环结束,否则触发循环结束
    {
        if (*str == ch)
            count++;
        str++;          // 指向下一个字符
    }
    return count;
}