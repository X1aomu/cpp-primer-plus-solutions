// This file is a solution to a programming exercise of Cpp Primer Plus 6th
// Edition.
// @Chapter 02
// @Exercise 03
//
// @Author Wang Jiayuan
// @Created 2018-09-06 23:13:38 CST
#include <iostream>

using namespace std;

void firstFunc() { cout << "Three blind mice" << endl; }

void secondFunc() { cout << "See how they run" << endl; }

int main()
{
  firstFunc();
  firstFunc();
  secondFunc();
  secondFunc();
  return 0;
}
