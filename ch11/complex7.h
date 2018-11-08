//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 07 in
/// chapter 11 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex11_07.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-08 21:33:01 CST
///
//===----------------------------------------------------------------------===//

#ifndef COMPLEX7_H_
#define COMPLEX7_H_

#include <iostream>

class Complex
{
public:
    Complex(double a = .0, double b = .0) : a(a), b(b) {}

private:
    double a;
    double b;

    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend Complex operator~(const Complex& c);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& os, Complex& c);
};

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator~(const Complex& c);
std::ostream& operator<<(std::ostream& os, const Complex& c);
std::istream& operator>>(std::istream& is, Complex& c);

#endif // COMPLEX7_H_
