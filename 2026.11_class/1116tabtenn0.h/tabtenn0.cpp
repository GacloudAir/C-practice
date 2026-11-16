// tabtenn0.cpp -- simple base-class methods
#include "tabtenn0.h"//目前构建的是基本类,未来将在此基础上构建派生类
#include <iostream>

TableTennisPlayer::TableTennisPlayer (const string & fn,
    const string & ln, bool ht) : firstname(fn),
        lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}