#include <iostream>
#include <fstream>
#include "./HashMap(generic).h"

using namespace std;

int size_tmy_strlen(const char *s) // return length before '\0'
{
    int count;
    for (count = 0; s[count] != '\0'; count++)
    {
    }
    return count;
}
int my_strcmp(const char *a, const char *b) // lexicographical compare
{
    int sizeOfA = size_tmy_strlen(a), sizeOfB = size_tmy_strlen(b);
    for (int i = 0, j = 0; i < sizeOfA && j < sizeOfB; i++, j++)
    {
        if (a[i] != b[i])
        {
            return a[i] - b[i];
        }
    }
    return 0;
}

char *lowercase(char *ch)
{
    if (*ch >= 65 && *ch < 97)
    {
        return (ch + 97);
    }
    return ch;
}

// Copy src into dest
char *my_strcpy(char *dest, const char *src)
{
    int i, sizeOfSrc = size_tmy_strlen(src);
    for (i = 0; i < sizeOfSrc; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

// Append src to dest
char *my_strcat(char *dest, const char *src)
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
    return dest;
}

// Find first occurrence of char
char *my_strchr(const char *s, int c)
{
    int sizeOfS = size_tmy_strlen(s);
    for (int i = 0; i < sizeOfS; i++)
    {
        if (s[i] == (char)c)
        {
            return (char *)&s[i];
        }
    }
    return nullptr;
}

// Substring search
char *my_strstr(const char *haystack, const char *needle)
{
    int sizeOfNeedle = size_tmy_strlen(needle), sizeOfHayStack = size_tmy_strlen(haystack);
    for (int i = 0; i < sizeOfHayStack; i++)
    {
        for (int j = 0; j < sizeOfNeedle; j++)
        {
            if (haystack[i] == needle[j])
            {
                int compareLength = 0, traverI = i;
                for (int k = 0; k < sizeOfNeedle; k++)
                {
                    if (haystack[traverI] == needle[k])
                    {
                        traverI++;
                        compareLength++;
                    }
                    else
                    {
                        k = sizeOfNeedle;
                    }
                }
                if (compareLength == sizeOfNeedle)
                {
                    return (char *)&haystack[i];
                }
            }
        }
    }
    return nullptr;
}

// Reverse a string in place
void reverse_inplace(char *s)
{
    int sizeOfS = size_tmy_strlen(s) - 1;
    char temp;
    for (int i = 0; i < sizeOfS; i++)
    {
        temp = s[i];
        s[i] = s[sizeOfS];
        s[sizeOfS] = temp;
        sizeOfS--;
    }
}

// Check if palindrome
int is_palindrome(const char *s)
{
    int sizeOfS = size_tmy_strlen(s) - 1;
    for (int i = 0; i < sizeOfS; i++)
    {
        if (s[i] != s[sizeOfS])
        {
            return 0;
        }
        sizeOfS--;
    }
    return 1;
}

// Count words
int count_words(const char *s)
{
    int totalWord = 0, sizeOfS = size_tmy_strlen(s);
    bool isWord = false;
    for (int i = 0; i < sizeOfS; i++)
    {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '\n' || s[i] == ';' || s[i] == ',' || s[i] == '-')
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

char **tokenizer(const char *data)
{
    // if (!data)
    // {
    //     return nullptr;
    // }
    // int totalWords = count_words(data), wordI = 0, fieldI = 0, sizeOfData = size_tmy_strlen(data);
    // // char **allFields = new char *[totalWords], *eachWord = new char[15];
    // bool isWord = false;
    // for (int i = 0; i < sizeOfData; i++)
    // {
    //     if (data[i] == ' ' || data[i] == ',' || data[i] == '.' || data[i] == '!' || data[i] == '\n' || data[i] == ';' || data[i] == ',' || data[i] == '-')
    //     {
    //         if (isWord)
    //         {
    //             // for (int j = 0; j < wordI; j++)
    //             // {
    //             //     cout << eachWord[j];
    //             //     allFields[fieldI][j] = eachWord[j];
    //             // }
    //             // fieldI++;
    //             // cout << eachWord << " ";
    //             wordI = 0;
    //         }
    //         isWord = false;
    //     }
    //     else
    //     {
    //         // eachWord[wordI] = data[i];
    //         wordI++;
    //         // eachWord[wordI] = '\0';
    //         isWord = true;
    //     }
    // }
    return nullptr;
}

char *readFile(const char *filePath)
{
    fstream file("./student.csv", ios::in);
    if (!file.is_open())
    {
        return nullptr;
    }
    int i = 0;
    char ch, *allData = new char[100];
    while (file.get(ch))
    {
        allData[i] = ch;
        i++;
    }
    allData[i] = '\0';
    file.close();

    return allData;
}

void clearArrayOfString(char **data)
{
    int i = 0;
    while (*data[i] != '\0')
    {
        if (data[i])
        {
            delete[] data[i];
            data[i] = nullptr;
        }
        i++;
    }
    delete[] data;
    data = nullptr;
}

void clearCharacters(char *data)
{
    delete[] data;
    data = nullptr;
}

// Most frequently used word (ignoring stopwords)
char *most_frequent_word(const char *text, const char **stopwords, int stopcount)
{
    cout << stopcount;
    return nullptr;
}
