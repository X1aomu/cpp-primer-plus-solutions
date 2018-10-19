//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 01 in
/// chapter 09 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex09_01.cc.
///
/// \author Wang Jiayuan
/// \since 2018-10-18 18:33:53 CST
///
//===----------------------------------------------------------------------===//
#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;

struct golf
{
    char fullname[Len];
    int handicap;
};

/// non-interactive version:
/// function sets golf structure to provided name, handicap
/// using values passed as arguments to the function
void setgolf(golf& g, const char* name, int hc);

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
