// arrfun4.cpp -- functions with an array range
#include <iostream>
const int ArSize = 8;
int sum_arr(const int * begin, const int * end);
int main()
{
    using namespace std;
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
// some systems require preceding int with static to
// enable array initialization

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);       // first 3 elements
    cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + 8);   // last 4 elements
    cout << "Last four eaters ate " << sum << " cookies.\n";
    return 0;
}

// return the sum of an integer array
int sum_arr(const int * begin, const int * end)//STL迭代器区间,后续可配合accumulate函数快速处理这类数组
{       //使用const,保证函数内部不会修改数组值
    const int * pt;//使用const,确保指针指向的整数不会被修改(但是pt的地址可变,可以指向不同值)
    int total = 0;

    for (pt = begin; pt != end; pt++)//最后一次循环将指向数组末尾,循环结束时将指向数组末后一个位置
        total = total + *pt;
    return total;
}