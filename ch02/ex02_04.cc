//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 04 in chapter 02 of Cpp
/// Primer Plus 6th Edition.
///
/// \author Wang Jiayuan
/// \since 2018-09-06 23:14:22 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your age: ";
    int age;
    cin >> age;
    cout << "Your age in months is: " << age * 12 << endl;
    return 0;
}
