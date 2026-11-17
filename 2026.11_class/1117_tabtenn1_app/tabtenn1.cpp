// tabtenn1.cpp -- simple base-class methods
#include "tabtenn1.h"
#include <iostream>

// 基类构造函数
TableTennisPlayer::TableTennisPlayer (const string & fn,
    const string & ln, bool ht) : firstname(fn),
        lastname(ln), hasTable(ht) {}

// 基类方法
void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

// RatedPlayer methods（派生类方法）
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
    const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)//派生类接受基类对象tp,利用默认拷贝后设置自己的rating
    : TableTennisPlayer(tp), rating(r)
{
}