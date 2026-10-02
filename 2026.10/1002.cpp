//filefunc.cpp -- function with ostream & parameter
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[],int n);
const int LIMIT = 5;
int main()
{
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of your "
            "telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
         << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    return 0;
}

void file_it(ostream & os/*这个参数可以指向ostream/ofstream对象*/, double fo, const double fe[],int n)
{//传入后,可以用os直接指涉传入对象,实现下列一系列内容
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); //保存下述修改前的当前格式
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);//setf可以设置不同的格式化状态,如此处显示小数点
    os.precision(1);//显示小数位数
    os.width(12);
    os << "f.l. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);   //恢复保存的格式,但是应该使用os.flags(initial),因为setf只能追加状态,而非改回状态
}//这个函数充分体现了C++的继承与多态特性(ios_base -> ostream -> ofstream同一类函数,不同的目标,一致的写法)
//同时体现了C++的封装与状态管理(不需要指涉具体对象,使用.进行对象成员访问并按需修改状态)