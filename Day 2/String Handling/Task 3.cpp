#include <iostream>
#include "./library/string.h"

using namespace std;

int main()
{
    char *textWithTemplate = "Hello, my name is {{name}}. I am from {{city}}. I am doing {{course}}.";
    HashMap<char *, char *> *obj = new HashMap<char *, char *>();
    char name[] = {'p', 'a', 'r', 'm', 'e', 'e', 't'};
    char city[] = {'p', 'a', 'n', 'i', 'p', 'a', 't'};
    char course[] = {'b', 'c', 'a'};
    obj->hashInsertion("name", name);
    obj->hashInsertion("city", city);
    obj->hashInsertion("course", course);
    // cout << fillPlaceholder(textWithTemplate, obj);
    delete obj;
    cout << "\n";
    return 0;
}