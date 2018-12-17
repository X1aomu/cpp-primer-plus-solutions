//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 04 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex04_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-17 23:55:24 CST
///
//===----------------------------------------------------------------------===//

#include "winec.h"

#include <iostream>

using namespace std;

Wine::Wine()
    : label("none"), num_years(0), data()
{
    /* nothing to do here */
}

Wine::Wine(const char* l, int y)
    : label(l), num_years(y), data(ArrayInt(y), ArrayInt(y))
{
    /* nothing to do here */
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
    : label(l), num_years(y), data(ArrayInt(y), ArrayInt(y))
{
    for (int i = 0; i != num_years; ++i)
    {
        data.first()[i] = yr[i];
        data.second()[i] = bot[i];
    }
}

void Wine::Show() const
{
    cout << "Wine: " << label << "\n";
    cout << "        Year    Bottles"
         << "\n";
    for (int i = 0; i != num_years; ++i)
    {
        cout << "        " << data.first()[i] << "    " << data.second()[i]
             << "\n";
    }
}

int Wine::sum() const
{
    return data.second().sum();
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
        data.first()[i] = year;
        data.second()[i] = bottles;
    }
}
