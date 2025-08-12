#include <iostream>
#include "./library/String.h"
using namespace std;

int main()
{
    Character *obj = new Character();
    char text[100] = "      hello       \n\nthis is my \nname             \n\n\n\n";
    cout << "\nBefore normalization : " << text;
    cout << "\nAfter normalization : " << obj->normalizeTextByRemovingExtraSpace(text);
    cout << "\n";
    return 0;
}