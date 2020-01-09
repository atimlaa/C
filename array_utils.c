/**
 * Author: Aryan Timla
 * Assignment 3.1
 * This program to get more practice working with arrays, and write several functions that involve
 * operations on arrays.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "array_utils.h"

int isEqual(const int *a, const int *b, int size){
//Error checking
if (size <= 0) {
  return 0;
}
if (a == NULL || b == NULL) {
return 0;
}
//condition
if (a == b){
  return 1;
  }
  else{
    return 0;
  }
}

 int reverse(int *a, int size){
 //Error Checking
 if (a == NULL) {
   return 0;
 }
 if (size <= 0) {
   return 0;
 }
 //loop to reverse the array from hack
 for (int first = 0, last = size-1; first<last; first++, last--){
   int rev = a[first];
   a[first]=a[last];
   a[last]=rev;
 }
 return 1;
}

 int * reverseCopy(const int *a, int size){
   //Error Checking
   if (a == NULL) {
     return 0;
   }
   if (size <= 0) {
     return 0;
   }
   //creating an array
   int *copy = (int *) malloc(size * sizeof(int));
   //loop to copy the array
   for (int i = 0; i < size; i++) {
     copy[i]=a[i];
   }
   //using the reverse function above
   reverse(copy, size);
   //return the new copy array
   return copy;
 }

 int shift(int *a, int size, int k){
   //Error Checking
   if (a == NULL) {
     return 0;
   }
   if (size <= 0) {
     return 0;
   }
   if (k < 0) {
     return 0;
   }
   //create a temporary array
   int *temp = (int *) malloc(size * sizeof(int));
   //loops suggested by LA
   for (int i = 0; i < k; i++) {
     temp[i] = a[size-k+i];
   }
   for (int j = 0; j < (size-k); j++) {
     temp[j+k]= a[j];
   }
   for (int z = 0; z < size; z++) {
     a[z] = temp[z];
   }
   return 1;
 }

 int * shiftCopy(const int *a, int size, int k){
   //Error Checking
   if (a == NULL) {
     return 0;
   }
   if (size <= 0) {
     return 0;
   }
   if (k < 0) {
     return 0;
   }
   //creating an array
   int *copy1 = (int *) malloc(size * sizeof(int));
   //loop to copy the array
   for (int i = 0; i < size; i++) {
     copy1[i] = a[i];
   }
   //using the shiftCopy function above
   shift(copy1, size, k);
   //return the new copy array
   return copy1;
 }

 int * getEvens(const int *a, int size, int *newSize){
   //Error Checking
   if (a == NULL) {
     return 0;
   }
   if (size <= 0) {
     return 0;
   }
   if (newSize < 0) {
     return 0;
   }
   int i;
   //create a counter to count the size of new array
   int count = 0;
   //loop to count the evens
   for (i = 0; i < size; i++){
     if (a[i] % 2 == 0) {
       count++;
       }
     }
     //using pass by reference parameter to indicate the size of new array
     *newSize = count;
     int j =0;
     //creaate an array to store evens
     int *even = (int *) malloc(count * sizeof(int));
     //loop to extract evens
     for (i = 0; i < size; i++){
       if (a[i] % 2 == 0) {
         even[j] = a[i];
         j++;
         }
       }
     return even;
   }

 int ** circulant(const int *a, int size){
   //Error Checking
   if (a == NULL) {
     return 0;
   }
   if (size <= 0) {
     return 0;
   }
   int ** matrix = (int **) malloc(sizeof(int *) * size);
   for (int i = 0; i < size; i++) {
    matrix[i] = (int *) malloc(size * sizeof(int));
   }
   //creating a deep copy array to discard the const in a
   int *copy2 = (int *) malloc(size * sizeof(int));
   //loop to copy the array
   for (int i = 0; i < size; i++) {
     copy2[i] = a[i];
   }

   int k = 0;
   //nested loop to create a matrix
   for (int i = 0; i < size; i++) {
     for (int j = 0; j < size; j++) {
       matrix[i][j] = copy2[j];
     }
     //using the shift function
     shift(copy2, size, 1);
     k++;
   }
   return matrix;
 }

 int * collapse(int **A, int n, int m){
   //Error Checking
   if (A == NULL) {
     return 0;
   }
   if (n <= 0 || m <= 0) {
     return 0;
   }
   //create an array to store the collapsed array
   int *arr = (int *) malloc(m * sizeof(int));
   int sum;
   for (int i = 0; i < m; i++) {
     sum = 0;
     for (int j = 0; j < n; j++) {
       sum = sum + A[j][i];
     }
     arr[i] = sum;
   }
   return arr;
 }
