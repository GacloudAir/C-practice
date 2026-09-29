// cingolf.cpp -- non-numeric input skipped
#include <iostream>
const int Max = 5;
int main()
{
    using namespace std;
    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ": ";
        while (!(cin >> golf[i])) {
            cin.clear(); // reset input(不清除输入的内容,需要清理干净)
            while (cin.get() != '\n')//每次取出一个字符，在到达\n之前会一直循环
                continue; // get rid of bad input
            cout << "Please enter a number: ";//取到\n之后被触发,从而要求重新输入
        }
    }
    // calculate average
    double total = 0.0;
    for (i = 0; i < Max; i++)
        total += golf[i];

    // report results
    cout << total / Max << " = average score " << Max << " rounds\n";
    return 0;
}