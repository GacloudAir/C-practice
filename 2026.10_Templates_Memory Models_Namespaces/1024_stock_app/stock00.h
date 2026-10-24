// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_//使用ifndef防止重复定义
#define STOCK00_H_

#include <string>

class Stock  //定义Stock类
{
private://私有类,非成员只允许经过成员间接访问此部分成员
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public://公共类,非成员类也可自由读取
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif