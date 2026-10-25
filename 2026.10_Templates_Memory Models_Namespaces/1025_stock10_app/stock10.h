// stock10.h -- Stock class declaration with constructors, destructor added
#ifndef STOCK10_H_
#define STOCK01_H_
#include <string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
// two constructors
    Stock();        //默认构造函数,不填入参数时会触发
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();       //析构函数
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif