//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 11 of Cpp Primer Plus 6th Edition.
///
/// Modify the Vector class header and implementation files (Listings 11.13
/// and 11.14) so that the magnitude and angle are no longer stored as data
/// components. Instead, they should be calculated on demand when the magval()
/// and angval() methods are called.You should leave the public interface
/// unchanged (the same public methods with the same arguments) but alter the
/// private section, including some of the private method and the method
/// implementations. Test the modified version with Listing 11.15, which should
/// be left unchanged because the public interface of the Vector class is
/// unchanged.
///
/// \author Wang Jiayuan
/// \since 2018-11-08 19:56:13 CST
///
/// \sa ch11/vect2.h ch11/vect2.cc
///
//===----------------------------------------------------------------------===//

// Listings 11.15 below
#include "vect2.h"
#include <cstdlib>
#include <ctime>    // time() prototype
#include <fstream>  // rand(), srand() prototypes
#include <iostream> // rand(), srand() prototypes

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps
               << " steps, the subject "
                  "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
               << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}
