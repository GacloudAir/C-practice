#include <iostream>
union one
{
    int i;
    double d;
};

int main()
{
    using namespace std;
    one thing;  // define a union variable
    thing.i = 10;  // set int member of union
    cout << "thing.i: " << thing.i << endl;
    thing.d = 3.14159;  // set double member of union
    cout << "thing.d: " << thing.d << endl;
    cout << "thing.i: " << thing.i << endl;  // the value of i is now undefined
    return 0;
}