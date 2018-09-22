//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 07 in chapter 04 of Cpp
/// Primer Plus 6th Edition.
///
/// \author Wang Jiayuan
/// \since 2018-09-22 12:23:32 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

using namespace std;

struct Pizza
{
    string name;
    unsigned diameter; ///< in cm
    unsigned weight;   ///< in grams
};

void print(const Pizza& p);

int main()
{
    cout << "Enter the name of pizza: ";
    string name;
    getline(cin, name);
    cout << "Enter the diameter of pizza in cm: ";
    unsigned d;
    cin >> d;
    cout << "Enter t he weight of pizza in grams: ";
    unsigned weight;
    cin >> weight;
    Pizza pizza = {name, d, weight};
    print(pizza);
    return 0;
}

void print(const Pizza& p)
{
    cout << "Pizza: " << p.name << "\n";
    cout << "\t"
         << "Diameter: " << p.diameter << "cm"
         << "\n";
    cout << "\t"
         << "Weight: " << p.weight << "g"
         << "\n";
    cout.flush();
}
