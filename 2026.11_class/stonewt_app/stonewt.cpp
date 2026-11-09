// stonewt.cpp -- Stonenwt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonenwt object from double value
Stonenwt::Stonenwt(double lbs)//允许隐式转换,若需要显式转换,则需要使用explicit
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonenwt object from stone, double values
Stonenwt::Stonenwt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonenwt::Stonenwt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonenwt::~Stonenwt()         // destructor
{
}

// show weight in stones
void Stonenwt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonenwt::show_lbs() const
{
    cout << pounds << " pounds\n";
}