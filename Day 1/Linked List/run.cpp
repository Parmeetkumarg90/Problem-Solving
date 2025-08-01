#include <iostream>
#include "./library/LinkedList(Generic).h"

using namespace std;

int main()
{
    LL<int> *llObj = new LL<int>();
    int value;
    int index = -1;
    char choice = '1';
    cout << "\n\t\t\t==>> Implementation of Generic Linked List <<==";

    cout << "\nNote:"
         << "\n#Press X for stopping program."
         << "\n#Press B for entering new value at beginning."
         << "\n#Press M for entering new value at middle."
         << "\n#Press N for entering new value at end."
         << "\n#Press D for Deleting a value at begin."
         << "\n#Press F for Deleting a value at middle."
         << "\n#Press G for Deleting a value at end."
         << "\n#Press S for searching a value."
         << "\n#Press O for displaying whole Linked List.";

    while (choice != 'X')
    {
        cout << "\n\n-->>Enter your choice: ";
        cin >> choice;
        choice = toupper(choice);
        cout << "\n";
        switch (choice)
        {
        case 'B': // insertionAtBegin
            cout << "Enter a value: ";
            cin >> value;
            llObj->insertionAtBegin(value);
            break;
        case 'M': // insertionAtMiddle
            cout << "Enter a value: ";
            cin >> value;
            cout << "Enter index after which to insert: ";
            cin >> index;
            llObj->insertionAtMiddle(index, value);
            index = -1;
            break;
        case 'N': // insertionAtEnd
            cout << "Enter a value: ";
            cin >> value;
            llObj->insertionAtBegin(value);
            break;
        case 'D': // deletionAtBegin
            llObj->deletionAtBegin();
            break;
        case 'F': // deletionAtMiddle
            cout << "Enter a value: ";
            cin >> value;
            llObj->deletionAtMiddle(value);
            break;
        case 'G': // deletionAtEnd
            llObj->deletionAtEnd();
            break;
        case 'S':
        { // searching
            cout << "Enter a value: ";
            cin >> value;
            bool isPresent = llObj->isPresent(value);
            cout << "\nValue present: ";
            if (isPresent)
                cout << "True";
            else
                cout << "False";
            break;
        }
        case 'O': // displaying
            cout << "Linked List: ";
            llObj->display();
            break;
        case 'X': // stoping program
            cout << "\n\t\t==>>Program Closed Successfully<<==";
            break;
        default: // default statement
            cout << "\n\t\t\t ==>>Please Choose Follow Instructions <<==";
        }
    }
    cout << "\n";
    delete llObj;
    return 0;
}