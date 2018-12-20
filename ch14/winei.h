//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex14_02.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 14:50:56 CST
///
//===----------------------------------------------------------------------===//

#ifndef WINEI_H_
#define WINEI_H_

#include <string>
#include <valarray>

#include "pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray
{
private:
    std::string label;
    int num_years;

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

#endif // WINEI_H_
