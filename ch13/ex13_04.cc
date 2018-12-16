//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 04 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// Start with the Port class' and the VintagePort Class' declaration in port.h.
///
/// You get the job of completing the VintagePort work.
///
///     a. Your first task is to re-create the Port method definitions because
///     the former Portmaster immolated his upon being relieved.
///
///     b. Your second task is to explain why certain methods are redefined and
///     others are not.
///
///     c. Your third task is to explain why operator=() and operator<<() are
///     not virtual.
///
///     d. Your fourth task is to provide definitions for the VintagePort
///     methods.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 15:30:29 CST
///
/// \sa ch13/port.h ch13/port.cc
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include "port.h"

using namespace std;

// This test case is referenced at
// https://github.com/PytLab/Cpp-Primer-Plus/blob/master/ch13/13_4/main.cpp
int main()
{
    Port p1;
    Port p2("Tsingtao", "Beer", 30);
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    Port p3 = p2;
    p3.Show();
    p3 += 3;
    p3.Show();

    VintagePort vp1("Harbin", 50, "hb", 1992);
    vp1.Show();
    VintagePort vp2;
    vp2.Show();
    vp1 -= 3;
    vp2 = vp1;
    vp2.Show();

    return 0;
}
