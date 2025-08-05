#include <iostream>
#include "./library/string.h"

using namespace std;

int main()
{
    Character *stringObj = new Character();
    char textWithTemplate[] = "Hello, my name is {{name}}. I am from {{city}}. I am doing {{course}}.";
    HashMap<char *, char *> *obj = new HashMap<char *, char *>();
    char name[] = {'p', 'a', 'r', 'm', 'e', 'e', 't', '\0'};
    char city[] = {'p', 'a', 'n', 'i', 'p', 'a', 't', '\0'};
    char course[] = {'b', 'c', 'a', '\0'};
    char key1[] = {'n', 'a', 'm', 'e', '\0'};
    char key2[] = {'c', 'i', 't', 'y', '\0'};
    char key3[] = {'c', 'o', 'u', 'r', 's', 'e', '\0'};
    obj->hashInsertion(key1, name);
    obj->hashInsertion(key2, city);
    obj->hashInsertion(key3, course);
    cout << stringObj->fillPlaceholder(textWithTemplate, obj); // bug for segementation fault
    delete obj;
    cout << "\n";
    return 0;
}