//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 06 in chapter 06 of Cpp
/// Primer Plus 6th Edition.
///
/// Put together a program that keeps track of monetary contributions to the
/// Society for the Preservation of Rightful Influence. It should ask the user
/// to enter the number of contributors and then solicit the user to enter the
/// name and contribution of each contributor. The information should be stored
/// in a dynamically allocated array of structures. Each structure should have
/// two members: a character array (or else a string object) to store the name
/// and a double member to hold the amount of the contribution. After reading
/// all the data, the program should display the names and amounts donated for
/// all donors who contributed $10,000 or more. This list should be headed by
/// the label Grand Patrons. After that, the program should list the remaining
/// donors. That list should be headed Patrons. If there are no donors in one of
/// the categories, the program should print the word “none.” Aside from
/// displaying two categories, the program need do no sorting.
///
/// \author Wang Jiayuan
/// \since 2018-09-28 20:34:26 CST
///
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Donor
{
    string name;
    double amount;
};

void print(const vector<Donor>& donors);

int main()
{
    // get number of donors
    cout << "Enter number of donors to be input: ";
    int num_of_donors;
    cin >> num_of_donors;
    if (num_of_donors < 1)
    {
        cout << "Invalid input! Quit."
             << "\n";
        return 0;
    }

    // allocate donor_list
    Donor* donor_list = new Donor[num_of_donors];

    // get donors
    for (int i = 0; i < num_of_donors; ++i)
    {
        cin.ignore();
        cout << "Enter the donor's name: ";
        string name;
        getline(cin, name);

        cout << "Enter the contribution amount of " << name << ": ";
        double amount;
        cin >> amount;

        if (!cin)
        {
            cout << "Invalid input! Quit."
                 << "\n";
            return 0;
        }

        donor_list[i] = {name, amount};
    }

    vector<Donor> grand_patrons;
    vector<Donor> patrons;
    for_each(donor_list, donor_list + num_of_donors, [&](const Donor& d) {
        if (d.amount >= 10000.00)
        {
            grand_patrons.push_back(d);
        }
        else
        {
            patrons.push_back(d);
        }
    });

    // print Grand Patrons
    cout << "\n";
    cout << "Grand Patrons"
         << "\n";
    cout << "=========================================="
         << "\n";
    print(grand_patrons);

    // print Patrons
    cout << "\n";
    cout << "Patrons"
         << "\n";
    cout << "=========================================="
         << "\n";
    print(patrons);

    // release resources
    delete[] donor_list;

    return 0;
}

void print(const vector<Donor>& donors)
{
    if (donors.empty())
    {
        cout << "none."
             << "\n";
        return;
    }

    cout << "Amount"
         << "\t"
         << "Name"
         << "\n";
    for (auto d : donors)
    {
        cout << "$" << d.amount << "\t" << d.name << "\n";
    }
}
