//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 04 in chapter 08 of Cpp
/// Primer Plus 6th Edition.
///
/// Complete this file by providing the described functions and prototypes. Note
/// that there should be two show() functions, each using default arguments. Use
/// const arguments when appropriate. Note that set() should use new to allocate
/// sufficient space to hold the designated string. The techniques used here are
/// similar to those used in designing and implementing classes. (You might have
/// to alter the header filenames and delete the using directive, depending on
/// your compiler.)
///
/// \author Wang Jiayuan
/// \since 2018-10-16 23:29:00 CST
///
//===----------------------------------------------------------------------===//
#include <cstring>

#include <iostream>

using namespace std;

// for strlen(), strcpy()
struct stringy
{
    char* str; // points to a string
    int ct;    // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy& stry, const char c[])
{
    stry.ct = strlen(c);
    stry.str = new char[stry.ct];
    strcpy(stry.str, c);
}
void show(const stringy& stry, int n = 1)
{
    while (n--)
    {
        cout << stry.str << "\n";
    }
}
void show(const string& str, int n = 1)
{
    while (n--)
    {
        cout << str << "\n";
    }
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    // first argument is a reference,
    // allocates space to hold copy of testing,
    // sets str member of beany to point to the
    // new block, copies testing to new block,
    // and sets ct member of beany
    set(beany, testing);
    show(beany);    // prints member string once
    show(beany, 2); // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);    // prints testing string once
    show(testing, 3); // prints testing string thrice
    show("Done!");
    return 0;
}
