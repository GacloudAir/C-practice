#include <array>
#include <iostream>
using namespace std;

int main()
{
    array<char, 30> actor{};
    cout << "Enter the name of an actor: ";
    cin.get(actor.data(), static_cast<int>(actor.size()));
    return 0;
}