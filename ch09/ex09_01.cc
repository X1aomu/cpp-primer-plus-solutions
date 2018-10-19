//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 09 of Cpp Primer Plus 6th Edition.
///
/// Here is a header file:
/// \code
///     const int Len = 40;
///     struct golf
///     {
///         char fullname[Len];
///         int handicap;
///     };
///     // non-interactive version:
///     // function sets golf structure to provided name, handicap
///     // using values passed as arguments to the function
///     void setgolf(golf& g, const char* name, int hc);
///     // interactive version:
///     // function solicits name and handicap from user
///     // and sets the members of g to the values entered
///     // returns 1 if name is entered, 0 if name is empty string
///     int setgolf(golf& g);
///     // function resets handicap to new value
///     void handicap(golf& g, int hc);
///     // function displays contents of golf structure
///     void showgolf(const golf& g);
/// \endcode
///
/// Note that setgolf() is overloaded. Using the first version of setgolf()
/// would look like this:
/// \code
///     golf ann;
///     setgolf(ann, "Ann Birdfree", 24);
/// \endcode
///
/// The function call provides the information that’s stored in the ann
/// structure. Using the second version of setgolf() would look like this:
/// \code
///     golf andy;
///     setgolf(andy);
/// \endcode
///
/// The function would prompt the user to enter the name and handicap and store
/// them in the andy structure. This function could (but doesn’t need to) use
/// the first version internally.
///
/// Put together a multifile program based on this header. One file, named
/// golf.cpp, should provide suitable function definitions to match the
/// prototypes in the header file. A second file should contain main() and
/// demonstrate all the features of the prototyped functions. For example, a
/// loop should solicit input for an array of golf structures and terminate when
/// the array is full or the user enters an empty string for the golfer’s name.
/// The main() function should use only the prototyped functions to access the
/// golf structures.
///
/// \author Wang Jiayuan
/// \since 2018-10-18 17:42:55 CST
///
/// \sa golf.h golf.cc
///
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <iostream>
#include <sstream>

#include "golf.h"

using namespace std;

int main()
{
    size_t n;
    cout << "How many golf player do you want to enter? ";
    cin >> n;

    golf* players = new golf[n];
    size_t num_of_input = 0;

    // solicit input for the array of golf players
    cout << "Enter players' information below. You can terminate the input by "
            "enter an empty name.\n";
    for (size_t i = 0; i != n; ++i)
    {
        if (setgolf(players[i]) == 0)
        {
            cout << "Input ended by user\n";
            break;
        }
        cout << "\n";
        ++num_of_input;
    }

    bool ok = false;
    while (!ok)
    {
        cout << "\n";
        cout << "Here are the players you input above:\n";
        cout << "============== Player list start ==============\n";
        for (size_t i = 0; i != num_of_input; ++i)
        {
            cout << "\n";
            cout << "No. " << i + 1 << "\n";
            showgolf(players[i]);
        }
        cout << "\n";
        cout << "=============== Player list end ===============\n";
        cout << "Total number of players is " << num_of_input << "\n";
        cout << "\n";

        cout << "Are you ok with them? ";
        char answer;
        cin >> answer;
        switch (answer)
        {
        case 'Y':
        case 'y':
            ok = true;
            break;
        default:
            cout << "Which player (No.) to modify? ";
            unsigned number;
            cin >> number;
            if (number > num_of_input)
            {
                cout << "Player No. " << number << " doesn't exist.\n";
                break;
            }
            golf& p = players[number - 1];
            cout << "The player to modify is: \n";
            showgolf(p);
            cin.ignore();
            string line;
            // change name
            cout << "Enter the new name (enter nothing to leave it "
                    "unchanged): ";
            getline(cin, line);
            if (!line.empty())
            {
                setgolf(p, line.c_str(), p.handicap);
            }
            // change handicap
            cout << "Enter the new handicap (enter nothing to leave it "
                    "unchanged): ";
            getline(cin, line);
            if (!line.empty())
            {
                istringstream iss(line);
                int hc;
                iss >> hc;
                handicap(p, hc);
            }
            break;
        }
    }

    delete[] players;

    return 0;
}
