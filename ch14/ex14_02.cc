//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 04 of Cpp Primer Plus 6th Edition.
///
/// This exercise is the same as Programming Exercise 1, except that you should
/// use private inheritance instead of containment. Again, a few typedefs might
/// prove handy. Also you might contemplate the meaning of statements such as
/// the following:
/// \code
///     PairArray::operator=(PairArray(ArrayInt(),ArrayInt()));
///     cout << (const string &)(*this);
/// \endcode
///
/// The class should work with the same test program as shown in Programming
/// Exercise 1.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 14:57:16 CST
///
//===----------------------------------------------------------------------===//

// ex14_02.cc -- using Wine class with private inheritance
#include "winei.h"
#include <iostream>
int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs); // store label, years, give arrays yrs elements
    holding.GetBottles();
    // solicit input for year, bottle count
    holding.Show();
    // display object contents
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    // create new object, initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() // use Label() method
         << ": " << more.sum() << endl;
    // use sum() method
    cout << "Bye\n";
    return 0;
}
