#include <iostream>
using namespace std;



int main()
{
    int A = 1;
    int & B = A;//使用引用,B将和A一样指向相同内存并拥有相同值,二者完全等价   
    return 0;
}