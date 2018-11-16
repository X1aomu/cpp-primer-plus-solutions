//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex12_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-16 09:20:45 CST
///
//===----------------------------------------------------------------------===//

#ifndef COW_H_
#define COW_H_

class Cow
{
    char name[20];
    char* hobby;
    double weight;

public:
    Cow();
    Cow(const Cow& c);
    Cow(const char* nm, const char* ho, double wt);
    ~Cow();
    Cow& operator=(const Cow& c);
    void ShowCow() const; // display all cow data
};

#endif // COW_H_
