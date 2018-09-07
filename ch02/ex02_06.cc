// This file is a solution to a programming exercise of Cpp Primer Plus 6th
// Edition.
// @Chapter 02
// @Exercise 06
//
// @Author Wang Jiayuan
// @Created 2018-09-06 23:22:38 CST
#include <iostream>

using namespace std;

double lightyearToAstronomicalunits(double lightyear) { return 63240 * lightyear; }

int main()
{
    cout << "Enter the number of light years: ";
    double lightyear;
    cin >> lightyear;
    cout << lightyear << " light years = " << lightyearToAstronomicalunits(lightyear)
         << " astronomical units." << endl;
    return 0;
}
