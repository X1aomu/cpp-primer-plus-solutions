//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 06 in
/// chapter 11 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex11_06.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-08 20:49:04 CST
///
/// \sa ch11/stonewt6.h ch11/stonewt6.cc
///
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "stonewt6.h"

using namespace std;

int main()
{
    using namespace std;

    const int Size = 6;

    Stonewt stArr[Size] = {Stonewt(11, 4), Stonewt(200), Stonewt(150)};

    for (int i = 3; i < Size; i++)
    {
        cout << "Enter the number of pounds for the Stonewt object";
        cout << " at position " << i + 1 << ": ";
        double pounds;
        cin >> pounds;
        stArr[i] = Stonewt(pounds);
    }

    Stonewt reference(11,0);

    Stonewt min = stArr[0];
    Stonewt max = stArr[0];

    int num_gt_stone11 = 0;
    for (int i = 0; i < Size; ++i)
    {
        if (stArr[i] > max)
            max = stArr[i];
        else if (stArr[i] < min)
            min = stArr[i];

        if (stArr[i] >= reference)
            num_gt_stone11++;
    }

    cout << "The heaviest object weighed: " << max << " pounds." << "\n";
    cout << "The lightest object weighed: " << min << " pounds." << "\n";
    cout << "The number of objects that weighed above " << reference;
    cout << " pounds was " << num_gt_stone11 << "\n";

    return 0;
}
