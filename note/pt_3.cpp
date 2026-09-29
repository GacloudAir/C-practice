#include <iostream>
using namespace std;



int main()
{
    const int **pp2;   // pp2 是一个“指向 const int* 的指针”
    int * p1;          // p1 是一个“指向 int 的指针”
    const int n = 13;  // n 是常量，不允许修改
    pp2 = &p1;         // ⚠️ 关键行：把 int** 赋给 const int**
    *pp2 = &n;         // 通过 pp2 间接把 n 的地址赋给 p1
    *p1 = 10;          // ⚠️ 通过 p1 修改了 n 的值！const 被绕过
    return 0;
}
/*pp2 相信它指向的是 const int *（即 *pp2 应该只能读，不能写）。
但实际上 pp2 指向的是 p1（一个 int *）。
所以 *pp2 = &n; 实际上执行的是 p1 = &n;——把 n 的地址装进了 p1。
现在 p1 可以合法地通过 *p1 = 10; 修改 n 的值。
因此，多级指针的 const 转换必须保证每一级都满足 const 安全性*/