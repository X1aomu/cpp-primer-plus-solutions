//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 05 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// The Bank of Heather has performed a study showing that ATM customers won’t
/// wait more than one minute in line. Using the simulation from Listing 12.10,
/// find a value for number of customers per hour that leads to an average wait
/// time of one minute. (Use at least a 100-hour trial period.)
///
/// \author Wang Jiayuan
/// \since 2018-11-16 16:45:00 CST
///
/// \sa ch12/queue.h ch12/queue.cc
///
//===----------------------------------------------------------------------===//

#include "queue.h"

#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

#include <iostream>

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    // setting things up
    std::srand(std::time(0)); // random initializing of rand()
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    Item temp;          // new customer data
    long turnaways;     // turned away by full queue
    long customers;     // joined the queue
    long served;        // served during the simulation
    long sum_line;      // cumulative line length
    int wait_time;      // time until autoteller is free
    long line_wait;     // cumulative time in line
    double perhour = 61; // average # of arrival per hour
    do
    {
        --perhour; // customers per hour is decreased from 60

        // initializing
        Queue line(qs); // line queue holds up to qs people
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time = 0;
        line_wait = 0;

        double min_per_cust; // average time between arrivals
        min_per_cust = MIN_PER_HR / perhour;

        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line.isfull())
                {
                    turnaways++;
                }
                else
                {
                    customers++;
                    temp.set(cycle);
                    // cycle = time of arrival
                    line.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);       // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }
    } while ((double)line_wait / served > 1.0);

    // reporting results
    if (customers > 0)
    {
        auto f = cout.flags();
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: " << (double)line_wait / served
             << " minutes\n";
        cout.flags(f);
    }
    else
    {
        cout << "No customers!\n";
    }

    cout << "The average wait time is approximately one minute "
            "when the value for number of customers per hour is: "
         << perhour << "\n";
    cout << "Done!\n";

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
