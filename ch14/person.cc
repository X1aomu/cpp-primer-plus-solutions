//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 04 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex14_04.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 16:06:58 CST
///
//===----------------------------------------------------------------------===//

#include "person.h"

#include <iostream>
#include <random>

using namespace std;

void Person::Show() const
{
    cout << "First Name: " << m_firstName << "\n";
    cout << "Last Name: " << m_lastName << "\n";
}
void Person::Set()
{
    cout << "Input First Name: ";
    getline(cin, m_firstName);
    cout << "Input Last Name: ";
    getline(cin, m_lastName);
}

void Gunslinger::Show() const
{
    Person::Show();
    cout << "Draw Time: " << m_drawTime << "\n";
    cout << "Notches:  " << m_notches << "\n";
}
void Gunslinger::Set()
{
    Person::Set();
    cout << "Input Draw Time (decimal): ";
    cin >> m_drawTime;
    cout << "Input Number of Notches (integer): ";
    cin >> m_notches;
}

void PokerPlayer::Show() const
{
    Person::Show();
    cout << "Card Value: " << Draw() << "\n";
}
void PokerPlayer::Set()
{
    Person::Set();
}
int PokerPlayer::Draw() const
{
    static random_device r;
    static default_random_engine randomEngine(r());
    static uniform_int_distribution<size_t> randomDist(1, 52);

    return randomDist(randomEngine);
}

void BadDude::Show() const
{
    Person::Show();
    cout << "Notches:  " << Notches() << "\n";
    cout << "Draw Time: " << GDraw() << "\n";
    cout << "Next Card Drawn: " << CDraw() << "\n";
}
void BadDude::Set()
{
    Gunslinger::Set();
}
