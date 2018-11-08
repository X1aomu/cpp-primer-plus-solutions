//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 06 in
/// chapter 11 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex11_06.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-08 20:51:54 CST
///
//===----------------------------------------------------------------------===//

// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class Stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14 // pounds per stone
    };
    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const; // show weight in pounds format
    void show_stn() const; // show weight in stone format

    friend bool operator==(const Stonewt& s1, const Stonewt& s2);
    friend bool operator!=(const Stonewt& s1, const Stonewt& s2);
    friend bool operator>=(const Stonewt& s1, const Stonewt& s2);
    friend bool operator>(const Stonewt& s1, const Stonewt& s2);
    friend bool operator<=(const Stonewt& s1, const Stonewt& s2);
    friend bool operator<(const Stonewt& s1, const Stonewt& s2);
    friend std::ostream& operator<<(std::ostream& os, const Stonewt& s);
};
#endif
