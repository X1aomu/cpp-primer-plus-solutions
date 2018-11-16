//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex12_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-16 09:21:00 CST
///
//===----------------------------------------------------------------------===//

#include "cow.h"

#include <cstring>
#include <iostream>

Cow::Cow()
{
    strcpy(name, "Nameless");
    hobby = new char[20];
    strcpy(hobby, "To eat");
    weight = 10000;
}

Cow::Cow(const Cow& c)
{
    strncpy(name, c.name, 20);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::Cow(const char* nm, const char* ho, double wt) : weight(wt)
{
    strcpy(name, nm);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
}

Cow& Cow::operator=(const Cow& c)
{
    if (this == &c)
        return *this;

    strcpy(name, c.name);
    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;

    return *this;
}

Cow::~Cow()
{
    delete[] hobby;
}

void Cow::ShowCow() const
{
    using namespace std;
    cout << "{ ";
    cout << '"' << "Name" << '"' << ": " << '"' << name << '"' << ", ";
    cout << '"' << "Hobby" << '"' << ": " << '"' << hobby << '"' << ", ";
    cout << '"' << "Weight" << '"' << ": " << weight;
    cout << " }";
}
