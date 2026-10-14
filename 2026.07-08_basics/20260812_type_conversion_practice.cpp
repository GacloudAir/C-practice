// init.cpp -- type changes on initialization
#include <iostream>
int main()
{
    using namespace std;
    double x;
    cout << "Enter a double value: ";
    cin >> x;  // input a double value
    cout << "x = " << static_cast<int>(x) << endl;
}