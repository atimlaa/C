/**
 * Author: Aryan Timla
 *Collab: Kwaah Khor
 * Hack 10
 * Date: 11-03-2019
 * In this program we will write several functions that involve operations on files.
 * To get more practice working with files.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file_utils.h"

 // a function that, given a file path/name as a string opens the file and returns
 // its entire contents as a single string.

char *getFileContents(const char *filePath){
  //open file
  FILE *f = fopen(filePath, "r");

  char c = fgetc(f);
  //create a counter
  int count = 1;
  while (c != EOF) {
    c = fgetc(f);
    count++;
  }
  fclose(f);

  f = fopen(filePath, "r");
  //create a string
  char *str = (char *) malloc(sizeof(char) * count);
  for (int i = 0; i < count-1; i++) {
    str[i] = fgetc(f);
  }
  fclose(f);

  return str;
}


//  a function that, given a file path/name as a string opens the file and returns
//  its entire contents as a single string.
 char **getFileLines(const char *filePath, int *numLines){
   //open the file
   FILE *f = fopen(filePath, "r");

   //initialization of string
   char mem[1000];
   char *a = fgets(mem,1000,f);
   //create a counter for predicting the size of numlines
   int count = 1;
   while (a != NULL) {
     a = fgets(mem,1000,f);
     count++;
   }

   //size of numLines
   *numLines = count -1;

   fclose(f);

   //create a string
   char **str = (char **) malloc(sizeof(char*) * *numLines);
   //loop
   for (int i = 0; i < *numLines; i++) {
     str[i]=(char *) malloc(sizeof(char) * 1000);
   }

   f = fopen(filePath, "r");

   for (int i = 0; i < *numLines; i++) {
     fgets(str[i],1000,f);
     str[i][strlen(str[i]) - 1] = '\0';
     printf("%s\n", str[i]);
     printf("%d\n", strlen(str[i]));
   }

   for (int i = 0; i < *numLines; i++) {
     printf("%s\n", str[i] );
   }

   fclose(f);

   return str;
}
