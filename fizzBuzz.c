/**
 * Author: Aryan Timla
 * Final Exam
 * Date: 12-17-2019
 * This program that takes four integers a, b, p, q as command line arguments
 * and prints the numbers a thru b (inclusive on both) one to a line.
 * However, if the number is divisible by p, print “Fizz” instead.
 * If it is divisible by q print “Buzz” instead of the number.
 * If it is divisible by both p and q, then print “FizzBuzz” instead.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv)
{
 int a, b, p, q;
 if(argc !=5)
 {printf("Please enter only 4 arguments\n");
 exit (1);
 }
 a = atof(argv[1]);
 b = atof(argv[2]);
 p = atof(argv[3]);
 q = atof(argv[4]);

for (int i = a; i <= b; i++) {
  if (i % p == 0){
    printf("Fizz\n");
  }
  else if (i % q == 0) {
    printf("Buzz\n");
  }
  else if (i % p == 0 && i % q == 0) {
    printf("FizzBuzz\n");
  }
  else {
    printf("%d\n", i);
   }
 }
 return 0;
}
