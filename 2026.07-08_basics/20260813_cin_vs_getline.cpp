#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);         // 这里故意使用 cin，而不是 getline()
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);      // 这里也是 getline()
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}