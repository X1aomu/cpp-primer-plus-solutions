//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to an optional exercise provided by the instructor
/// in the course of teaching Cpp Primer Plus 6th Edition.
///
/// Chapter: 02
///
/// Description:
///
/// Define a struct to store name, sex and birthday of a student and then
/// implement input and output of two student's information in main function.
/// Also use class instead of struct to meet the requirements.
///
/// \author Wang Jiayuan
/// \since 2018-09-07 09:56:42 CST
///
//===----------------------------------------------------------------------===//
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

enum Sex
{
    Male,
    Female
};

struct Date
{
    int year;
    int month;
    int day;

    bool isValid();
};
ostream& operator<<(ostream& os, const Date& date);
istream& operator>>(istream& is, Date& date);

class Student
{
    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);

public:
    Student() = default;
    Student(string name, Sex sex, Date birthday)
        : name(name), sex(sex), birthday(birthday)
    {
    }

private:
    string name;
    Sex sex;
    Date birthday;
};
ostream& operator<<(ostream& os, const Student& s);
istream& operator>>(istream& is, Student& s);

int main()
{
    const string prompt =
            "Input a student's information(name sex birthday) in one line: ";
    const string errmsg = "Invalid input, please try again: ";

    Student a;
    cout << prompt;
    while (!(cin >> a))
    {
        cout << errmsg;
        cin.clear();
    }
    cout << a;

    Student b;
    cout << prompt;
    while (!(cin >> b))
    {
        cout << errmsg;
        cin.clear();
    }
    cout << b;

    return 0;
}

bool Date::isValid()
{
    if (year < 0 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (day == 31)
        if (month == 4 || month == 6 || month == 9 || month == 11)
            return false;
    if (month == 2 && day == 29)
        if (!(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            return false;
    return true;
}

ostream& operator<<(ostream& os, const Date& date)
{
    os << setw(4) << setfill('0') << date.year << "-" << setw(2) << date.month
       << "-" << setw(2) << date.day;
    return os;
}
istream& operator>>(istream& is, Date& date)
{
    static auto isDelimiterValid = [](char d) -> bool {
        if (d == '-' || d == '.' || d == '/')
            return true;
        else
            return false;
    };
    is >> date.year;
    char d;
    d = is.get();
    if (!isDelimiterValid(d))
        is.setstate(ios_base::failbit);
    is >> date.month;
    if (is.get() != d) // second delimiter dosen't match the previous one
        is.setstate(ios_base::failbit);
    is >> date.day;

    if (!date.isValid())
        is.setstate(ios_base::failbit);

    return is;
}

ostream& operator<<(ostream& os, const Student& s)
{
    os << "Student information:" << endl;
    os << "\tName: " << s.name << endl;
    os << "\tSex: " << ((s.sex == Sex::Male) ? "Male" : "Female") << endl;
    os << "\tBirthday: " << s.birthday << endl;
    return os;
}
istream& operator>>(istream& is, Student& s)
{
    Student backup = s;

    string line;
    getline(is, line);
    istringstream iss(line);

    iss >> s.name;

    string malePattern = "[Mm]ale";
    string femalePattern = "[Ff]emale";
    regex male(malePattern);
    regex female(femalePattern);
    string sex;
    iss >> sex;
    if (regex_match(sex.begin(), sex.end(), male))
    {
        s.sex = Sex::Male;
    }
    else if (regex_match(sex.begin(), sex.end(), female))
    {
        s.sex = Sex::Female;
    }
    else
    {
        is.setstate(ios_base::failbit); // failed to get information
        return is;
    }

    iss >> s.birthday;

    if (!iss)
        is.setstate(ios_base::failbit);
    return is;
}
