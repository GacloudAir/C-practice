// stringbad.cpp -- StringBad class methods
#include <cstring>                 // string.h for some
#include "stringbad.h"
using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

// class methods
// construct StringBad from C string
StringBad::StringBad(const char * s)//输入的是一个指针,因此str指向的是指针内地址
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n"; // For Your Information
}

StringBad::StringBad()             // default constructor
{
    len = 4;
    str = new char[4];             //申请了一块内存
    std::strcpy(str, "C++");       // default string
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n"; // FYI
}

StringBad::~StringBad()            // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";  // FYI
    --num_strings;                 //每次构造+1,每次析构-1,但是代码中出现多次调用析构函数,导致num_strings<0
    cout << num_strings << " left\n"; // FYI
    delete [] str;                 //释放内存
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}