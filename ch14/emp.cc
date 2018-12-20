//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 05 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex14_05.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 17:12:49 CST
///
//===----------------------------------------------------------------------===//

#include "emp.h"

#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

abstr_emp::abstr_emp() : fname(), lname(), job()
{
}
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
                     const std::string& j)
    : fname(fn), lname(ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
    cout << "First Name: " << fname << "\n";
    cout << "Last Name: " << lname << "\n";
    cout << "Job: " << job << "\n";
}

void abstr_emp::SetAll()
{
    cout << "Input First Name: ";
    getline(cin, fname);
    cout << "Input Last Name: ";
    getline(cin, lname);
    cout << "Input the Job: ";
    getline(cin, job);
}

// just displays first and last name
std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
    os << e.lname << ", " << e.fname;
    return os;
}

abstr_emp::~abstr_emp()
{
}

employee::employee() : abstr_emp()
{
}

employee::employee(const std::string& fn, const std::string& ln,
                   const std::string& j)
    : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Position: Employee"
         << "\n";
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

manager::manager() : abstr_emp()
{
    inchargeof = 0;
}

manager::manager(const std::string& fn, const std::string& ln,
                 const std::string& j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Position: Manager"
         << "\n";
    cout << "Number of people in charge: " << inchargeof << "\n";
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the number of people the manager is in charge of: ";
    cin >> inchargeof;
}

fink::fink() : abstr_emp(), reportsto("")
{
}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j,
           const std::string& rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp& e, const std::string& rpo)
    : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto)
{
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Position: Fink"
         << "\n";
    cout << "Reports to " << reportsto << "\n";
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter whomever is reported to: ";
    getline(cin, reportsto);
}

// highfink class methods (inherits manager and fink classes publically)
highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string& fn, const std::string& ln,
                   const std::string& j, const std::string& rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink& f, int ico)
    : abstr_emp(f), manager(f, ico), fink()
{
}

highfink::highfink(const manager& m, const std::string& rpo)
    : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Position: Highfink"
         << "\n";
    cout << "Number of people in charge: " << InChargeOf() << "\n";
    cout << "Reports to " << ReportsTo() << "\n";
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the number of people managed: ";
    cin >> InChargeOf();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略一行
    cout << "Enter whomever is reported to: ";
    getline(cin, ReportsTo());
}
