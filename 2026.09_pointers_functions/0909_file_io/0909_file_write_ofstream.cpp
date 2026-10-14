// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream>    // 提供文件I/O的基础头文件

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;    // 建立outFile对象用于文件写入,此时outFile等价于cout
    outFile.open("carinfo.txt");  // 打开文件夹下该名称的文件,若没有则自动创建一个
    if (!outFile.is_open())
        exit(EXIT_FAILURE);
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;//设定允许数字显示小数位
    cout.precision(2);//设定2位小数
    cout.setf(ios_base::showpoint);//若没有cout << fixed;强制显示小数点,有则多余
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same things using outFile instead of cout
    outFile << fixed;//在文件中执行上方同等文本操作
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();    // 关闭文件并保存,防止出现任何文件异常问题.
    return 0;
}