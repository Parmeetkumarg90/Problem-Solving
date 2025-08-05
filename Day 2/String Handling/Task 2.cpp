#include <iostream>
#include "./library/string.h"
using namespace std;

int main()
{
    Character *obj = new Character();
    // char *data = readFile("./student.csv"); // readFile("./student.csv");
    fstream file("./student.csv", ios::in);
    if (!file.is_open())
    {
        cout << "Unable to read file";
        return 0;
    }
    int i = 0;
    char ch, allData[100];
    while (file.get(ch))
    {
        allData[i] = ch;
        i++;
    }
    allData[i] = '\0';
    file.close();
    char **fields = new char *[obj->count_words(allData) + 1];
    fields = obj->tokenizer(allData);
    for (int i = 0; fields[i]; i++)
    {
        cout << "'" << fields[i] << "' ";
    }
    obj->clearArrayOfString(fields);
    cout << "\n";
    return 0;
}