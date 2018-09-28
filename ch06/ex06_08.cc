//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 08 in chapter 06 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a program that opens a text file, reads it character-by-character to
/// the end of the file, and reports the number of characters in the file.
///
/// \author Wang Jiayuan
/// \since 2018-09-28 22:09:15 CST
///
//===----------------------------------------------------------------------===//
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Loss parameter!"
             << "\n"
             << "Usage: ex06_08 INPUT_FILE"
             << "\n";
        return 1;
    }

    ifstream file(argv[1], ios_base::in);

    int num_of_characters = 0;
    char ch;
    file >> noskipws; // do not skip space characters
    while (file >> ch)
    {
        ++num_of_characters;
    }

    cout << "The number of characters in the file is " << num_of_characters
         << "\n";

    return 0;
}
