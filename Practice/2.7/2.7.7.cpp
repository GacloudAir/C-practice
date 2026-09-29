#include <iostream>
using namespace std;

void showtime(int hours,int minutes)
{
    cout << "Time:" << hours <<":"<<minutes<<endl;
}

int main()
{
    int Hours;
    int Minutes;
    cout<< "Enter the number of hours:"<<endl;
    cin >> Hours;
    cout<< "Enter the number of hours:"<<endl;
    cin>>Minutes;
    showtime(Hours,Minutes);
    return 0;
}