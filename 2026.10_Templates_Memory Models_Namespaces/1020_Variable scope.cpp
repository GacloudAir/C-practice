// static.cpp -- using a static local variable
#include <iostream>
// constants
const int ArSize = 10;

// function prototype
void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);
        while (next != '\n')      // string didn't fit!
            cin.get(next);        // dispose of remainder
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0;         //使用static声明内部变量,不改变变量范围但是能延长其存续期
    int count = 0;                //普通声明内部变量,每次触发函数都会重新声明一次,函数结束即被回收内存
    cout << "\"" << str <<"\" contains ";
    while (*str++)                //*str是一个指向字符串地址的指针,每次自增都会向后读取一个字符,若读取为空,转换bool为false
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}