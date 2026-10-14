// strquote.cpp -- different designs
#include <iostream>
#include <string>
using namespace std;

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);  // has side effect
const string & version3(string & s1, const string & s2);  // bad design

int main()
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");//这里的符号是const char数组(等价一个char *指针)类型,
                                    //因为string类提供了char *向string转换的功能,这串字符得以被C风格字符串初始化为string对象并向函数内传递
                                    //此外,类型为const引用的形参可以在形参实参不匹配时创建正确类型的临时变量,并用转换后的是残值初始化再传递引用
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    return 0;
}

string version1(const string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
}

const string & version2(string & s1, const string & s2)  // has side effect
{
    s1 = s2 + s1 + s2;
//在函数内修改传入值,会导致一定的副作用
    return s1;
}

const string & version3(string & s1, const string & s2)  //函数类型为string &,其试图返回一个函数创建的临时类的引用,会导致严重问题
{
    string temp;

    temp = s2 + s1 + s2;
// unsafe to return reference to local variable
    return temp;
}