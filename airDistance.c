/**
 * Author: Aryan Timla
 *
 * This program prompts the user to enter the
 * longitude and latitude of points A and B and computes
 * its air distance using the given formula
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double distance;
  double R = 6371;


double lA, lB, ltA, ltB;

  printf("Please enter the latitude of A : ");
  scanf("%lf", &lA);
  double latitude1= (lA/180.0) * M_PI;

  printf("Please enter the longitude of A : ");
  scanf("%lf", &ltA);
  double r1= (ltA/180.0) * M_PI;

  printf("Please enter the latitude of B : ");
  scanf("%lf", &lB);
  double latitude2= (lB/180.0) * M_PI;

  printf("Please enter the longitude of B : ");
  scanf("%lf", &ltB);
  double r2= (ltB/180.0) * M_PI;

  double delta;
  delta = r2 - r1;

  printf("Origin: (%lf,%lf)\n",lA,ltA);
  printf("Destination: (%lf,%lf)\n",lB,ltB);

  double d;
  d = acos ((sin(latitude1) * sin(latitude2)) + (cos(latitude1) * cos(latitude2) * cos(delta))) * R;

  printf("Air distance is %lf kms\n", d);

  return 0;
}
