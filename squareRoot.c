/**
 * Author: Aryan Timla
 * Assignment 2.3
 * This program takes x and an ε and computes
 * the square root of x using the given method developed for EDSAC.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv)
{
 double x, Epsilon;
 if(argc !=3)
 {printf("Please enter only 2 arguments\n");
 exit (1);
 }
 x = atof(argv[1]);
 Epsilon = atof(argv[2]);

 int power = 0;
//scale up:
  while(x < 0) {
  x = x * 3;
  power--;
}
  while(x >= 3.0) {
  x = x / 3;
  power++;
}

double a1, c1;
double a =x;
double c =x-1;

while (a < Epsilon) {
  a = a1-(a1 * c1)/2.0;
  c = (pow(c1,2.0)* (c1-3.0))/4.0;
}
printf("sqrt(%lf) ~= %lf\n", x, a);
}
