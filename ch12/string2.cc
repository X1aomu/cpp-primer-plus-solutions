//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex12_02.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-16 11:14:29 CST
///
//===----------------------------------------------------------------------===//

#include "string2.h" // includes <iostream>

#include <cctype>
#include <cstring> // string.h for some

#include <algorithm>

using namespace std;

// initializing static class member

int String::num_strings = 0;

// static method

int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char* s) // construct String from C string
{
    len = std::strlen(s);    // set size
    str = new char[len + 1]; // allot storage
    std::strcpy(str, s);     // initialize pointer
    num_strings++;           // set object count
}

String::String() // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0'; // default string
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;            // handle static member update
    len = st.len;             // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str); // copy string to new location
}

String::~String() // necessary destructor
{
    --num_strings; // required
    delete[] str;  // required
}

void String::stringlow()
{
    for_each(str, str + len + 1, [](char& e) { e = tolower(e); });
}

void String::stringup()
{
    for_each(str, str + len + 1, [](char& e) { e = toupper(e); });
}

int String::has(const char& c) const
{
    int count = 0;
    for_each(str, str + len + 1, [&](char& e) {
        if (e == c)
            ++count;
    });
    return count;
}

// overloaded operator methods

// assign a String to a String
String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String& String::operator+=(const String& rhs)
{
    char* new_str = new char[len + rhs.len + 1];
    strcpy(new_str, str);
    strcpy(new_str + len, rhs.str);
    delete[] str;
    str = new_str;

    len += rhs.len;

    return *this;
}

// read-write char access for non-const String
char& String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char& String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends
bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) > 0);
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

String operator+(const String& lhs, const String& rhs)
{
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}

// simple String output
ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
