#include <iostream>
#include "./library/string.h"
using namespace std;

int main()
{
    // //                       Task 1
    // char str1[20] = {'p', 'a', 'r', 'm', 'e', 'e', 't'};
    // char str2[8] = {'p', 'a', 'r', 'm', 'e', 'e', 't'};
    // const char *stopwords[] = {"the", "is", "and", "of", "in", "to", "a", "on", "for", "with", "at", "by", "is", "am", "are", "was", "were", "will", "has", "have"};
    // int stopcount = sizeof(stopwords) / sizeof(stopwords[0]);

    // cout << "size: " << size_tmy_strlen(str1);
    // cout << "\ncompare: " << my_strcmp(str1, "kumar");
    // cout << "\nConcatenate: " << my_strcat(str1, " kumar");
    // cout << "\nFirst Occurance: " << my_strchr(str1, 'k');
    // char *foundValue = my_strstr(str1, "kmar");
    // cout << "\nFind Substring: " << (foundValue ? foundValue : "Not found");
    // reverse_inplace(str2);
    // cout << "\nreverse: " << str2;
    // cout << "\nis palidrome: " << (is_palindrome(str2) ? "True" : "False");
    // cout << "\ntotal words in a string: " << count_words("hello my name is parmeet kumar.");
    // cout << "\n most frequest word: " << most_frequent_word("hello my name hello what is your name hello", stopwords, stopcount);

    // //                       Task 2
    char *data = readFile("./student.csv"); // readFile("./student.csv");
    char **fields = tokenizer(data);
    cout << fields;
    clearArrayOfString(fields);
    clearCharacters(data);
    cout << "\n";
    return 0;
}