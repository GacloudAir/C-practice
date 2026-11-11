// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    
    //使用友元函数,不强制左端是成员函数,从而允许double*t
    friend Time operator*(double m, const Time & t)
        { return t * m; }   // inline definition
        
    // 友元函数：重载 << 运算符，用于直接 cout << time
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
    //重载成员函数要求左端是自定义的成员函数,但cout是标准库,修改标准库不现实,因此需要使用友元函数
};
#endif