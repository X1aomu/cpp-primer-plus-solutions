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
#include <sstream>

#include <cctype>

using namespace std;

void print(string* str, int more = 0);

int main()
{
    string str = "I love C++ !!!";
    while (true)
    {
        cout << "Enter an integer as the second parameter(an empty line means "
                "there is no second parameter): "
             << "\n";
        string line;
        getline(cin, line);

        if (!cin)
            break;

        if (line.empty())
        {
            print(&str);
        }
        else
        {
            if (!isdigit(line[0])) // 非正常输入
                continue;
            istringstream iss(line);
            int n;
            iss >> n;
            print(&str, n);
        }
    }

    return 0;
}

void print(string* str, int more)
{
    static int count = 0;
    ++count;

    if (more)
    {
        for (int i = 0; i < count; ++i)
        {
            cout << *str << "\n";
        }
    }
    else
    {
        cout << *str << "\n";
    }
}
