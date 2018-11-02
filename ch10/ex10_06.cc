//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 06 in chapter 10 of Cpp
/// Primer Plus 6th Edition.
///
/// Here’s a class declaration:
/// \code
///     class Move
///     {
///     private:
///         double x;
///         double y;
///
///     public:
///         Move(double a = 0, double b = 0); // sets x, y to a, b
///         void showmove() const;            // shows current x, y values
///         // this function adds x of m to x of invoking object to get new x,
///         // adds y of m to y of invoking object to get new y, creates a new
///         // move object initialized to new x, y values and returns it
///         Move add(const Move& m) const;
///         void reset(double a = 0, double b = 0); // resets x,y to a, b
///     };
/// \endcode
///
/// Create member function definitions and a program that exercises the class.
///
/// \author Wang Jiayuan
/// \since 2018-11-02 13:07:57 CST
///
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0) : x(a), y(b) {}
    /// shows current x, y values
    void showmove() const;
    /// this function adds x of m to x of invoking object to get new x,
    /// adds y of m to y of invoking object to get new y, creates a new
    /// move object initialized to new x, y values and returns it
    Move add(const Move& m) const;
    /// resets x,y to a, b
    void reset(double a = 0, double b = 0);
};

int main()
{
    Move m;
    m.showmove();

    cout << "Add (5, 6)\n";
    m = m.add(Move(5, 6));
    m.showmove();

    cout << "Add (-4, 8)\n";
    m = m.add(Move(-4, 8));
    m.showmove();

    cout << "Reset to (-1, 1)\n";
    m.reset(-1, 1);
    m.showmove();

    cout << "Add (1, -1)\n";
    m = m.add(Move(1, -1));
    m.showmove();

    return 0;
}

void Move::showmove() const
{
    cout << "Current coordinates are (" << x << ", " << y << ")\n";
}
Move Move::add(const Move& m) const
{
    return Move(x + m.x, y + m.y);
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
