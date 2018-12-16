//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 04 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex13_04.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-16 15:57:03 CST
///
//===----------------------------------------------------------------------===//

#include "port.h"

#include <cstring>

#include <iostream>

Port::Port(const char* br, const char* st, int b)
    : brand(new char[strlen(br) + 1]), bottles(b)
{
    strcpy(brand, br);
    strcpy(style, st);
}

Port::Port(const Port& p)
    : brand(new char[strlen(p.brand) + 1]), bottles(p.bottles)
{
    strcpy(brand, p.brand);
    strcpy(style, p.style);
}

Port& Port::operator=(const Port& p)
{
    if (this == &p)
        return *this;

    delete[] brand;
    brand = new char[strlen(p.brand) + 1];

    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;

    return *this;
}

Port& Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b)
{
    if (b <= bottles)
        bottles -= b;
    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << "\n";
    std::cout << "Kind: " << style << "\n";
    std::cout << "Bottles: " << bottles << "\n";
}

ostream& operator<<(ostream& os, const Port& p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort()
    : Port("none", "vintage", 0), nickname(new char[5]), year(1970)
{
    strcpy(nickname, "none");
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, "vintage", b), nickname(new char[strlen(nn) + 1]), year(y)
{
    strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort& vp)
    : Port(vp), nickname(new char[strlen(vp.nickname) + 1]), year(vp.year)
{
    strcpy(nickname, vp.nickname);
}

void VintagePort::Show() const
{
    std::cout << "Nickanme: " << nickname << "\n";
    std::cout << "Year: " << year << "\n";
    Port::Show();
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
    const Port& p = vp;
    os << vp.nickname << ", " << vp.year << ", " << p;
    return os;
}
