//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 05 in chapter 02 of Cpp
/// Primer Plus 6th Edition.
///
/// \author Wang Jiayuan
/// \since 2018-09-06 23:15:41 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

using namespace std;

double celsiusToFahrenheit(double celsius) { return 1.8 * celsius + 32.0; }

int main()
{
    cout << "Please enter a Celsius value: ";
    double celsius;
    cin >> celsius;
    cout << celsius << " degrees Celsius is " << celsiusToFahrenheit(celsius)
         << " degrees Fahrenheit." << endl;
    return 0;
}
