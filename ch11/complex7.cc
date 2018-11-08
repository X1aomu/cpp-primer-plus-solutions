#include "complex7.h"

#include <iostream>

Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(c1.a + c2.a, c1.b + c2.b);
}
Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1.a - c2.a, c1.b - c2.b);
}
Complex operator*(const Complex& c1, const Complex& c2)
{
    return Complex(c1.a * c2.a - c1.b * c2.b, c1.a * c2.b + c1.b * c2.a);
}
Complex operator~(const Complex& c)
{
    return Complex(c.a, -c.b);
}
std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << "(" << c.a << ", " << c.b << "i)";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& c)
{
    std::cout << "real: ";
    is >> c.a;
    if (!is)
        return is;
    std::cout << "imaginary: ";
    is >> c.b;
    return is;
}
