//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 05 in chapter 08 of Cpp
/// Primer Plus 6th Edition.
///
/// Write a template function max5() that takes as its argument an array of five
/// items of type T and returns the largest item in the array. (Because the size
/// is fixed, it can be hard-coded into the loop instead of being passed as an
/// argument.) Test it in a program that uses the function with an array of five
/// int value and an array of five double values.
///
/// \author Wang Jiayuan
/// \since 2018-10-16 23:49:26 CST
///
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
T max5(const T array[])
{
    T ret = array[0];
    for_each(array, array + 5, [&](const T& e) {
        if (e > ret)
            ret = e;
    });
    return ret;
}

int main()
{
    int integers[] = {1, 2, 3, 4, 5};
    double decimals[] = {5.0, 4.0, 3.0, 2.0, 1.0};

    cout << max5<int>(integers) << "\n";
    cout << max5<double>(decimals) << "\n";

    return 0;
}
