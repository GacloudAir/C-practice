#include <iostream>
using namespace std;



int main()
{
    double *pt=new double;
    *pt =3.14;
    cout <<*pt<<endl;
    delete pt;
    return 0;
}