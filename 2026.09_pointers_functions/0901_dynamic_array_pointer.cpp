#include <iostream>
using namespace std;

int main()
{
    int *psome = new int[10];//创建一个十元素动态数组
    psome[0] = 5;//为第一个元素赋值
    psome[1] = 10;//为第二个元素赋值
    psome[2] = 15;//为第三个元素赋值
    cout << "Value at index 0: " << psome[0] << endl;
    psome = psome + 1;//指针向后移动一个位置
    cout << "now value at index 0: " << psome[0] << endl;
    psome = psome - 1;//指针向前移动一个位置（释放前必要的重要设置）
    delete[] psome;//释放整个动态数组
    return 0;
}