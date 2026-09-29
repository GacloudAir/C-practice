#include <iostream>
using namespace std;



int main()
{
    int maxtemps[4][5]=
    {
        {12,15,24,36,42},
        {12,15,24,36,42},
        {12,15,24,36,42},
        {12,15,24,36,42},
    };
    for (int i=0;i<4;i++)
    {
        for (int r=0;r<5;r++)
        {
            cout << maxtemps[i][r]<<",";
        }
        cout<<endl;
    }
    return 0;
}