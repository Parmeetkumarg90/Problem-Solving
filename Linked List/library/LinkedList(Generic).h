#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

template <typename valType>
class Node
{
public:
    valType val;
    Node<valType> *next;
    Node(valType val);
};

template <typename valType>
class LL
{
private:
    int count = 0;
    Node<valType> *head;
    Node<valType> *getNode(int index); // not working

    // for matching various type of data structure for all operations
    bool isMatched(const string &val1, const string &val2);
    bool isMatched(const char *val1, const char *val2);
    bool isMatched(int val1, int val2);

public:
    LL();
    ~LL();
    // insertion
    void insertionAtBegin(valType val);
    void insertionAtMiddle(int index, valType val); // not working
    void insertionAtEnd(valType val);               // not working

    // deletion
    void deletionAtBegin();           // not working
    void deletionAtMiddle(int index); // not working
    void deletionAtEnd();             // not working

    // searching
    Node<valType> *isPresent(int index);

    // display
    void display();

    // clear whole linked list
    void clear();

    // operator overloading for creating new obj
    LL<valType> &operator=(const LL<valType> &obj); // not working
};

#include "./library.cpp"

#endif