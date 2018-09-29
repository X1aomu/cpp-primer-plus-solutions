//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 01 in chapter 08 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a function that normally takes one argument, the address of a string,
/// and prints that string once. However, if a second, type int, argument is
/// provided and is nonzero, the function should print the string a number of
/// times equal to the number of times that function has been called at that
/// point. (Note that the number of times the string is printed is not equal to
/// the value of the second argument; it is equal to the number of times the
/// function has been called.) Yes, this is a silly function, but it makes you
/// use some of the techniques discussed in this chapter. Use the function in a
/// simple program that demonstrates how the function works.
///
/// \author Wang Jiayuan
/// \since 2018-09-29 14:18:14 CST
///
//===----------------------------------------------------------------------===//
#include <iostream>

using namespace std;

void print(string* str, int more);

int main()
{
    string str = "ex08_01.cc";
    int n;
    while (true)
    {
        cout << "Enter the second parameter of the called function, which is "
                "an integer: ";
        cin >> n;
        if (!cin)
            break;
        print(&str, n);
    }

    return 0;
}

void print(string* str, int more)
{
    static int count = 0;
    ++count;

    cout << *str << "\n";

    if (more)
    {
        for (int i = 0; i < count; ++i)
        {
            cout << *str << "\n";
        }
    }
}
