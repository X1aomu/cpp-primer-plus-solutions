//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 02 in chapter 10 of Cpp
/// Primer Plus 6th Edition.
///
/// Here is a rather simple class definition:
/// \code
///     class Person
///     {
///     private:
///         static const int LIMIT = 25;
///         string lname;      // Person’s last name
///         char fname[LIMIT]; // Person’s first name
///     public:
///         Person() : lname("") { fname[0] = '\0'; }            // #1
///         Person(const string& ln, const char* fn = "Heyyou"); // #2
///
///         // the following methods display lname and fname
///         void Show() const;       // firstname lastname format
///         void FormalShow() const; // lastname, firstname format
///     };
/// \endcode
///
/// (It uses both a string object and a character array so that you can compare
/// how the two forms are used.) Write a program that completes the
/// implementation by providing code for the undefined methods. The program in
/// which you use the class should also use the three possible constructor calls
/// (no arguments, one argument, and two arguments) and the two display methods.
/// Here’s an example that uses the constructors and methods:
/// \code
///     Person one;                      // use default constructor
///     Person two("Smythecraft");       // use #2 with one default argument
///     Person three("Dimwiddy", "Sam"); // use #2, no defaults
///     one.Show();
///     cout << endl;
///     one.FormalShow();
///     // etc. for two and three
/// \endcode
///
/// \author Wang Jiayuan
/// \since 2018-11-02 11:01:12 CST
///
//===----------------------------------------------------------------------===//

#include <cstring>

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
    static const int LIMIT = 25;
    string lname;      // Person’s last name
    char fname[LIMIT]; // Person’s first name
public:
    Person() : lname("") { fname[0] = '\0'; }            // #1
    Person(const string& ln, const char* fn = "Heyyou"); // #2

    // the following methods display lname and fname
    void Show() const;       // firstname lastname format
    void FormalShow() const; // lastname, firstname format
};

int main()
{
    Person one;                      // use default constructor
    Person two("Smythecraft");       // use #2 with one default argument
    Person three("Dimwiddy", "Sam"); // use #2, no defaults

    one.Show();
    one.FormalShow();
    cout << endl;

    two.Show();
    two.FormalShow();
    cout << endl;

    three.Show();
    three.FormalShow();
    cout << endl;

    return 0;
}

Person::Person(const string& ln, const char* fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}

void Person::Show() const
{
    cout << fname << " " << lname << "\n";
}
void Person::FormalShow() const
{
    cout << lname << " " << fname << "\n";
}
