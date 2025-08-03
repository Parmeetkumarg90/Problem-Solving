#include <iostream>
#include <fstream>
using namespace std;

// return length before '\0'
int size_tmy_strlen(const char *s)
{
    int count = 0;
    for (count = 0; s[count] && s[count] != '\0'; count++)
    {
    }
    return count;
}

// Count words
int count_words(const char *s)
{
    int totalWord = 0, sizeOfS = size_tmy_strlen(s);
    bool isWord = false;
    for (int i = 0; i < sizeOfS; i++)
    {
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90))
        {
            if (isWord)
            {
                totalWord++;
            }
            isWord = false;
        }
        else
        {
            isWord = true;
        }
    }
    return totalWord;
}

// Append src to dest
void my_strcat(char *dest, const char *src)
{
    int i, sizeOfSrc = size_tmy_strlen(src), sizeOfDest = size_tmy_strlen(dest);
    for (i = 0; i < sizeOfDest; i++)
    {
    }
    for (int j = 0; j < sizeOfSrc; j++)
    {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
}

// read a file
char *readFile(const char *filePath)
{
    fstream file(filePath, ios::in | ios::binary);
    if (!file.is_open())
    {
        return nullptr;
    }
    int i = 0;
    char ch, *allData = new char[1000];
    while (file.get(ch))
    {
        allData[i] = ch;
        i++;
    }
    allData[i] = '\0';
    file.close();

    return allData;
}

// append data in a file
void appendInFile(const char *filePath, const char *data)
{
    fstream file(filePath, ios::app);
    if (!file.is_open())
    {
        cout << "Failed Operation of opening a file";
        return;
    }
    file << data;
    file.close();
}

// create a copy of a file
void copyBinaryFile(const char *binaryFilePath)
{
    char *allFIleData = readFile(binaryFilePath);
    if (!allFIleData)
    {
        cout << "Invalid File";
        return;
    }
    char copy[20];
    copy[0] = '\0';
    my_strcat(copy, "copy\0");
    my_strcat(copy, binaryFilePath);
    fstream file(copy, ios::in | ios::binary);
    if (!file.is_open())
    {
        cout << "Error while creating new file";
        return;
    }
    // file << allFIleData;
    file.close();
}