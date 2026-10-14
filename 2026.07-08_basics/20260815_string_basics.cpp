// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <string>    // make string class available
int main()
{
    using namespace std;
    string name { "Java" };
    string description;
    cout << "What do you think of " << name<< "?\n";
    getline(cin, description);    // read a line into description
    string all = name + ": " + description;    // concatenate strings
    string copy;
    copy = all;               // copy all into copy
    copy += '\n';            // append newline character to copy
    cout << copy << endl;            // print copy
    size_t len = copy.size();          // get length of copy
    cout << "The string " << copy << " contains " << len << " characters.\n";
}
