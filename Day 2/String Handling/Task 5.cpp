#include <iostream>
#include "./library/string.h"
using namespace std;

int main()
{
    char text[100] = "      hello       \n\nthis is my \nname             \n\n\n\n";
    cout << "\nBefore normalization : " << text;
    cout << "\nAfter normalization : " << normalizeTextByRemovingExtraSpace(text);
    cout << "\n";
    return 0;
}