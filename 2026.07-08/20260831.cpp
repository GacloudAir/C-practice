// pointer.cpp -- using pointers to manipulate values
#include <iostream>
int main()
{
    using namespace std;
    int *p_num = new int; // 自助申请一个位置存放指针和对应值
    *p_num = 42; // assign value to allocated space
    cout << "address of p_num: " << p_num << endl;
    cout << "value of *p_num: " << *p_num << endl;
    delete p_num; // deallocate the memory
    p_num= new int(15);
    cout << "address of p_num: " << p_num << endl;
    cout << "value of *p_num: " << *p_num << endl;
    return 0;
}