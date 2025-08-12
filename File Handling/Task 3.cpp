#include <iostream>
#include "./library/file.h"
using namespace std;

int main()
{
    int size = 0, i = 0;
    cout << "\nEnter size of text: ";
    cin >> size;
    while (size <= 0)
    {
        cout << "\nEnter size of text: ";
        cin >> size;
    }
    char str[size];
    cout << "\nEnter your string: ";
    while (i < size)
    {
        cin >> str[i];
        i++;
    }
    str[i] = '\0';
    appendInFile("./student.txt", str);
    return 0;
}