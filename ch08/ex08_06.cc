//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 06 in chapter 08 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a template function maxn() that takes as its arguments an array of
/// items of type T and an integer representing the number of elements in the
/// array and that returns the largest item in the array. Test it in a program
/// that uses the function template with an array of six int value and an array
/// of four double values. The program should also include a specialization that
/// takes an array of pointers-to-char as an argument and the number of pointers
/// as a second argument and that returns the address of the longest string. If
/// multiple strings are tied for having the longest length, the function should
/// return the address of the first one tied for longest. Test the
/// specialization with an array of five string pointers.
///
/// \author Wang Jiayuan
/// \since 2018-10-17 00:19:34 CST
///
//===----------------------------------------------------------------------===//
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

template <typename T, size_t N>
T maxn(const T (&arr)[N])
{
    T max_value = arr[0];
    for_each(arr, arr + N, [&](const T& e) { max_value = max(max_value, e); });
    return max_value;
}

template <size_t N>
const char* maxn(const char* (&arr)[N])
{
    const char* ret = arr[0];
    for_each(arr, arr + N,
             [&](const char* e) { ret = strlen(ret) < strlen(e) ? e : ret; });
    return ret;
}

int main()
{
    int integers[] = {1, 2, 3, 4, 5, 6};
    cout << maxn(integers) << "\n";
    double decimals[] = {4.1, 3.1, 2.2, 1.1};
    cout << maxn(decimals) << "\n";
    const char* strs[] = {"a", "The 1st one of the longest strings",
                          "The 2nd one of the longest strings", "b", "c"};
    cout << maxn(strs) << "\n";

    return 0;
}
