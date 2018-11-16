//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// Consider the following class declaration:
///
/// \code
///     #ifndef COW_H_
///     #define COW_H_
///
///     class Cow
///     {
///         char name[20];
///         char* hobby;
///         double weight;
///
///     public:
///         Cow();
///         Cow(const Cow& c);
///         Cow(const char* nm, const char* ho, double wt);
///         ~Cow();
///         Cow& operator=(const Cow& c);
///         void ShowCow() const; // display all cow data
///     };
/// \endcode
///
/// Provide the implementation for this class and write a short program that
/// uses all the member functions.
///
/// \author Wang Jiayuan
/// \since 2018-11-16 08:55:49 CST
///
/// \sa ch12/cow.h ch12/cow.cc
///
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "cow.h"

using namespace std;

int main()
{
    Cow c1;
    c1.ShowCow();
    cout << "\n";

    Cow c2(c1);
    c2.ShowCow();
    cout << "\n";

    Cow c3("Cow 3", "Dancing", 1000);
    c3.ShowCow();
    cout << "\n";

    Cow c4;
    c4 = c3;
    c4.ShowCow();
    cout << "\n";

    Cow *c5 = new Cow();
    c5->ShowCow();
    cout << "\n";
    delete c5;

    return 0;
}
