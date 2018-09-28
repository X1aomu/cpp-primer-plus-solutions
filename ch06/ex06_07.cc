//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 07 in chapter 06 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a program that reads input a word at a time until a lone q is
/// entered. The program should then report the number of words that began with
/// vowels, the number that began with consonants, and the number that fit
/// neither of those categories. One approach is to use isalpha() to
/// discriminate between words beginning with letters and those that don’t and
/// then use an if or switch statement to further identify those passing the
/// isalpha() test that begin with vowels. A sample run might look like this:
///
/// Enter words (q to quit):
/// The 12 awesome oxen ambled
/// quietly across 15 meters of lawn. q
/// 5 words beginning with vowels
/// 4 words beginning with consonants
/// 2 others
///
/// \author Wang Jiayuan
/// \since 2018-09-28 21:43:02 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

using namespace std;

int main()
{
    int num_of_vowels = 0;
    int num_of_consonants = 0;
    int num_of_others = 0;

    string word;
    while (cin >> word && word != "q")
    {
        auto letter = word[0];
        letter = tolower(letter);
        if (isalpha(letter))
        {
            if (letter == 'a' || letter == 'e' || letter == 'i' ||
                letter == 'o' || letter == 'u')
            {
                ++num_of_vowels;
            }
            else
            {
                ++num_of_consonants;
            }
        }
        else
        {
            ++num_of_others;
        }
    }

    cout << num_of_vowels << " words beginning with vowels"
         << "\n";
    cout << num_of_consonants << " words beginning with consonants"
         << "\n";
    cout << num_of_others << " others"
         << "\n";

    return 0;
}
