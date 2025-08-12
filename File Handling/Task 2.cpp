#include <iostream>
#include "./library/file.h"
using namespace std;

int main()
{
    copyBinaryFile("binary.jpg\0");
    return 0;
}