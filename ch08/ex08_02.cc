//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 02 in chapter 08 of Cpp
/// Primer Plus 6th Edition.
///
/// The CandyBar structure contains three members. The first member holds the
/// brand name of a candy bar. The second member holds the weight (which may
/// have a fractional part) of the candy bar, and the third member holds the
/// number of calories (an integer value) in the candy bar. Write a program that
/// uses a function that takes as arguments a reference to CandyBar, a
/// pointer-to-char, a double, and an int and uses the last three values to set
/// the corresponding members of the structure. The last three arguments should
/// have default values of “Millennium Munch,” 2.85, and 350. Also the program
/// should use a function that takes a reference to a CandyBar as an argument
/// and displays the contents of the structure. Use const where appropriate.
///
/// \author Wang Jiayuan
/// \since 2018-09-29 14:40:21 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

#include <cstring>

using namespace std;

struct CandyBar
{
    string brand_name;
    double weight;
    int calories;
};
void print(const CandyBar& candybar);
void setCandyBar(CandyBar& candybar,
                 const char* brand_name = "Millennium Munch",
                 double weight = 2.85, int calories = 350);

int main()
{
    cout << "Enter the brand name: ";
    string brand_name;
    getline(cin, brand_name);

    cout << "Enter the weight: ";
    double weight;
    cin >> weight;

    cout << "Enter the calories: ";
    int calories;
    cin >> calories;

    CandyBar cb;
    setCandyBar(cb, brand_name.c_str(), weight, calories);

    print(cb);

    return 0;
}

void print(const CandyBar& candybar)
{
    cout << "Brand name: " << candybar.brand_name << "\n";
    cout << "Weight: " << candybar.weight << "\n";
    cout << "Calories: " << candybar.calories << "\n";
}

void setCandyBar(CandyBar& candybar, const char* brand_name, double weight,
                 int calories)
{
    candybar.brand_name = string(brand_name);
    candybar.weight = weight;
    candybar.calories = calories;
}
