// This file is a solution to a programming exercise of Cpp Primer Plus 6th
// Edition.
// @Chapter 02
// @Exercise 07
//
// @Author Wang Jiayuan
// @Created 2018-09-06 23:31:24 CST
#include <iostream>

using namespace std;

void displayTime(unsigned hours, unsigned minutes) { cout << hours << ":" << minutes << endl; }

int main()
{
    unsigned hours;
    unsigned minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    displayTime(hours, minutes);

    return 0;
}
