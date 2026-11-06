// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// 构造函数1：从总磅数（double）构建
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;               // 整数除法求英石数
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs); // 求余数 + 小数部分
    pounds = lbs;                                  // 保存总磅数
}

// 构造函数2：从英石数（int）和磅数（double）构建
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;              // 换算总磅数
}

// 构造函数3：默认构造函数，初始化为0
Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {} // 析构函数

// 显示为英石+磅的格式
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// 显示为总磅数格式
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}