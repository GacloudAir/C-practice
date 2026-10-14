// ptrstr.cpp -- using pointers to strings
#include <iostream>
#include <cstring>    // declare strlen(), strcpy()
int main()
{
    using namespace std;
    char animal[20] = "bear";  // animal holds bear
    const char * bird = "wren"; // bird holds address of string
    char * ps;    // uninitialized

    cout << animal << " and "; // display bear
    cout << bird << "\n";    // display wren
    // cout << ps << "\n";    // may display garbage, may cause a crash

    cout << "Enter a kind of animal: ";
    cin >> animal;    // ok if input < 20 chars
    // cin >> ps; Too horrible a blunder to try; ps doesn't
    // point to allocated space

    ps = animal;    // 指针=数组，表示使用指针获取数组的首位地址
    cout << ps << "!\n";    // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1]; // 表示获取一个新的动态数组，长度为animal的长度+1（用于存储字符串结束符'\0'）
    strcpy(ps, animal);    //安全拷贝animal的内容到ps.
        cout << "After using strcpy():\n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;
    return 0;
}