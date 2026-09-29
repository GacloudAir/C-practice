// cinfish.cpp -- non-numeric input terminates loop
#include <iostream>
const int Max = 5;
int main()
{
    using namespace std;
    // get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
         << " fish <q to terminate.\n";
    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i]) //右式若正常输入,判定为true,否则结束循环
    {
        if (++i < Max)
            cout << "fish #" << i+1 << ": ";
    }

    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];//表示total=total(原值)+fish[j]

    // report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of " << i << " fish\n";
    cout << "Done.\n";
    return 0;
}