// This file is a solution to a programming exercise of Cpp Primer Plus 6th
// Edition.
// @Chapter 02
// @Exercise 05
//
// @Author Wang Jiayuan
// @Created 2018-09-06 23:15:41 CST
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
