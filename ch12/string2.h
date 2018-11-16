//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex12_02.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-16 11:00:15 CST
///
//===----------------------------------------------------------------------===//

#include <iostream>

#ifndef STRING2_H_
#define STRING2_H_

class String
{
private:
    char* str;                    // pointer to string
    int len;                      // length of string
    static int num_strings;       // number of objects
    static const int CINLIM = 80; // cin input limit
public:
    // constructors and other methods
    String(const char* s); // constructor
    String();              // default constructor
    String(const String&); // copy constructor
    ~String();             // destructor
    int length() const { return len; }
    void stringlow();
    void stringup();
    int has(const char& c) const; // returns the number of times the character
                                  // appears in the string.
    // overloaded operator methods
    String& operator=(const String& rhs);
    String& operator+=(const String& rhs);
    char& operator[](int i);
    const char& operator[](int i) const;
    // overloaded operator friends
    friend bool operator<(const String& st, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st, const String& st2);
    friend String operator+(const String& lhs, const String& rhs);
    friend std::ostream& operator<<(std::ostream& os, const String& st);
    friend std::istream& operator>>(std::istream& is, String& st);
    // static function
    static int HowMany();
};

#endif
