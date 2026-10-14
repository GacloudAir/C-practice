#include <iostream>
using namespace std;
int main()
{
    //pt[x] = *(pt+x) = *(x+pt) = x[pt](不推荐使用)
    int *pt = new int[10];//创建一个十元素动态数组
    pt[0] = 5;//为第一个元素赋值
    cout << "Value at index 0: " << pt[0] << endl;
    *pt = 10;//与pt[0] = 10;等价
    cout << "now value at index 0: " << pt[0] << endl;
    pt[1] = 15;//为第二个元素赋值
    cout << "Value at index 1: " << pt[1] << endl;
    *(pt + 1) = 20;//与pt[1] = 20;等价
    cout << "now value at index 1: " << pt[1] << endl;
    1[pt] = 25;//与pt[1] = 25;等价
    cout << "now value at index 1: " << pt[1] << endl;
    delete[] pt;//释放整个动态数组
    return 0;
}