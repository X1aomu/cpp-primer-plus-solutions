//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex13_02.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 14:36:28 CST
///
/// \sa ch13/cd_2.h ch13/classic_1.h
///
//===----------------------------------------------------------------------===//

#ifndef CLASSIC_2_H_
#define CLASSIC_2_H_

#include <cstring>

#include <iostream>

#include "cd_2.h"

class Classic : public Cd
{
private:
    char* works;

public:
    Classic();
    Classic(const char* w, const char* s1, const char* s2, int n, double x);
    Classic(const Classic& d);
    ~Classic() override;
    void Report() const override;
    Classic& operator=(const Classic& d);
};

inline Classic::Classic() : Cd(), works(new char[1])
{
    works[0] = '\0';
}
inline Classic::Classic(const char* w, const char* s1, const char* s2, int n,
                        double x)
    : Cd(s1, s2, n, x), works(new char[strlen(w) + 1])
{
    strcpy(works, w);
}
inline Classic::Classic(const Classic& d)
    : Cd(d), works(new char[strlen(d.works) + 1])
{
    strcpy(works, d.works);
}
inline Classic::~Classic()
{
    delete[] works;
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

    delete[] works;
    works = new char[strlen(d.works) + 1];

    strcpy(works, d.works);
    return *this;
}

#endif // CLASSIC_2_H_
