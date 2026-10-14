#include <iostream>
using namespace std;



int main()
{
    int i;
    cin>>i;
    switch (i)
    {
        case 1:cout<<i<<endl;break;
        case 2:cout<<(i*-1)<<endl;break;
        case 3:cout<<(i-1)<<endl;break;
        default:cout<<"What can I say"<<endl;
    }
    return 0;
}