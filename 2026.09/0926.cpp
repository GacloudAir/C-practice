// recur.cpp -- using recursion
#include <iostream>
void countdown(int n);

int main()
{
    countdown(4);           // call the recursive function
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Counting down ... " << n << endl;//前半部分,递归会先多次完成这一部分
    if (n > 0)
        countdown(n-1);     //调用递归
    cout << n << ": Kaboom!\n";//后半部分,递归会将这部分执行同样次数
}//递归形如一个千层饼,从上到下,先得到上半部分的酥皮(语句),越过中间区域后得到下半部分.
//另外,五次递归互相独立,对于不同层数的递归,其拥有不同坐标