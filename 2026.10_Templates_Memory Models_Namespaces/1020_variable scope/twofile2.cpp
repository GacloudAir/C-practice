// twofile2.cpp -- variables with internal and external linkage
#include <iostream>
extern int tom;         //使用extern,外部链接tom变量
static int dick = 10;   //使用static,在文件内定义一个变量,覆盖外部变量作用域
int harry = 200;        //定义一个外部变量,作用域跨文件
                        // no conflict with twofile1 harry

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}