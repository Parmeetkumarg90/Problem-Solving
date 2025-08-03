#include <iostream>
#include "./library/string.h"

using namespace std;

int main()
{
    char textWithTemplate[] = "Hello, my name is {{name}}. I am from {{city}}. I am doing {{course}}.";
    HashMap<char *, char *> *obj = new HashMap<char *, char *>();
    char name[] = {'p', 'a', 'r', 'm', 'e', 'e', 't'};
    char city[] = {'p', 'a', 'n', 'i', 'p', 'a', 't'};
    char course[] = {'b', 'c', 'a'};
    char key1[] = {'n', 'a', 'm', 'e'};
    char key2[] = {'c', 'i', 't', 'y'};
    char key3[] = {'c', 'o', 'u', 'r', 's', 'e'};
    obj->hashInsertion(key1, name);
    obj->hashInsertion(key2, city);
    obj->hashInsertion(key3, course);
    cout << fillPlaceholder(textWithTemplate, obj); // bug for segementation fault
    delete obj;
    cout << "\n";
    return 0;
}