/**
 * Author: Aryan Timla
 * HACK 8.0
 * Collab: Kwaah Khor
 * Date: 10-16-2019
 * This program to get more practice working with strings, and write several functions that involve
 * operations on strings.
 */
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

// function that replaces instances of a given character
// with a different character in a string.
void replaceChar(char *s, char oldChar, char newChar){
  //Error Checking
  if (s == NULL) {
    return 0;
  }
  //replaceChar function
  int i;
  for(i = 0; i < strlen(s); i++){
    if (s[i] == oldChar){
      s[i] = newChar;
    }
  }
    s[i] = '\0';
    return;
}

// a function that takes a string and creates a new copy of it
// but with instances of a given character replaced with a different character.
char * replaceCharCopy(const char *s, char oldChar, char newChar){
  //Error Checking
  if (s == NULL) {
    return 0;
  }
  //replaceCharCopy function
   int i;
   char *copy = (char *) malloc(sizeof(char) * (strlen(s) + 1) );
   for(i = 0; i < strlen(s); i++){
     copy[i] = s[i];
   }
   copy[i] = '\0';

   replaceChar(copy, oldChar, newChar);
   return copy;
}

// function that takes a string and removes all instances
// of a certain character from it.
void removeChar(char *s, char c){
  //Error Checking
  if (s == NULL) {
    return 0;
  }
  //removeChar function
  int i, j;
  for(i = 0; s[i] != '\0'; i++){
    if (s[i] == c){
      for (j = i; s[j] != '\0'; j++) {
        s[j] = s[j+1];
      }
      i--;
    }
  }
    return;
 }

// a function that takes a string and creates a new copy of it but with all
// instances of a specified character removed from it.
char * removeCharCopy(const char *s, char c){
  //Error Checking
  if (s == NULL) {
    return 0;
  }
  //removeCharCopy functon
  int i;
  char * copy1 = (char *) malloc(sizeof(char) * (strlen(s) + 1) );
  for(i = 0; i < strlen(s); i++){
    copy1[i] = s[i];
  }
  copy1[i] = '\0';
  removeChar(copy1, c);
  return copy1;
}

// function that takes a string and splits it up to an array of strings.
// The split will be length-based: the function will also take an integer n and
// will split the given string up into strings of length n.
// Idea from a LA in Resource Center
char **lengthSplit(const char *s, int n){
  //Error Checking
  if (s == NULL) {
    return 0;
  }
  if (n <= 0) {
    return 0;
  }
//lengthSplit function
  //ind string length
  int size = strlen(s);
  int splitsize = size/n;
  //create new string
  char ** split = (char **) malloc(sizeof(char *) * (splitsize + 1));
//loop
  for (int i = 0; i <= splitsize; i++){
    split[i] = (char *) malloc(sizeof(char) * (n + 1));
    split[i][n] = '\0';
  }
  //nested loop
    int k = 0;
    for (int i = 0; i <= splitsize; i++) {
      for (int j = 0; j < n; j++) {
        split[i][j] = s[k];
        k++;
      }
    }
    return split;
  }
