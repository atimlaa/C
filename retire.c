/**
 * Author: Aryan Timla
 *
 * This program produces an amortization table for a 401(k) account. Your program
 * will read the following inputs as command line arguments.
 * An initial starting balance
 * A monthly contribution amount
 * An (average) annual rate of return (on the scale [0, 1])
 * An (average) annual rate of inflation (on the scale [0, 1])
 * A number of years until retirement
 * and then compute a monthly savings table detailing the (inflation-adjusted)
 * interest earned each month, contribution, and new balance.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char ** argv)
{
  //command line arguments
 double startingbal, mocontributionamt, returnrate, inflationrate, retireage;
 if(argc !=6)
 {printf("Please enter only 5 arguments\n");
 exit (1);
 }
 startingbal = atof(argv[1]);
 mocontributionamt = atof(argv[2]);
 returnrate = atof(argv[3]);
 inflationrate = atof(argv[4]);
 retireage = atof(argv[5]);
 //for error inputs
 if(mocontributionamt * 12 >18500) {
   printf("Illegal: monthly contributions exceed $18,500 annual limit \n");
   return 0;
}
if(startingbal<0 || (returnrate<0 && returnrate>1)|| (inflationrate<0 && inflationrate>1)) {
   printf("Invalid input(s) \n");
   return 0;
 }
 if(returnrate<0) {
   printf("Illegal: interest must be positive \n");
   return 0;
}
 //declarations
 //formula for the inflation-adjusted rate of return
 double inflation, balance, monthlyrate, interest, totint=0.0, nestegg;;
 int i;
 inflation = ((1+returnrate)/(1+inflationrate)) - 1;
 monthlyrate= inflation/12;
 balance= startingbal;
 //headings for the table
 printf("month interest balance\n");
 //the loop
 for(i=1; i<=(retireage*12); i++) {
   //rounding up the values
   interest= round(interest*100)/100;
   balance= round(balance*100)/100;
   totint= round(totint*100)/100;
 //formulas
   interest= monthlyrate * balance;
   balance= balance + interest + mocontributionamt;
   totint = totint + interest;

   printf("%d     $%.2f    $%.2f\n", i,interest, balance);
 }

 //Total Interst Earned and Total Nest Egg
 printf("Total Interst Earned = $%.2f\n", totint );
 nestegg= balance;
 printf("Total Nest Egg= $%.2f\n", nestegg );

 return 0;
}
