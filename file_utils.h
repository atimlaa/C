/**
 * Author: Aryan Timla
 * Collab: Matthew Mai
 * Hack 10
 * Date: 11-03-2019
 * In this program we will write several functions that involve operations on files.
 * To get more practice working with files.
 */
 
/*
 * a function that, given a file path/name as a string opens the file and returns
 * its entire contents as a single string.
 */
char *getFileContents(const char *filePath);

/*
 *  a function that, given a file path/name as a string opens the file and returns
 * the contents of the file as an array of strings. Each element in the array should
 * correspond to a line in the file.
 */
char **getFileLines(const char *filePath, int *numLines);
