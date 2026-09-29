#include <iostream>
using namespace std;



int main()
{
    double arr[5]={12.3,53.8,26.4,63.36,42.53};
    double *m = arr;//挪到外面即可
    for (int i=0;i++<5;)//使用i++<5,实则等价于i<5;i++;
    {
        //double *m = arr; //不能将定义放在循环中，会导致指针反复指向第一个值的地址而不能自动向下遍历
        double r= *m++;//等价于r= *m;m++;(++/--特有的先取值再增减)
        cout << r <<endl;
    }
    return 0;
}