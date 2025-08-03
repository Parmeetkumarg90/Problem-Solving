#include <iostream>
#include "./library/file.h"
using namespace std;

int main()
{
    char *allData = readFile("./student.txt");
    cout << count_words(allData);
    return 0;
}