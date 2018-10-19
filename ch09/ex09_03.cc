//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 03 in chapter 09 of Cpp
/// Primer Plus 6th Edition.
///
/// Begin with the following structure declaration:
/// \code
///     struct chaff
///     {
///         char dross[20];
///         int slag;
///     };
/// \endcode
///
/// Write a program that uses placement new to place an array of two such
/// structures in a buffer. Then assign values to the structure members
/// (remembering to use strcpy() for the char array) and use a loop to display
/// the contents. Option 1 is to use a static array, like that in Listing 9.10,
/// for the buffer. Option 2 is to use regular new to allocate the buffer.
///
/// \author Wang Jiayuan
/// \since 2018-10-18 20:58:26 CST
///
//===----------------------------------------------------------------------===//
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

const int BUF_LEN = 1024;

char* buf[BUF_LEN];

int main()
{
    chaff* p = new (buf) chaff[2];

    strcpy(p[0].dross, "Dross 1");
    p[0].slag = 1;
    strcpy(p[1].dross, "Dross 2");
    p[1].slag = 2;

    for_each(p, p + 2, [](const chaff& e) {
        cout << "Dross: " << e.dross << ", "
             << "Slag: " << e.slag << "\n";
    });

    return 0;
}
