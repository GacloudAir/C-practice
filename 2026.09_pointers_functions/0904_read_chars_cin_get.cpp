// textin1.cpp -- reading chars with a while loop
#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;    // use basic input
    cout << "Enter characters; enter # to quit:\n";//在 C++ 字符串和字符常量中，反斜杠 \ 是转义前缀，使用"\\"代表真正的反斜杠。
    cin >> ch;    // get a character
    while (ch != '#')   // test the character
    {
        cout << ch;    // echo the character
        ++count;    // count the character
        cin >> ch;    // get the next character
    }
    cout <<endl<<count<<" characters read\n";
    return 0;
}