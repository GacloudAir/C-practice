// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        //默认构造函数
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();       //析构函数(不做任何操作)
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s) const;//返回指向Stock对象的const引用,成员不会修改传入参数,也不会被修改
};

#endif