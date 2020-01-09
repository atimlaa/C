/**
 * Author: Aryan Timla
 * Assignment 3.2
 * This program takes a collection of integers as command line arguments
 * (representing the numbers around the circle; the starting point does not matter) and
 * attempts to find a solution to the Circle Division problem. The program will then report
 * a solution using the indices of the numbers where the division would be drawn
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 //command line arguments
 int main(int argc, char const *argv[]) {
 int sum = 0;

  int count = argc-1;
  //create an array to store the values of command line arguments
  int *arr = (int *) malloc(count * sizeof(int));
  for (int i = 0; i < count; i++) {
    arr[i] = atoi(argv[i+1]);
  }

  int total = 0;
  //sum of the array
    for (int i = 0; i<count; i++) {
      sum +=arr[i];
    }
    //condition for no solution
    if (sum %5 !=0) {
      printf("No solution\n");
      return 0;
    }

  int x=5;
  int result = sum/5;

  //printing the sum
  printf("Sum:");
  printf("%d\n", result);

  //create an array to track th indices
  int *track = (int *) malloc(5 * sizeof(int));

  printf("Solutions found:\n");

  for (int i = 0; i < count; i++) {
    int flag;
    total = 0;
    int k = 0;
    for (int j = i; j < count+i; j++) {
      flag=0;
      total += arr[j % count];
      if(total == result){
        total = 0;
        track[k] = j % count;
        k++;
    }
    else if(total > result){
      flag = 1;
        break;
      }
  }
  if (flag==0) {
    for (int i = 0; i < x; i++) {
      track[i] += 1;
      track[x-1] %= count;
    }

  //sorting array using insertion sort
  int value;
  for (int s = 0; s < x; s++) {
    value = track[s];
    int p = s;
    while(p > 0 && track[p-1] > value){
      track[p] = track[p-1];
      p--;
    }
    track[p] = value;
  }
  // printing out the indices
  for (int z = 0; z < x; z++) {
    printf("%d, ", track[z]);
  }
  return 0;
}
}
  // if there is no solution
  printf("No solution\n");
  return 0;
}
