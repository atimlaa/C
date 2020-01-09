/**
 * Author: Aryan Timla
 * Assignment 2.1
 * This program takes an integer n and a subsequent list of integers as command line arguments
 and determines which number(s) between 1 and n are missing from the list.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  int i = 0;
  int j = 0;
  int length1 = 0;
  int length2 = 0;
  int arr1[100];
  int arr2[100];

  length1 = sizeof(arr1) / sizeof(arr1[0]);
  length2 = sizeof(arr2) / sizeof(arr2[0]);

  for(i = 0; i < argc ; i++) {
    arr1[i] = atoi(argv[i+1]);
  }

  for(i = 0; i < length1; i++) {
    for(j = 0; j < length2; j++) {
      if(arr1[i] == arr2[j]){
      break;
      }
    }
      if(j == length2) {
        printf("%d ", arr1[i]);
      }
    }
  }

/*int MissingNo(int n, int arr[])
{
    int x = arr[0];
    int y = 1;

    for (int i = 1; i < n; i++) {
      x = x ^ arr[i];
    }

    for (int i = 2; i <= n + 1; i++){
      y = y ^ i;
      int result = x ^ y;
      return result;
    }
    return 0;
}*/


/**int main(int argc, char const *argv[]) {
  int n;
  n= atof(argv[1]);

int arr[100];
printf("Missing numbers 1 thru %d:\n", n);


for(int i=0; i < argc-1; i++) {
    for(int j=1; j < n; j++) {
    if (arr[i] != arr[j]) {
      printf("%d\n", arr[i]);
    }
  }
}
return 0;
}*/
