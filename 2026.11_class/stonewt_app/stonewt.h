// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // 1英石(st) = 14磅(lbs)
    int stone;                    // 整英石数量
    double pds_left;              // 剩余的磅数（小数）
    double pounds;                // 总磅数
public:
    Stonewt(double lbs);          // 构造函数1：通过总磅数(double)转换
    Stonewt(int stn, double lbs); // 构造函数2：通过英石和磅数构造
    Stonewt();                    // 构造函数3：默认构造函数
    ~Stonewt();
    void show_lbs() const;        // 以总磅数格式显示
    void show_stn() const;        // 以英石和磅格式显示
};
#endif