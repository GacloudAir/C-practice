#include <iostream>
using namespace std;



int main()
{
    int age = 39;
    const int * pt = &age;//age需要带&符号,以确保指针得到的是age的地址
    //这里的const阻止了指针pt修改age,但是age可以自行修改自己.
    //* pt =36;//不可行,*pt 被锁定
    age =36; //可行,age没有被锁定
    const float age_2 = 0;
    const float * pt_2 = &age_2;//可行,这样两个路径均被锁定
    const float age_3 = 0;
    //float *pt_3 = &age_3;//不可行,可变指针用于不可变值是被禁止的,但是可以使用强制类型转换
    float age_4 = 12;
    pt_2 = &age_4;//可行,const只阻止了pt_2指针修改指向变量的值,
                  //而允许其更换指向变量(虽然也不能修改)
    int const * pt_3 = &age;//const具有后结合性,结合*使pt_3不能更换其指向变量
    return 0;
}