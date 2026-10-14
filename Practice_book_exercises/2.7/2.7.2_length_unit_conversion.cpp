#include <iostream>
using namespace std;

int translation(void)
{
    int length;
    cout << "please set the length" <<endl;
    cin >> length;
    return (length*220);
}

int main()
{
    int yd_length = translation();
    cout << "It can be translated to:" << yd_length << "yd";
    return 0;
}

