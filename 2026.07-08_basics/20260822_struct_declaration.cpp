#include <iostream>
struct inflatable  // structure declaration
{
    char name[20];                                       
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guests[2] =
    {
        { "Glorious Gloria", 1.88, 29.99 },
        { "Audacious Arthur", 3.12, 32.99 }
    };  // guests is an array of structure variables of type inflatable
    cout << "The guests " << guests[0].name << " and " << guests[1].name;
    cout << " have a combined volume of ";
    cout << guests[0].volume + guests[1].volume << " cubic feet.\n";
    return 0;
}
