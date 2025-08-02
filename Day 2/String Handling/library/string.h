#include <iostream>
#include "./hashtable.h"

// Task 1
int size_tmy_strlen(const char *s);                                                 // return length before '\0'
int my_strcmp(const char *a, const char *b);                                        // lexicographical compare
char *my_strcpy(char *dest, const char *src);                                       // copy src into dest
char *my_strcat(char *dest, const char *src);                                       // append src to dest
char *my_strchr(const char *s, int c);                                              // find first occurrence of char
char *my_strstr(const char *haystack, const char *needle);                          // substring search
void reverse_inplace(char *s);                                                      // reverse a string
int is_palindrome(const char *s);                                                   // check if palidrome
int count_words(const char *s);                                                     // count words
void lowercase(const char *ch);                                                     // convert into lowercase
char **most_frequent_word(const char *text, const char **stopwords, int stopcount); // most frequestly used words

// Task 2
char *readFile(const char *filePath); // read a file
char **tokenizer(const char *data);   // return all fields
void clearArrayOfString(char **data); // clear a array of character string
void clearCharacters(char *data);     // clear a array of characters

// // Task 3
// char *fillPlaceholder(char *text, HashMap<keyType, valType> *obj);

#include "./library.cpp"