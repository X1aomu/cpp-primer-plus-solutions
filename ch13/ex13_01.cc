//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 13 of Cpp Primer Plus 6th Edition.
///
/// Start with the following class declaration:
/// \code
///     // base class
///     class Cd // represents a CD disk
///     {
///     private:
///         char performers[50];
///         char label[20];
///         int selections;  // number of selections
///         double playtime; // playing time in minutes
///     public:
///         Cd(char* s1, char* s2, int n, double x);
///         Cd(const Cd& d);
///         Cd();
///         ~Cd();
///         void Report() const; // reports all CD data
///         Cd& operator=(const Cd& d);
///     };
/// \endcode
///
/// Derive a Classic class that adds an array of char members that will hold a
/// string identifying the primary work on the CD. If the base class requires
/// that any functions be virtual, modify the base-class declaration to make it
/// so. If a declared method is not needed, remove it from the definition. Test
/// your product with the following program:
/// \code
///     #include <iostream>
///     using namespace std;
///     #include "classic.h"
///     void Bravo(const Cd& disk);
///     int main()
///     {
///         Cd c1("Beatles", "Capitol", 14, 35.5);
///         Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
///                              "Alfred Brendel", "Philips", 2, 57.17);
///         Cd* pcd = &c1;
///         cout << "Using object directly:\n";
///         c1.Report(); // use Cd method
///         c2.Report(); // use Classic method
///         cout << "Using type cd * pointer to objects:\n";
///         pcd->Report(); // use Cd method for cd object
///         pcd = &c2;
///         pcd->Report(); // use Classic method for classic object
///         cout << "Calling a function with a Cd reference argument:\n";
///         Bravo(c1);
///         Bravo(c2);
///         cout << "Testing assignment: ";
///         Classic copy;
///         copy = c2;
///         copy.Report();
///         return 0;
///     }
///     void Bravo(const Cd& disk)
///     {
///         disk.Report();
///     }
/// \endcode
///
/// \author Wang Jiayuan
/// \since 2018-12-16 13:26:28 CST
///
/// \sa ch13/cd_1.h ch13/classic_1.h
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include "cd_1.h"
#include "classic_1.h"

using namespace std;

void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use Classic method
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}

void Bravo(const Cd& disk)
{
    disk.Report();
}
