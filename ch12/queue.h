//===----------------------------------------------------------------------===//
///
/// \file
/// This file is a part of the solution to the programming exercise 05 in
/// chapter 12 of Cpp Primer Plus 6th Edition.
///
/// For the problem description, see ex12_05.cc.
///
/// \author Wang Jiayuan
/// \since 2018-11-16 17:01:52 CST
///
//===----------------------------------------------------------------------===//

// Listing 12.10 queue.h

// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_

// This queue will contain Customer items

class Customer
{
private:
    long arrive;     // arrival time for customer
    int processtime; // processing time for customer
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node
    {
        Item item;
        struct Node* next;
    };
    enum
    {
        Q_SIZE = 10
    };
    // private class members
    Node* front;     // pointer to front of Queue
    Node* rear;      // pointer to rear of Queue
    int items;       // current number of items in Queue
    const int qsize; // maximum number of items in Queue
    //// preemptive definitions to prevent public copying
    //Queue(const Queue& q) : qsize(0) {}
    //Queue& operator=(const Queue& q) { return *this; }
    Queue(const Queue& q) = delete;
    Queue& operator=(const Queue& q) = delete;

public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item& item); // add item to end
    bool dequeue(Item& item);       // remove item from front
};

#endif
