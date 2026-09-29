#include <iostream>
using namespace std;



int main()
{
    int i = 0;
    cout<<"please set i"<<endl;
    cin>>i;
    for (i=i;i>0;i--)
    {
        int r=i;
        int result=1;
        for (r=r;r>0;r--)
        {
            result=result*r;
        }
        cout << i <<"! = "<<result<<endl;
    }
    return 0;
}