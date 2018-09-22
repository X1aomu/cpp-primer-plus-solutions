//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 03 in chapter 02 of Cpp
/// Primer Plus 6th Edition.
///
/// \author Wang Jiayuan
/// \since 2018-09-06 23:13:38 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

using namespace std;

void firstFunc() { cout << "Three blind mice" << endl; }

void secondFunc() { cout << "See how they run" << endl; }

int main()
{
    firstFunc();
    firstFunc();
    secondFunc();
    secondFunc();
    return 0;
}
