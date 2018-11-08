//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 06 in
/// chapter 11 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex11_06.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-08 20:54:27 CST
///
//===----------------------------------------------------------------------===//

// stonewt.cpp -- Stonewt methods
#include "stonewt6.h"

#include <iostream>

using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
// default constructor, wt = 0
Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}
// destructor
Stonewt::~Stonewt()
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}
// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

bool operator==(const Stonewt& s1, const Stonewt& s2)
{
    if (s1.pounds == s2.pounds)
        return true;
    else
        return false;
}

bool operator!=(const Stonewt& s1, const Stonewt& s2)
{
    return !(s1 == s2);
}

bool operator>=(const Stonewt& s1, const Stonewt& s2)
{
    if (s1.pounds >= s2.pounds)
        return true;
    else
        return false;
}

bool operator>(const Stonewt& s1, const Stonewt& s2)
{
    if (s1.pounds > s2.pounds)
        return true;
    else
        return false;
}

bool operator<=(const Stonewt& s1, const Stonewt& s2)
{
    if (s1.pounds <= s2.pounds)
        return true;
    else
        return false;
}

bool operator<(const Stonewt& s1, const Stonewt& s2)
{
    if (s1.pounds < s2.pounds)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& s)
{
    os << s.pounds;
    return os;
}
