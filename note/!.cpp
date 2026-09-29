#include <iostream>
using namespace std;



int main()
{
    int x=3;
    if (!(x==4))//!与判断式之间需要隔括号,否则会出现!x的布尔值与4的比较
        cout << "x!=4" <<endl; 
    return 0;
}