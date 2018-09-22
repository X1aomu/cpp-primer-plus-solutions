//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 10 in chapter 04 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a program that requests the user to enter three times for the 40-yd
/// dash (or 40-meter, if you prefer) and then displays the times and the
/// average. Use an array object to hold the data. (Use a built-in array if
/// array is not available.)
///
/// \author Wang Jiayuan
/// \since 2018-09-22 12:42:05 CST
///
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    const int NumOfTimes = 3;
    array<double, NumOfTimes> grades;
    cout << "Enter 3 times of 40-yd dash(e.g. 4 4.9 4.4): ";
    cin >> grades[0] >> grades[1] >> grades[2];
    cout << "Grades: ";
    for_each(grades.begin(), grades.end(),
             [](const double& grade) { cout << grade << " "; });
    cout << "Average: ";
    cout << accumulate(grades.begin(), grades.end(), 0.0) / grades.size()
         << "\n";
    return 0;
}
