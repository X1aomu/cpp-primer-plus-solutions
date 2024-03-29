//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 02 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// Enhance the String class declaration (that is, upgrade string1.h to
/// string2.h) by oing the following:
///
///     a. Overload the + operator to allow you to join two strings into one.
///
///     b. Provide a stringlow() member function that converts all alphabetic
///     characters in a string to lowercase. (Don’t forget the cctype family of
///     character functions.)
///
///     c. Provide a stringup() member function that converts all alphabetic
///     characters in a string to uppercase.
///
///     d. Provide a member function that takes a char argument and returns the
///     number of times the character appears in the string.
///
/// Test your work in the following program:
///
/// \code
///     #include <iostream>
///     #include "string2.h"
///     using namespace std;
///     int main()
///     {
///         String s1(" and I am a C++ student.");
///         String s2 = "Please enter your name: ";
///         String s3;
///         cout << s2;              // overloaded << operator
///         cin >> s3;               // overloaded >> operator
///         s2 = "My name is " + s3; // overloaded =, + operators
///         cout << s2 << ".\n";
///         s2 = s2 + s1;
///         s2.stringup(); // converts string to uppercase
///         cout << "The string\n"
///              << s2 << "\ncontains " << s2.has('A')
///              << " 'A' characters in it.\n";
///         s1 = "red";
///         // String(const char *),
///         // then String & operator=(const String&)
///         String rgb[3] = {String(s1), String("green"), String("blue")};
///         cout << "Enter the name of a primary color for mixing light: ";
///         String ans;
///         bool success = false;
///         while (cin >> ans)
///         {
///             ans.stringlow(); // converts string to lowercase
///             for (int i = 0; i < 3; i++)
///             {
///                 if (ans == rgb[i]) // overloaded == operator
///                 {
///                     cout << "That's right!\n";
///                     success = true;
///                     break;
///                 }
///             }
///             if (success)
///                 break;
///             else
///                 cout << "Try again!\n";
///         }
///         cout << "Bye\n";
///         return 0;
///     }
/// \endcode
///
/// Your output should look like this sample run:
///
///     Please enter your name: Fretta Farbo
///     My name is Fretta Farbo.
///     The string
///     MY NAME IS FRETTA FARBO AND I AM A C++ STUDENT.
///     contains 6 'A' characters in it.
///     Enter the name of a primary color for mixing light: yellow
///     Try again!
///     BLUE
///     That's right!
///     Bye
///
/// \author Wang Jiayuan
/// \since 2018-11-16 10:55:09 CST
///
/// \sa ch12/string2.h ch12/string2.cc ch12/string1.h ch12/string1.cc
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include "string2.h"

using namespace std;

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;              // overloaded << operator
    cin >> s3;               // overloaded >> operator
    s2 = "My name is " + s3; // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase
    cout << "The string\n"
         << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red";
    // String(const char *),
    // then String & operator=(const String&)
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}
