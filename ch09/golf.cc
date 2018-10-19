//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 09 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex09_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-10-18 18:38:21 CST
///
//===----------------------------------------------------------------------===//
#include "golf.h"

#include <cstring>

#include <iostream>

using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
    strncpy(g.fullname, name, Len - 1);
    g.fullname[Len - 1] = '\0';
    g.handicap = hc;
}

int setgolf(golf& g)
{
    string s;
    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, s);

    if (s.empty()) // no name entered
        return 0;

    int hc;
    cout << "Enter the handicap: ";
    while (!(cin >> hc))
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid handicap, please try again: ";
    }

    setgolf(g, s.c_str(), hc);

    return 1;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    cout << "Name:     " << g.fullname << "\n";
    cout << "Handicap: " << g.handicap << "\n";
}
