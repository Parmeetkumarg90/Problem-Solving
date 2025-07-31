// HashMap -> A type of data structure that is used to store user values in key-value pair. [  ]
// HashMap Various Complexities ->
// 1.) Read -> Best-O(1) Worst-O(n)
// 2.) Write -> Best-O(1) Worst-O(n)
// 3.) Deletion -> Best-O(1) Worst-O(n)

#include <iostream>
#include "./library/HashMap(generic).h"
using namespace std;

int main()
{
    HashMap<string, string> *hashObj = new HashMap<string, string>();
    string key, value;
    char choice = '1';
    cout << "\n\t\t\t==>> Implementation of HashMap <<==";

    cout << "\nNote:"
         << "\n#Key must be unique for each value."
         << "\n#Value can be same.\n\nControlles:"
         << "\n#Press X for stopping program."
         << "\n#Press E for entering new key-value pair."
         << "\n#Press D for Deleting a key-value pair."
         << "\n#Press S for searching a key-value pair."
         << "\n#Press O for displaying whole HashTable."
         << "\n#Press C for Clearing whole HashTable."
         << "\n#Press F for Checking If Empty HashTable."
         << "\n#Press P for Count whole HashTable."
         << "\n#Press N for a whole copy HashTable.";

    while (choice != 'X')
    {
        cout << "\n\n-->>Enter your choice: ";
        cin >> choice;
        choice = toupper(choice);
        cout << "\n";
        switch (choice)
        {
        case 'E': // insertion
            cout << "Enter a key: ";
            cin >> key;
            cout << "Enter a value: ";
            cin >> value;
            hashObj->hashInsertion(key, value);
            break;
        case 'D': // deletion
            cout << "Enter a key: ";
            cin >> key;
            hashObj->hashDeletion(key);
            break;
        case 'S':
        { // searching
            cout << "Enter a key: ";
            cin >> key;
            bool isPresent = hashObj->isPresent(key);
            cout << "\nKey-Value Pair present: ";
            if (isPresent)
                cout << "True";
            else
                cout << "False";
            break;
        }
        case 'O': // displaying
            cout << "HashTable: ";
            hashObj->hashDisplay();
            break;
        case 'C': // clearing
            hashObj->clear();
            break;
        case 'N': // creating a new copy
        {
            HashMap<string, string> *newObj(hashObj);
            newObj->hashDisplay();
            newObj->clear();
            break;
        }
        case 'F':
        { // checking if empty
            cout << "Is HashTable Empty: ";
            bool isEmpty = hashObj->empty();
            if (isEmpty)
                cout << "True";
            else
                cout << "False";
            break;
        }
        case 'P': // counting
            cout << "HashTable: ";
            cout << hashObj->count();
            break;
        case 'X': // stoping program
            cout << "\n\t\t==>>Program Closed Successfully<<==";
            break;
        default: // default statement
            cout << "\n\t\t\t ==>>Please Choose Follow Instructions <<==";
        }
    }
    cout << "\n";
    delete hashObj;
    return 0;
}