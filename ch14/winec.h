//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex14_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-17 23:21:31 CST
///
//===----------------------------------------------------------------------===//

#ifndef WINEC_H_
#define WINEC_H_

#include <string>
#include <valarray>

#include "pair.h"

class Wine
{
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;

    std::string label;
    int num_years;
    PairArray data;

public:
    // default constructor
    Wine();
    // initialize label to l, number of years to y,
    // create array objects of length y
    Wine(const char* l, int y);
    // initialize label to l, number of years to y,
    // vintage years to yr[], bottles to bot[]
    Wine(const char* l, int y, const int yr[], const int bot[]);

    const std::string& Label() const { return label; }
    void Show() const;
    int sum() const;
    void GetBottles();
};

#endif // WINEC_H_
