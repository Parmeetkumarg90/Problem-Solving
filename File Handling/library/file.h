// to read a file
char *readFile(const char *filePath);

// to append data in a file
void appendInFile(const char *filePath, const char *data);

// to copy a binary file into new file
void copyBinaryFile(const char *binaryFilePath);

// count words
int count_words(const char *s);

// return length before '\0'
int size_tmy_strlen(const char *s);

// concatenate string
void my_strcat(char *dest, const char *src);

#include "./library.cpp"