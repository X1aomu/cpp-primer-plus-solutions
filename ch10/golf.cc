//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 03 in
/// chapter 10 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex10_03.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-02 12:22:57 CST
///
//===----------------------------------------------------------------------===//

#include "golf.h"

#include <cstring>

#include <iostream>

using namespace std;

golf::golf(const char* name, int hc)
{
    strncpy(fullname, name, Len - 1);
    fullname[Len - 1] = '\0';
    handicap = hc;
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

    g = golf(s.c_str(), hc);

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
