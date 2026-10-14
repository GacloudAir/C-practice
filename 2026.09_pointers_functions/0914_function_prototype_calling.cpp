// calling.cpp -- defining, prototyping, and calling a function
#include <iostream>

void simple();   //函数原型，表示有此函数在后面被定义和使用，防止使用时出现未定义报错

int main()
{
    using namespace std;
    cout << "main() will call the simple() function:\n";
    simple();    // function call
    cout << "main() is finished with the simple() function.\n";
    // cin.get();
    return 0;
}

// function definition
void simple()
{
    using namespace std;
    cout << "I'm but a simple function.\n";
}