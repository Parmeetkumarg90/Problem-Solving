#include <iostream>
#include <fstream>
#include "./HashMap(generic).h"

using namespace std;

// Task 1

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

void lowercase(char *ch)
{
    if (!ch)
        return;
    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            ch[i] += 32;
        }
        i++;
    }
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

// Most frequently used word (ignoring stopwords)
char **most_frequent_word(const char *text, const char **stopwords, int stopcount)
{
    if (!text)
    {
        return nullptr;
    }
    return nullptr;
}

// Task 2
char **tokenizer(const char *data)
{
    if (!data)
    {
        return nullptr;
    }
    int wordI = 0, fieldI = 0, i;
    char **allFields = new char *[50];
    char *eachWord = new char[15];
    bool isWord = false;
    for (i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == ',' || data[i] == '\n' || data[i] == '\0')
        {
            if (isWord)
            {
                allFields[fieldI] = new char[wordI + 1];
                for (int j = 0; j < wordI; j++)
                {
                    allFields[fieldI][j] = eachWord[j];
                }
                allFields[fieldI][wordI] = '\0';
                fieldI++;
                wordI = 0;
            }
            isWord = false;
        }
        else
        {
            eachWord[wordI] = data[i];
            wordI++;
            eachWord[wordI] = '\0';
            isWord = true;
        }
    }
    allFields[fieldI] = nullptr;
    delete[] eachWord;
    return allFields;
}

char *readFile(const char *filePath)
{
    fstream file("./student.csv", ios::in);
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

void clearArrayOfString(char **data)
{
    int i = 0;
    while (data[i] != nullptr)
    {
        if (data[i])
        {
            delete[] data[i];
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

// Task 3
// template <typename keyType, typename valType>
// char *fillPlaceholder(char *text, HashMap<keyType, valType> *obj) {}

// Task 4
// Substring search
char *my_strstr(const char *haystack, const char *needle)
{
    char *newhaystack = my_strcpy(new char[size_tmy_strlen(haystack) + 1], haystack);
    char *newneedle = my_strcpy(new char[size_tmy_strlen(haystack) + 1], needle);
    lowercase(newhaystack);
    lowercase(newneedle);
    int sizeOfNeedle = size_tmy_strlen(newneedle), sizeOfHayStack = size_tmy_strlen(newhaystack);
    for (int i = 0; i < sizeOfHayStack; i++)
    {
        for (int j = 0; j < sizeOfNeedle; j++)
        {
            if (newhaystack[i] == newneedle[j])
            {
                int compareLength = 0, traverI = i;
                for (int k = 0; k < sizeOfNeedle; k++)
                {
                    if (newhaystack[traverI] == newneedle[k])
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
                    return (char *)&newhaystack[i];
                }
            }
        }
    }
    return nullptr;
}