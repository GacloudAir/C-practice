#include <iostream>
using namespace std;



int main()
{
    int x = (1,024);//这里的逗号是分隔符,有括号时先取逗号后边的值返回,而024中0是八进制标志,实则十进制下为20
    int y;
    y = 1,024;
    cout << "x:" << x <<endl;
    cout << "y:" << y <<endl;
    return 0;
}
