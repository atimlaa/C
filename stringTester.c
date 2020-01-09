#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <string.h>

#include "string_utils.h"

int main() {
  int result = 1;
  int numPassed = 0;
  int numFailed = 0;

  //Test case for replaceChar
  char Hello[] = "Hello";
  char oldChar1 = 'e';
  char newChar1 = 'i';
  printf("TESTING: replaceChar1: ");
  replaceChar(Hello, oldChar1, newChar1);
  result = strcmp(Hello, "Hillo");
  if (result != 0) {
    printf("FAILED: replaceChar returned %s, expected Hillo\n", Hello);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  char Aryan[] = "Aryan";
  char oldChar2 = 'y';
  char newChar2 = 'i';
  printf("TESTING: replaceChar2: ");
  replaceChar(Aryan, oldChar2, newChar2);
  result = strcmp(Aryan, "Arian");
  if (result != 0) {
    printf("FAILED: replaceChar returned %s, expected Arian\n", Aryan);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  char Nepal[] = "Nepal";
  char oldChar3 = 'a';
  char newChar3 = 'o';
  printf("TESTING: replaceChar3: ");
  replaceChar(Nepal, oldChar3, newChar3);
  result = strcmp(Nepal, "Nepol");
  if (result != 0) {
    printf("FAILED: replaceChar returned %s, expected Nepol\n", Nepal);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  //Test case for replaceCharCopy

  printf("TESTING: replaceCharCopy1: ");
  char * copyarr1 = replaceCharCopy(Hello, oldChar1, newChar1);
  result = strcmp(Hello, "Hillo");
  if (result != 0) {
    printf("FAILED: replaceCharCopy returned %s, expected Hillo\n", Hello);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: replaceCharCopy2: ");
  char * copyarr2 = replaceCharCopy(Aryan, oldChar2, newChar2);
  result = strcmp(Aryan, "Arian");
  if (result != 0) {
    printf("FAILED: replaceCharCopy returned %s, expected Arian\n", Aryan);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: replaceCharCopy3: ");
  char * copyarr3 = replaceCharCopy(Nepal, oldChar3, newChar3);
  result = strcmp(Nepal, "Nepol");
  if (result != 0) {
    printf("FAILED: replaceCharCopy returned %s, expected Nepol\n", Nepal);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  //Test case for removeChar
  char Hello1[] = "Hello";
  char c1 = 'o';
  printf("TESTING: removeChar1: ");
  removeChar(Hello1, c1);
  result = strcmp(Hello1, "Hell");
  if (result != 0) {
    printf("FAILED: removeChar returned %s, expected Hell\n", Hello1);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  char Aryan1[] = "Aryan";
  char c2 = 'y';
  printf("TESTING: removeChar2: ");
  removeChar(Aryan1, c2);
  result = strcmp(Aryan1, "Aran");
  if (result != 0) {
    printf("FAILED: removeChar returned %s, expected Aran\n", Aryan1);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  char Nepal1[] = "Nepal";
  char c3 = 'p';
  printf("TESTING: removeChar3: ");
  removeChar(Nepal1, c3);
  result = strcmp(Nepal1, "Neal");
  if (result != 0) {
    printf("FAILED: removeChar returned %s, expected Neal\n", Nepal1);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  //Test case for removeCharCopy

  printf("TESTING: removeCharCopy1: ");
  char * copyarrA = removeCharCopy(Hello1, c1);
  result = strcmp(Hello1, "Hell");
  if (result != 0) {
    printf("FAILED: removeCharCopy returned %s, expected Hell\n", copyarrA);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }


  printf("TESTING: removeCharCopy2: ");
  char * copyarrB = removeCharCopy(Aryan1, c2);
  result = strcmp(Aryan1, "Aran");
  if (result != 0) {
    printf("FAILED: removeCharCopy returned %s, expected Aran\n", copyarrB);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: removeCharCopy3: ");
  char * copyarrC = removeCharCopy(Nepal1, c3);
  result = strcmp(Nepal1, "Neal");
  if (result != 0) {
    printf("FAILED: removeCharCopy returned %s, expected Neal\n", copyarrC);
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  // Test case for lengthSplit
  printf("TESTING: lengthSplit1:");
  char arr1[] = "Hello";
  char ** splitarray1 = lengthSplit(arr1, 1);

  result = strcmp(splitarray1[0], "H");
  result = strcmp(splitarray1[1], "e");
  result = strcmp(splitarray1[2], "l");
  result = strcmp(splitarray1[3], "l");
  result = strcmp(splitarray1[4], "o");
  if (result != 0) {
    printf("FAILED\n");
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: lengthSplit2:");
  char arr2[] = "Aryan Raj";
  char ** splitarray2 = lengthSplit(arr2, 5);

  result = strcmp(splitarray2[0], "Aryan");
  result = strcmp(splitarray2[1], " Raj");
  if (result != 0) {
    printf("FAILED\n");
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("TESTING: lengthSplit2:");
  char arr3[] = "Sandhya";
  char ** splitarray3 = lengthSplit(arr3, 2);

  result = strcmp(splitarray3[0], "Sa");
  result = strcmp(splitarray3[1], "nd");
  result = strcmp(splitarray3[2], "hy");
  result = strcmp(splitarray3[3], "a");
  if (result != 0) {
    printf("FAILED\n");
    numFailed++;
  } else {
    printf("PASSED\n");
    numPassed++;
  }

  printf("Number Test Cases Passed: %15d\n", numPassed);
  printf("Number Test Cases Failed: %15d\n", numFailed);
  printf("Percent Passed:           %15.2f\n", 100.0 * numPassed / (numPassed + numFailed));
  return 0;
}
