//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex14_02.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 14:53:38 CST
///
//===----------------------------------------------------------------------===//

#include "winei.h"

#include <iostream>

using namespace std;

Wine::Wine() : PairArray(), label("none"), num_years(0)
{
    /* nothing to do here */
}

Wine::Wine(const char* l, int y)
    : PairArray(ArrayInt(y), ArrayInt(y)), label(l), num_years(y)
{
    /* nothing to do here */
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
    : PairArray(ArrayInt(y), ArrayInt(y)), label(l), num_years(y)
{
    for (int i = 0; i != num_years; ++i)
    {
        first()[i] = yr[i];
        second()[i] = bot[i];
    }
}

void Wine::Show() const
{
    cout << "Wine: " << label << "\n";
    cout << "        Year    Bottles"
         << "\n";
    for (int i = 0; i != num_years; ++i)
    {
        cout << "        " << first()[i] << "    " << second()[i] << "\n";
    }
}

int Wine::sum() const
{
    return second().sum();
}

void Wine::GetBottles()
{
    cout << "Enter " << label << " data for " << num_years << " year(s)"
         << "\n";
    for (int i = 0; i != num_years; ++i)
    {
        cout << "Enter year: ";
        int year;
        cin >> year;
        cout << "Enter bottles for that year: ";
        int bottles;
        cin >> bottles;
        first()[i] = year;
        second()[i] = bottles;
    }
}
