//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// Do Programming Exercise 1 but use dynamic memory allocation instead of fixed
/// size arrays for the various strings tracked by the two classes.
///
/// For more description, see ex13_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 14:32:53 CST
///
/// \sa ch13/cd_2.h ch13/classic_2.h
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include "cd_2.h"
#include "classic_2.h"

using namespace std;

void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use Classic method
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}

void Bravo(const Cd& disk)
{
    disk.Report();
}
