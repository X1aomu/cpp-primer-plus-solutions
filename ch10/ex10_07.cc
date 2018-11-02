//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 07 in chapter 10 of Cpp
/// Primer Plus 6th Edition.
///
/// A Betelgeusean plorg has these properties:
///
/// Data
///
///     A plorg has a name with no more than 19 letters.
///
///     A plorg has a contentment index (CI), which is an integer.
///
/// Operations
///
///     A new plorg starts out with a name and a CI of 50.
///
///     A plorg’s CI can change.
///
///     A plorg can report its name and CI.
///
///     The default plorg has the name "Plorga".
///
/// Write a Plorg class declaration (including data members and member function
/// prototypes) that represents a plorg.Write the function definitions for the
/// member functions. Write a short program that demonstrates all the features
/// of the Plorg class.
///
/// \author Wang Jiayuan
/// \since 2018-11-02 13:35:03 CST
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

class Plorg
{
public:
    Plorg(string name = "Plorga", int contentment_index = 50);

    void SelfReport() const;
    void SetContentmentIndex(int ci);

private:
    string m_name;
    int m_ci;
};

int main()
{
    Plorg a;
    a.SelfReport();

    Plorg b("Plorgb");
    b.SelfReport();

    Plorg c("Plorgc", 100);
    c.SelfReport();

    Plorg d("Plorgd");
    d.SetContentmentIndex(80);
    d.SelfReport();

    return 0;
}

Plorg::Plorg(string name, int contentment_index)
    : m_name(name), m_ci(contentment_index)
{
}

void Plorg::SelfReport() const
{
    cout << "Name:              " << m_name << "\n";
    cout << "Contentment index: " << m_ci << "\n";
}
void Plorg::SetContentmentIndex(int ci)
{
    m_ci = ci;
}
