//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 09 in chapter 05 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a program that matches the description of the program in Programming
/// Exercise 8, but use a string class object instead of an array. Include the
/// string header file and use a relational operator to make the comparison
/// test.
///
/// \author Wang Jiayuan
/// \since 2018-09-28 20:28:35 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string kEndOfInput = "done";

    int num_of_words = 0;

    cout << "Enter words (to stop, type the word done):" << endl;
    string word;
    while (cin >> word)
    {
        if (word == kEndOfInput)
        {
            break;
        }
        ++num_of_words;
    }
    cout << "You entered a total of " << num_of_words << " word"
         << (num_of_words > 1 ? "s" : "") << "."
         << "\n";

    return 0;
}
