#include <iostream>
using namespace std;



int main()
{
    long all_seconds,orignal_seconds,seconds,minutes;
    int hours, days;
    cout <<"Enter the number of seconds: " ;
    cin>>orignal_seconds;
    all_seconds = orignal_seconds;
    days = all_seconds/86400;
    all_seconds = all_seconds%86400;
    hours = all_seconds/3600;
    all_seconds = all_seconds%3600;
    minutes = all_seconds/60;
    seconds = all_seconds%60;
    cout << endl << orignal_seconds << " = " << days << " days," << hours << " hours,";
    cout << minutes << " minutes," << seconds <<" seconds,"; 
    return 0;
}