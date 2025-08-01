#include <iostream>
// #include "HashMap.h"
using namespace std;

class Node // used for applying open chaining collision if happend
{
private:
    int val, key;
    Node *next;

public:
    // constructors
    Node(int key, int val);
    ~Node() {}

    // member functions
    int getKey();
    int getValue();
    Node *getNext();
    void setNext(Node *next);
};

class HashMap
{
private:
    int size = 10, totalElements = 0;
    Node **HashTable;
    void resizeHash();

public:
    // constructors
    HashMap();
    ~HashMap();
    HashMap(HashMap &obj);

    // member functions
    void hashInsertion(int key, int val);
    void hashDeletion(int key);
    Node *getPreviousNodeForKey(int key);
    bool isPresent(int key);
    void hashDisplay();
    int hashFunction(int key);
    void clear();
    bool empty();
    int count();
};

Node::Node(int key, int value)
{ // constructor for initialization of node
    this->val = value;
    this->key = key;
    this->next = nullptr;
}

int Node::getKey()
{
    return key;
}

int Node::getValue()
{
    return val;
}

Node *Node::getNext()
{
    return next;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

HashMap::HashMap()
{
    size = 5;
    HashTable = new Node *[size]();
}

HashMap::HashMap(HashMap &obj)
{
    this->size = obj.size;
    this->totalElements = obj.totalElements;
    this->HashTable = new Node *[size]();
    for (int i = 0; i < obj.size; i++)
    {
        Node *objEachHead = obj.HashTable[i];
        while (objEachHead)
        {
            this->hashInsertion(objEachHead->getKey(), objEachHead->getValue());
            objEachHead = objEachHead->getNext();
        }
    }
}

HashMap::~HashMap()
{
    clear();
    if (HashTable)
    {
        delete[] HashTable;
    }
    HashTable = nullptr;
}

void HashMap::hashInsertion(int key, int val)
{
    int headPosition = hashFunction(key);
    if (!HashTable[headPosition]) // no node
    {
        HashTable[headPosition] = new Node(key, val); // insert at beginning
        cout << "\nKey-Value pair {" << key << "," << val << "} added Successfully";
        totalElements++;
        return;
    }
    Node *head = getPreviousNodeForKey(key), *headNode = HashTable[headPosition];
    if (head)
    {
        if (!head->getNext())
        {
            head->setNext(new Node(key, val)); // insert at end
        }
        else if (head->getNext() && head->getNext()->getKey() == key)
        {
            cout << "\nKey-Value pair {" << key << "," << val << "} already exists"; // found at middle
            return;
        }
    }
    else
    {
        if (headNode && headNode->getKey() == key)
        {
            cout << "\nKey-Value pair {" << key << "," << val << "} already exists"; // found at head
            return;
        }
    }
    totalElements++;
    cout << "\nKey-Value pair {" << key << "," << val << "} added Successfully";
    if (((totalElements * 100) / size) >= 75)
    {
        resizeHash();
    }
}

void HashMap::hashDeletion(int key)
{
    int headPosition = hashFunction(key);
    Node *headNode = HashTable[headPosition];
    if (!headNode) // not a single key-pair at position
    {
        cout << "\nHashTable is empty for this key";
        return;
    }
    Node *before = getPreviousNodeForKey(key);
    if (before)
    {
        Node *deletingNode = before->getNext();
        if (!deletingNode) // not found and currently at last node
        {
            cout << "Key-Value pair is not present in HashTable to delete";
        }
        else if (deletingNode && deletingNode->getKey() == key) // found pair
        {
            before->setNext(deletingNode->getNext());
            deletingNode->setNext(nullptr);
            cout << "Key-value pair {" << deletingNode->getKey() << "," << deletingNode->getValue() << "} deleted successfully";
            totalElements--;
            delete deletingNode;
        }
    }
    else if (headNode && headNode->getKey() == key) // found at head
    {
        HashTable[headPosition] = headNode->getNext() ? headNode->getNext() : nullptr;
        headNode->setNext(nullptr);
        cout << "Key-value pair {" << headNode->getKey() << "," << headNode->getValue() << "} deleted successfully";
        totalElements--;
        delete headNode;
    }
    else // not found
    {
        cout << "Key-Value pair is not present in HashTable to delete";
    }
}

Node *HashMap::getPreviousNodeForKey(int key)
{
    int headPosition = hashFunction(key);
    Node *prev = nullptr;
    if (!HashTable[headPosition])
    {
        cout << "\nHashTable is empty for this key";
    }
    else
    {
        Node *head = HashTable[headPosition];
        while (head)
        {
            if (head->getKey() == key) // key found
            {
                break;
            }
            prev = head;
            head = head->getNext();
        }
    }
    return prev;
}

void HashMap::hashDisplay() // display all pairs from the hashtable bucket
{
    cout << "{";
    Node *traverseEach = nullptr;
    for (int i = 0; i < size; i++)
    {
        traverseEach = HashTable[i]; // find all pairs at each location in map
        if (traverseEach)
        {
            while (traverseEach)
            {
                cout << "\n    {" << traverseEach->getKey() << "," << traverseEach->getValue() << "},";
                traverseEach = traverseEach->getNext();
            }
        }
    }
    cout << "\n}";
}

int HashMap::hashFunction(int key) // hashfunction for finding the index in the hashtable bucket
{
    return key % size;
}

void HashMap::clear() // clear the whole hashtable
{
    Node *traverse = nullptr, *deleteNode = nullptr;
    if (!HashTable)
    {
        cout << "\nHashTable is already empty";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        traverse = HashTable[i];
        while (traverse)
        {
            deleteNode = traverse;
            traverse = traverse->getNext();
            deleteNode->setNext(nullptr);
            delete deleteNode;
        }
        HashTable[i] = nullptr;
    }
    totalElements = 0;
    cout << "\nHashTable Cleared Successfully\n";
}

int HashMap::count() // count all pairs present in hashtable
{
    // int totalNodes = 0;
    // Node *traverse = nullptr;
    // for (int i = 0; i < size; i++)
    // {
    //     traverse = HashTable[i];
    //     while (traverse)
    //     {
    //         totalNodes++;
    //         traverse = traverse->getNext();
    //     }
    // }
    // return totalNodes;
    return totalElements;
}

bool HashMap::empty() // check if whole hashtable is empty or not
{
    // bool isEmpty = true;
    // Node *traverse = nullptr;
    // for (int i = 0; i < size; i++)
    // {
    //     traverse = HashTable[i];
    //     if (traverse)
    //     {
    //         return false;
    //     }
    // }
    // return isEmpty;
    return totalElements > 0;
}

bool HashMap::isPresent(int key)
{
    int headPosition = hashFunction(key);
    Node *headNode = HashTable[headPosition];
    if (headNode)
    {
        Node *before = getPreviousNodeForKey(key);
        if (before)
        {
            Node *matchedNode = before->getNext();
            if (matchedNode) // found pair
            {
                return true;
            }
        }
        else if (headNode->getKey() == key) // found at head
        {
            return true;
        }
    }
    return false;
}

void HashMap::resizeHash()
{
    int filledPercentage = (totalElements * 100) / size;
    if (filledPercentage < 75)
    {
        return;
    }
    else
    {
        Node **oldBucket = HashTable;
        HashTable = new Node *[size * 2]();
        for (int i = 0; i < size; i++)
        {
            Node *eachHead = oldBucket[i], *deleteNode = nullptr;
            while (eachHead)
            {
                hashInsertion(eachHead->getKey(), eachHead->getValue());
                deleteNode = eachHead;
                eachHead = eachHead->getNext();
                deleteNode->setNext(nullptr);
                delete deleteNode;
            }
        }
        size = size * 2;
        delete[] oldBucket;
    }
}