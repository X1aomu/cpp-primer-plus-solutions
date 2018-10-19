//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 04 in
/// chapter 09 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex09_04.cc.
///
/// \author Wang Jiayuan
/// \since 2018-10-19 00:12:20 CST
///
//===----------------------------------------------------------------------===//

#include "sales.h"

#include <cmath>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

namespace SALES
{

// copies the lesser of 4 or n items from the array ar
// to the sales member of s and computes and stores the
// average, maximum, and minimum values of the entered items;
// remaining elements of sales, if any, set to 0
void setSales(Sales& s, const double ar[], int n)
{
    n = n < 4 ? n : 4;

    for (int i = 0; i != n; ++i)
    {
        std::copy(ar, ar + n, s.sales);
    }

    s.max = *std::max_element(ar, ar + n);
    s.min = *std::min_element(ar, ar + n);
    s.average = std::accumulate(ar, ar + n, 0.0) / n;

    // set the remaining elements to 0
    std::for_each(s.sales + n, s.sales + QUARTERS, [](double& e) { e = 0.0; });
}

// gathers sales for 4 quarters interactively, stores them
// in the sales member of s and computes and stores the
// average, maximum, and minimum values
void setSales(Sales& s)
{
    using std::cin;
    using std::cout;

    int n = 0; // quarters
    double sales[QUARTERS] = {0};

    while (n < QUARTERS)
    {
        cout << "Enter the sales of quarter #" << n + 1
             << " (quit with non-member): ";
        std::string line;
        getline(cin, line);
        std::istringstream iss(line);
        iss >> sales[n];
        if (!iss)
            break;
        ++n;
    }

    // if no input gathered, set n to 1, thus min, max and average are all 0.
    if (n == 0)
    {
        n = 1;
    }

    setSales(s, sales, n);
}

// display all information in structure s
void showSales(const Sales& s)
{
    using std::cout;

    cout << "Quarterly Sales:";
    std::for_each(s.sales, s.sales + QUARTERS,
                  [](const double& e) { cout << " " << e; });
    cout << "\n";
    cout << "Average: " << s.average << "\n";
    cout << "Max:     " << s.max << "\n";
    cout << "Min:     " << s.min << "\n";
}

} // namespace SALES
