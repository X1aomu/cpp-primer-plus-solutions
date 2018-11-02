//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 03 in
/// chapter 10 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex10_03.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-02 12:22:29 CST
///
//===----------------------------------------------------------------------===//
#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;

struct golf
{
    golf() = default;
    golf(const char* name, int hc);
    char fullname[Len];
    int handicap;
};

/// interactive version:
/// function solicits name and handicap from user
/// and sets the members of g to the values entered
/// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf& g);

/// function resets handicap to new value
void handicap(golf& g, int hc);

/// function displays contents of golf structure
void showgolf(const golf& g);

#endif // GOLF_H_
