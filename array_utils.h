/**
 * Author: Aryan Timla
 * Assignment 3.1
 * This is a header file for the source file program to get more practice working with arrays, and write several functions that involve
 * operations on arrays.
 */
 
/* function takes two integer arrays and determines if they are equal:
* that is, each index contains the same element.
* If they are equal, then you should return true (non-zero),
* if not return false (zero).
*/
int isEqual(const int *a, const int *b, int size);

// function takes an integer array and reverses its contents.
int reverse(int *a, int size);

/* function  takes an integer array and creates and
* returns a new copy with the contents reversed.
*/
int * reverseCopy(const int *a, int size);

/* function takes an integer array and an integer k and
* shifts the contents of the circularly to the right by k positions.
*/
int shift(int *a, int size, int k);

/* function that takes an integer array and an integer k and creates
* a copy of the array with the contents circularly shifted to the right by k positions.
*/
int * shiftCopy(const int *a, int size, int k);

/* function takes an integer array and returns a new array containing only the even elements.
*/
int * getEvens(const int *a, int size, int *newSize);

/* function  takes an array of n elements and produces an n × n circulant matrix
* in which the first row consists of the array elements, then each subsequent row contains the same elements,
* but circularly shifted by one position.
*/
 int ** circulant(const int *a, int size);

// function that “collapses” an n × m matrix into an array of size m by summing all elements in each column.
 int * collapse(int **A, int n, int m);
