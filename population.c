/**
 * Author: Aryan Timla
 * Assignment 2.2
 * This program projects the population growth under two models
 (as in the assignment) for n years.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//command line arguments
int main(int argc, char ** argv)
{
  int initialpop;
 double p, x, n;
 if(argc !=5)
 {printf("Please enter only 4 arguments\n");
 exit (1);
 }
 initialpop = atof(argv[1]);
 p = atof(argv[2]);
 x = atof(argv[3]);
 n = atof(argv[4]);

 //for error inputs
 if(initialpop<0 || (p<0)|| (x<0) || (n<0)) {
    printf("Invalid input(s) \n");
    return 0;
}
//declarations and printing the headers odthe table
double pop1, pop2;
int i;
printf("Year    ModelA    ModelB\n");

//the loop
for(i = 0; i <= n; i++) {
  if (i == 0){
    pop1= initialpop;
    pop2= initialpop;
    printf("%d     %.0f    %.0f\n", i, pop1, pop2);
  }
  else {
    //rounding the values
    pop1 = round(pop1);
    pop2 = round(pop2);
  //formulas
    pop1 = (pop1 + (p * pop1));
    pop2 = (pop2 + x);

    printf("%d     %.0f    %.0f\n", i, pop1, pop2);
   }
 }
return 0;
}
