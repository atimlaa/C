/**
* a function that replaces instances of a given character
* with a different character in a string.
*/
void replaceChar(char *s, char oldChar, char newChar);

/**
* a function that takes a string and creates a new copy of it
* but with instances of a given character replaced with a different character.
*/
char * replaceCharCopy(const char *s, char oldChar, char newChar);

/**
* a function that takes a string and removes all instances
* of a certain character from it.
*/
void removeChar(char *s, char c);

/**
* a function that takes a string and creates a new copy of it but with all
* instances of a specified character removed from it.
*/
char * removeCharCopy(const char *s, char c);

/** a function that takes a string and splits it up to an array of strings. The
* split will be length-based: the function will also take an integer n and will split the
* given string up into strings of length n.
*/
char **lengthSplit(const char *s, int n);
