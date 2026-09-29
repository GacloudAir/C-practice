#include <iostream>
#include <cstring>
using namespace std;



int main()
{
    char ghost[15] = "galloping";
    char * str = "galumphing";
    int n1 = strlen(ghost);//获取了char数组，实际上是指向该数组的指针
    int n2 = strlen(str);//获取了指向字符串的指针
    int n3 = strlen("gamboling");//获取了char字符串，实际上是指向该字符串的指针
    //注意,C风格字符串自带结束符,在传参中不需要为其提供字符串长度
    return 0;
}