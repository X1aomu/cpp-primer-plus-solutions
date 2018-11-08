//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 11 of Cpp Primer Plus 6th Edition.
///
/// Modify Listing 11.15 so that it writes the successive locations of the
/// random walker into a file. Label each position with the step number. Also
/// have the program write the initial conditions (target distance and step
/// size) and the summarized results to the file. The file contents might look
/// like this:
///
///     Target Distance: 100, Step Size: 20
///     0: (x,y) = (0, 0)
///     1: (x,y) = (-11.4715, 16.383)
///     2: (x,y) = (-8.68807, -3.42232)
///     ...
///     26: (x,y) = (42.2919, -78.2594)
///     27: (x,y) = (58.6749, -89.7309)
///     After 27 steps, the subject has the following location:
///     (x,y) = (58.6749, -89.7309)
///     or
///     (m,a) = (107.212, -56.8194)
///     Average outward distance per step = 3.97081
///
/// \author Wang Jiayuan
/// \since 2018-11-08 19:04:01 CST
///
/// \sa ch11/vect1.h ch11/vect1.cc
///
//===----------------------------------------------------------------------===//

#include "vect1.h"
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
    ofstream output("output_ex11_01.txt", ios::out);

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        output << "Target Distance: " << target << ", Step Size: " << dstep
               << "\n";
        output << steps << ": " << result << "\n";
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            output << steps << ": " << result << "\n";
        }
        output << "After " << steps
               << " steps, the subject "
                  "has the following location:\n";
        output << result << endl;
        result.polar_mode();
        output << " or\n" << result << endl;
        output << "Average outward distance per step = "
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
