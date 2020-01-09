/**
 * Author: Aryan Timla
 *
 * This program interactively prompts the user for
 * their weight, height and age and computes their BMR.
 */
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char ** argv)
{

  int gender, age;
  float weight, height;

  printf("Enter subject's gender  followed by ENTER (1=female, 2=male): \n");
  scanf("%d", &gender);

  printf("Enter subject's weight (kg): \n");
  scanf("%f", &weight);

  printf("Enter the subject's height (cm): \n");
  scanf("%f", &height);

  printf("Enter subject's age (years): \n");
  scanf("%d", &age);

  if(gender <0 || weight<0 || height<0 || age<0){
    printf("Bad input(s) \n");
    return 0;
  }

 float BMRf;
   if(gender==1) {
	   BMRf = 655.1 + 9.6 * weight + 1.8 * height - 4.7 * age;

  printf("Subject's BMR: %.2f kCal/day\n", BMRf);
   }

 float BMRm;
   if(gender==2) {
	   BMRm = 66.47 + 13.7 * weight + 5 * height - 6.8 * age;

	  printf("Subject's BMR: %.2f kCal/day\n", BMRm);
   }

   if(gender!=1 && gender!=2){
   printf("Error: invalid gender\n");
 }

  return 0;

}
