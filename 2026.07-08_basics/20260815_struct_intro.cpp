#include<iostream>
#include<string>
using namespace std;

struct Person
    {
        string name;
        int age;
    };

int main()
{
    Person p1;
    p1.name = "Alice";
    p1.age = 30;
    cout << "Name: " << p1.name << ", Age: " << p1.age << endl;
}