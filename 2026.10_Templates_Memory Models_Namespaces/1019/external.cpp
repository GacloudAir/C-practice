// external.cpp -- external variables
// compile with support.cpp
#include <iostream>
using namespace std;
// external variable
double warming = 0.3;       //定义了全局变量,可供extern 变量进行引用声明
// function prototypes
void update(double dt);
void local();

int main()                   // uses global variable
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);             // call function to change warming
    cout << "Global warming is " << warming << " degrees.\n";
    local();                 // call function with local warming
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;
}