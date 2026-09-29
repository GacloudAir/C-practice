#include <iostream>
using namespace std;



int main()
{
    for (int i=1;i<10;i++)
    {
        if (i==4)
            continue;//continue会跳过剩余代码,回到更新表达式从头运行
        cout << "i=" << i <<endl;
    }
    return 0;
}