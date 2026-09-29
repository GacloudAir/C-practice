// cubes.cpp -- regular and reference arguments
#include <iostream>
double cube(double a);
double refcube(double &ra);
int main ()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;//等价于a=a*a*a
    return a;
}

double refcube(double &ra)//传递引用不能使用诸如x+3.0这样的表达式,在参数为const引用时,C++会生成临时变量代替原变量传入
{
    ra *= ra * ra;//ra在函数内变动的时候,也会同步影响函数外的传入值,即X
    return ra;
}