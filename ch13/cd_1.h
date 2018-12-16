//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex13_01.cc.
///
/// I made some changes on Cd class to meet the C++11 standard as ISO C++11 does
/// not allow conversion from string literal to 'char *'.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 14:03:32 CST
///
//===----------------------------------------------------------------------===//

#ifndef CD_1_H_
#define CD_1_H_

#include <cstring>

#include <iostream>

// base class
class Cd // represents a CD disk
{
private:
    char performers[50];
    char label[20];
    int selections;  // number of selections
    double playtime; // playing time in minutes
public:
    Cd();
    Cd(const char* s1, const char* s2, int n, double x);
    Cd(const Cd& d);
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
    Cd& operator=(const Cd& d);
};

inline Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}
inline Cd::Cd(const char* s1, const char* s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
inline Cd::Cd(const Cd& d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
inline Cd::~Cd()
{
}
inline void Cd::Report() const
{
    std::cout << "Performers: " << performers << "\n";
    std::cout << "Pabel: " << label << "\n";
    std::cout << "Selections: " << selections << "\n";
    std::cout << "Playtime: " << playtime << "\n";
}
inline Cd& Cd::operator=(const Cd& d)
{
    if (this == &d)
        return *this;
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

#endif // CD_1_H_
