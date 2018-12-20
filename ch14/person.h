//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 04 in
/// chapter 14 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex14_04.cc.
///
/// \author Wang Jiayuan
/// \since 2018-12-20 15:48:24 CST
///
//===----------------------------------------------------------------------===//

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person
{
private:
    std::string m_firstName;
    std::string m_lastName;

public:
    Person(){};
    Person(const std::string& firstName, const std::string& lastName)
        : m_firstName(firstName), m_lastName(lastName)
    {
    }
    virtual ~Person(){}; // base class destructor should be virtual

    virtual void Show() const;
    virtual void Set();
};

class Gunslinger : virtual public Person
{
private:
    double m_drawTime = 0.0;
    int m_notches = 0;

public:
    using Person::Person;
    Gunslinger(const std::string& firstName, const std::string& lastName,
               double drawTime, int notches)
        : Person(firstName, lastName), m_drawTime(drawTime), m_notches(notches)
    {
    }

    virtual void Show() const override;
    virtual void Set() override;
    double Draw() const { return m_drawTime; }
    int Notches() const { return m_notches; }
};

class PokerPlayer : virtual public Person
{
public:
    using Person::Person;

    virtual void Show() const override;
    virtual void Set() override;
    int Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    using Gunslinger::Gunslinger;
    double GDraw() const { return Gunslinger::Draw(); }
    double CDraw() const { return PokerPlayer::Draw(); }
    virtual void Show() const override;
    virtual void Set() override;
};

#endif // PERSON_H_
