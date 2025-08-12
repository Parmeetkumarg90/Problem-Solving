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
    Node<valType> *getNode(valType val);

    // for matching various type of data structure for all operations
    bool isMatched(const string &val1, const string &val2);
    bool isMatched(const char *val1, const char *val2);
    bool isMatched(int val1, int val2);

public:
    LL();
    ~LL();
    // insertion
    void insertionAtBegin(valType val);
    void insertionAtMiddle(int index, valType val);
    void insertionAtEnd(valType val);

    // deletion
    void deletionAtBegin();
    void deletionAtMiddle(valType val);
    void deletionAtEnd();

    // searching
    Node<valType> *isPresent(int index);

    // display
    void display();

    // clear whole linked list
    void clear();

    // operator overloading for creating new obj
    LL<valType> operator=(LL<valType> *obj);
};

#include "./library.cpp"

#endif