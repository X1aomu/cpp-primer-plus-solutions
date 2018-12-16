//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex13_02.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 14:38:11 CST
///
/// \sa ch13/cd_1.h
///
//===----------------------------------------------------------------------===//

#ifndef CD_2_H_
#define CD_2_H_

#include <cstring>

#include <iostream>

// base class
class Cd // represents a CD disk
{
private:
    char* performers;
    char* label;
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

inline Cd::Cd() : performers(new char[1]), label(new char[1])
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}
inline Cd::Cd(const char* s1, const char* s2, int n, double x)
    : performers(new char[strlen(s1) + 1]), label(new char[strlen(s2) + 1])
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
inline Cd::Cd(const Cd& d)
    : performers(new char[strlen(d.performers) + 1]),
      label(new char[strlen(d.label) + 1])
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
inline Cd::~Cd()
{
    delete[] performers;
    delete[] label;
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

    delete[] performers;
    delete[] label;
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];

    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

#endif // CD_2_H_
