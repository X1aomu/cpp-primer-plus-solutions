//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 08 in chapter 05 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a program that uses an array of char and a loop to read one word at a
/// time until the word done is entered.The program should then report the
/// number of words entered (not counting done).A sample run could look like
/// this:
///
/// Enter words (to stop, type the word done):
/// anteater birthday category dumpster
/// envy finagle geometry done for sure
/// You entered a total of 7 words.
///
/// You should include the cstring header file and use the strcmp() function to
/// make the comparison test.
///
/// \author Wang Jiayuan
/// \since 2018-09-28 19:57:47 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

#include <cstring>

using namespace std;

int main()
{
    const int kMaxLengthOfWord = 30;
    const char kEndOfInput[] = "done";

    int num_of_words = 0;

    cout << "Enter words (to stop, type the word done):" << endl;
    char word[kMaxLengthOfWord];
    while (cin >> word)
    {
        if (strcmp(word, kEndOfInput) == 0)
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
