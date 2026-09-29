#include <iostream>
using namespace std;



int main()
{
    int i = 11;
    int j = 12;
    if (i++<6||i==j && j==12)//&&优先级更高,会判断i++<6或(i==j && j==12)而非(i++<6||i==j)与j==12;
        //完整逻辑为:i<6->i++->(i==j && j==12) -> ... || ... 
        cout<<"true"<<endl;
    else
        cout<<"fause"<<endl;
    cout << "i=" << i;
    return 0;
}