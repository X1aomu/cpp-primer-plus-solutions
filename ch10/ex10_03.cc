//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 03 in
/// chapter 10 of Cpp Primer Plus 6th Edition.
///
/// Do Programming Exercise 1 from Chapter 9 but replace the code shown there
/// with an appropriate golf class declaration. Replace setgolf(golf &, const
/// char*, int) with a constructor with the appropriate argument for providing
/// initial values. Retain the interactive version of setgolf() but implement it
/// by using the constructor. (For example, for the code for setgolf(), obtain
/// the data, pass the data to the constructor to create a temporary object, and
/// assign the temporary object to the invoking object, which is *this.)
///
/// \author Wang Jiayuan
/// \since 2018-11-02 11:25:23 CST
///
/// \sa ch10/golf.h ch10/golf.cc ch09/ex09_01.cc ch09/golf.h ch09/golf.cc
///
//===----------------------------------------------------------------------===//

#include "golf.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

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
                p = golf(line.c_str(), p.handicap);
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
