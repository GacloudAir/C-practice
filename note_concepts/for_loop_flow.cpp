#include <iostream>
using namespace std;



int main()
{
    for (int i=0;i<5;i++/*=++i*/)
        //do something - for循环将括号内的内容分为定义->判断->执行->自增,因此i++与++i等价
        ;
    int j = 0;
    while (j++<5) //这里j++/++j的规则体现,前者先判断后自增,
                  //后者先自增后判断,为了保证和for循环效果相同,使用前者
        //do something
        ;
    int r = 0;
    int x = r++;//规则同样体现,r++先取值再自增,++r反之;
    //总结:在需要返回值时,i++与++i规则不同,而for循环第三部分无视返回值,故无需在意其先后;
    return 0;
}