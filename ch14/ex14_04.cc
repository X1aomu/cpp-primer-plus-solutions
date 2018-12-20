//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 04 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// A Person class holds the first name and the last name of a person. In
/// addition to its constructors, it has a Show() method that displays both
/// names. A Gunslinger class derives virtually from the Person class. It has a
/// Draw() member that returns a type double value representing a gunslinger’s
/// draw time. The class also has an int member representing the number of
/// notches on a gunslinger’s gun. Finally, it has a Show() function that
/// displays all this information.
///
/// A PokerPlayer class derives virtually from the Person class. It has a Draw()
/// member that returns a random number in the range 1 through 52, representing
/// a card value. (Optionally, you could define a Card class with suit and face
/// value members and use a Card return value for Draw().) The PokerPlayer class
/// uses the Person show() function. The BadDude class derives publicly from the
/// Gunslinger and PokerPlayer classes. It has a Gdraw() member that returns a
/// bad dude’s draw time and a Cdraw() member that returns the next card drawn.
/// It has an appropriate Show() function. Define all these classes and methods,
/// along with any other necessary methods (such as methods for setting object
/// values) and test them in a simple program similar to that in Listing 14.12.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 15:08:46 CST
///
//===----------------------------------------------------------------------===//

#include <cstring>
#include <iostream>

#include "person.h"

const int SIZE = 5;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    Person* players[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the person category:\n"
             << "g: gunslinger, p: poker player, "
             << "b: bad dude, q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'g':
            players[ct] = new Gunslinger;
            break;
        case 'p':
            players[ct] = new PokerPlayer;
            break;
        case 'b':
            players[ct] = new BadDude;
            break;
        }
        cin.get();
        players[ct]->Set();
    }
    cout << "\nHere is your players:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        players[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete players[i];
    cout << "Bye.\n";
    return 0;
}
