//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a solution to the programming exercise 01 in chapter 10 of Cpp
/// Primer Plus 6th Edition.
///
/// Provide method definitions for the class described in Chapter Review
/// Question 5 and write a short program that illustrates all the features.
///
/// Define a class to represent a bank account. Data members should include the
/// depositor’s name, the account number (use a string), and the balance. Member
/// functions should allow the following:
///
///     Creating an object and initializing it.
///
///     Displaying the depositor’s name, account number, and balance
///
///     Depositing an amount of money given by an argument
///
///     Withdrawing an amount of money given by an argument
///
/// Just show the class declaration, not the method implementations.
/// (Programming Exercise 1 provides you with an opportunity to write the
/// implementation.)
///
/// \author Wang Jiayuan
/// \since 2018-11-02 09:56:16 CST
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

class Account
{
public:
    Account(string name, string no, double balance);

    /// Display the depositor’s name, account number, and balance
    void Display();
    /// Deposit an amount of money
    /// \return current balance
    double Deposit(double amount);
    /// Withdraw an amount of money
    /// \return current balance
    double Withdraw(double amount);

private:
    string m_name;
    string m_no;
    double m_balance;
};

int main()
{
    Account a("Ma Yun", "6217000000000000000", 1e9);
    a.Display();
    cout << "\n";

    cout << "Deposit " << a.Deposit(1e6) << ":"
         << "\n";
    a.Display();
    cout << "\n";

    cout << "Withdraw " << a.Withdraw(1e8) << ":"
         << "\n";
    a.Display();
    cout << "\n";

    return 0;
}

Account::Account(string name, string no, double balance)
    : m_name(name), m_no(no), m_balance(balance)
{
}

void Account::Display()
{
    cout << "Name:    " << m_name << "\n";
    cout << "No.      " << m_no << "\n";
    cout << "Balance: " << m_balance << "\n";
}
double Account::Deposit(double amount)
{
    return m_balance += amount;
}
double Account::Withdraw(double amount)
{
    return m_balance -= amount;
}
