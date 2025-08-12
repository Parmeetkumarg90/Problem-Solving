#include <iostream>
#include "./library/String.h"
using namespace std;

int main()
{
    Character *obj = new Character();
    char ch1[8] = {'P', 'a', 'r', 'm', 'e', 'e', 't'};
    char ch2[8] = {'p', 'a', 'r', 'm', 'e', 'e', 't'};
    cout << obj->my_strstr(ch1, ch2);
    cout << "\n";
    return 0;
}