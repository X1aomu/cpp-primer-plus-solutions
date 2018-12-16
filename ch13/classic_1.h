//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex13_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 13:29:05 CST
///
/// \sa ch13/cd_1.h
///
//===----------------------------------------------------------------------===//

#ifndef CLASSIC_1_H_
#define CLASSIC_1_H_

#include <cstring>

#include <iostream>

#include "cd_1.h"

class Classic : public Cd
{
private:
    char works[255];

public:
    Classic();
    Classic(const char* w, const char* s1, const char* s2, int n, double x);
    Classic(const Classic& d);
    ~Classic() override;
    void Report() const override;
    Classic& operator=(const Classic& d);
};

inline Classic::Classic() : Cd()
{
    works[0] = '\0';
}
inline Classic::Classic(const char* w, const char* s1, const char* s2, int n,
                        double x)
    : Cd(s1, s2, n, x)
{
    strcpy(works, w);
}
inline Classic::Classic(const Classic& d) : Cd(d)
{
    strcpy(works, d.works);
}
inline Classic::~Classic()
{
}
inline void Classic::Report() const
{
    Cd::Report();
    std::cout << "Works: " << works << "\n";
}
inline Classic& Classic::operator=(const Classic& d)
{
    if (this == &d)
        return *this;
    Cd::operator=(d);
    strcpy(works, d.works);
    return *this;
}

#endif // CLASSIC_1_H_
