// strgback.cpp -- a function that returns a pointer to char
#include <iostream>
char * buildstr(char c, int n);     // prototype
int main()
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;             //输出批量写入的单个字符
    delete [] ps;                   // 释放函数生成的数组的内存
    ps = buildstr('+', 20);         // 生成20个+号组成的数组
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;                   // free memory
    return 0;
}

// builds string made of n c characters
char * buildstr(char c, int n)
{
    char * pstr = new char[n + 1];
    pstr[n] = '\0';                 // 在数组最后一位加入结束符
    while (n-- > 0)                 //n--表示从末尾往前写入(这样写可以少用一个i变量)
        pstr[n] = c;                //写入目标字符
    return pstr;
}