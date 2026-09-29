// textin3.cpp -- reading chars to end of file
#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch);    // attempt to read a char
    while (cin.fail() == false)   // 检测cin.get(ch)是否成功,在EDF被触发时，其会失败并触发退出 
    {
        cout << ch;    // echo character
        ++count;
        cin.get(ch);    // attempt to read another char
    }
    cout << endl << count << " characters read\n";
    return 0;
}