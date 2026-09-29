#include <iostream>
using namespace std;



int main()
{
    int a,b =0;
    int result = 0;
    cout << "please set two numbers" <<endl;
    cin >> a;
    cin >> b;
    if (a > b)
    {
        int r = a;
        a = b;
        b = r;
    }
    if (a == b)
        result = 2 * a;
    else
    {
        for (;a<=b;a++)
            result = result + a; 

    }
    cout << "the sum of all ints between a and b is " << result <<endl;
    return 0;
}