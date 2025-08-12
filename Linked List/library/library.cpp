#include "./LinkedList(Generic).h"

using namespace std;

template <typename valType>
Node<valType>::Node(valType val)
{
    this->val = val;
    this->next = nullptr;
}

template <typename valType>
LL<valType>::LL()
{
    head = nullptr;
    count = 0;
}

template <typename valType>
LL<valType>::~LL()
{
    clear();
}

template <typename valType>
void LL<valType>::clear()
{
    Node<valType> *deleteNode = nullptr;
    while (head)
    {
        deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        deleteNode = nullptr;
    }
    head = nullptr;
    count = 0;
}

template <typename valType>
Node<valType> *LL<valType>::getNode(int index)
{
    if (count < index || index < 0 || !head)
    {
        cout << "Index is out of range";
        return nullptr;
    }
    Node<valType> *traverse = head;
    while (traverse && index > 1)
    {
        index--;
        traverse = traverse->next;
    }
    return traverse;
}

template <typename valType>
void LL<valType>::insertionAtBegin(valType val)
{
    cout << "\n";
    Node<valType> *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    count++;
    cout << "Element inserted successfully";
}

template <typename valType>
void LL<valType>::insertionAtMiddle(int index, valType val)
{
    cout << "\n";
    if (count < index || index < 0 || !head)
    {
        cout << "Index is out of range";
        return;
    }
    Node<valType> *traverse = head, *newNode = new Node(val);
    while (traverse && index > 1)
    {
        index--;
        traverse = traverse->next;
    }
    newNode->next = traverse->next;
    traverse->next = newNode;
    count++;
    cout << "Element inserted successfully";
}

template <typename valType>
void LL<valType>::insertionAtEnd(valType val)
{
    cout << "\n";
    Node<valType> *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else if (!head->next)
    {
        head->next = newNode;
    }
    else
    {
        Node<valType> *traverse = head;
        while (traverse->next)
        {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }
    count++;
    cout << "Element inserted successfully";
}

template <typename valType>
void LL<valType>::deletionAtBegin()
{
    cout << "\n";
    if (!head)
    {
        cout << "\nListNode is empty";
        return;
    }
    else if (!head->next)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node<valType> *deleteNode = head;
        head = head->next;
        deleteNode->next = nullptr;
        delete deleteNode;
        deleteNode = nullptr;
    }
    cout << "Element deleted";
    count--;
}

template <typename valType>
void LL<valType>::deletionAtMiddle(int index)
{
    cout << "\n";
    if (!head)
    {
        cout << "\nListNode is empty";
        return;
    }
    if (isMatched(val, head->val))
    {
        if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<valType> *deleteNode = head;
            head = head->next;
            deleteNode->next = nullptr;
            delete deleteNode;
        }
        count--;
        cout << "Element deleted";
        return;
    }
    Node<valType> *nodeBeforeMatched = getNode(val);
    if (!nodeBeforeMatched)
    {
        cout << "Element not found";
    }
    else
    {
        Node<valType> *temp = nodeBeforeMatched->next;
        nodeBeforeMatched->next = nodeBeforeMatched->next->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
        cout << "Element deleted";
        count--;
    }
}

template <typename valType>
void LL<valType>::deletionAtEnd()
{
    cout << "\n";
    if (!head)
    {
        cout << "\nListNode is empty";
        return;
    }
    else if (!head->next)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node<valType> *traverse = head, *deleteNode = nullptr;
        while (traverse->next)
        {
            deleteNode = traverse;
            traverse = traverse->next;
        }
        deleteNode->next = nullptr;
        delete traverse;
        traverse = nullptr;
    }
    cout << "Element deleted";
    count--;
}

template <typename valType>
Node<valType> *LL<valType>::isPresent(int index)
{
    return getNode(index);
}

template <typename valType>
void LL<valType>::display()
{
    Node<valType> *traverse = head;
    cout << "\n";
    while (traverse)
    {
        cout << traverse->val << " -> ";
        traverse = traverse->next;
    }
    cout << "nullptr";
}

template <typename valType>
bool LL<valType>::isMatched(const string &val1, const string &val2)
{
    if (val1.size() != val2.size())
    {
        return false;
    }
    int i = 0;
    while (val1[i] != '\0' && val2[i] != '\0')
    {
        if (val1[i] != val2[i])
        {
            return false;
        }
        i++;
    }
    return val1[i] == '\0' && val2[i] == '\0';
}

template <typename valType>
bool LL<valType>::isMatched(const char *val1, const char *val2)
{
    int i = 0;
    while (val1[i] != '\0' && val2[i] != '\0')
    {
        if (val1[i] != val2[i])
        {
            return false;
        }
        i++;
    }
    return val1[i] == '\0' && val2[i] == '\0';
}

template <typename valType>
bool LL<valType>::isMatched(int val1, int val2)
{
    return val1 == val2;
}

// template <typename valType>
// LL<valType> &LL<valType>::operator=(const LL<valType> &obj)
// {
//     if (this == &obj)
//     {
//         return *this;
//     }
//     clear();
//     Node<valType> *objLL = obj.head;
//     if (!objLL)
//     {
//         this->count = 0;
//         this->head = nullptr;
//         return *this;
//     }
//     this->head = new Node<valType>(objLL->val);
//     Node<valType> *temp = head;
//     objLL = objLL->next;
//     while (objLL)
//     {
//         temp->next = new Node<valType>(objLL->val);
//         temp = temp->next;
//         objLL = objLL->next;
//     }
//     this->count = obj.count;
//     return *this;
// }

template <typename valType>
LL<valType> &LL<valType>::operator=(const LL<valType> &obj)
{
    if (this == &obj)
        return *this; // self-assignment safe

    clear(); // free old nodes

    if (!obj.head)
    {
        head = nullptr;
        count = 0;
        return *this;
    }

    head = new Node<valType>(obj.head->val);
    Node<valType> *temp = head;
    Node<valType> *objCurrent = obj.head->next;

    while (objCurrent)
    {
        temp->next = new Node<valType>(objCurrent->val);
        temp = temp->next;
        objCurrent = objCurrent->next;
    }
    count = obj.count;

    return *this;
}
