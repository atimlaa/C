/**
 * Author: Aryan Timla
 *
 * This program interactively prompts the user for
 * their team’s runs scored, runs against, number of games
 * and the number of actual wins the team had
 * and computes the expected win percentage .
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv)
{
 double RS, RA, G, W;
 if(argc !=5)
 {printf("Please enter only 4 arguments\n");
 exit (1);
 }
 RS = atof(argv[1]);
 RA = atof(argv[2]);
 G = atof(argv[3]);
 W = atof(argv[4]);

 float p1, WP1, winp1;
 double PredictedWins1, PredictedLoss1, Error1;

 p1 = 2;
 WP1 = pow(RS,2)/(pow(RS, 2)+ pow(RA, 2));
 winp1 = WP1 * 100;
 PredictedWins1 = WP1 * G;
 PredictedLoss1 = G - PredictedWins1;
 if ( W > PredictedWins1 ) {
 Error1 = W - PredictedWins1;
 }
 if ( PredictedWins1 > W ) {
 Error1 = PredictedWins1 - W;
 }

 float p2, WP2, winp2;
 double PredictedWins2, PredictedLoss2, Error2;
 p2 = 1.83;
 WP2 = pow(RS,1.83)/(pow(RS, 1.83)+ pow(RA, 1.83));
 winp2 = WP2 * 100;
PredictedWins2 = WP2 * G;
PredictedLoss2 = G - PredictedWins2;
if ( W > PredictedWins2 ) {
Error2 = W - PredictedWins2;
}
if ( PredictedWins2 > W ) {
Error2 = PredictedWins2 - W;
}

float p3, WP3, winp3;
double PredictedWins3, PredictedLoss3, Error3;
p3 = 1.5 * log10(((RS + RA) / G)) + 0.45;
WP3 = pow(RS,p3)/(pow(RS,p3)+ pow(RA,p3));
winp3 = WP3 * 100;
PredictedWins3 = WP3 * G;
PredictedLoss3 = G - PredictedWins3;
if ( W > PredictedWins3 ) {
Error3 = W - PredictedWins3;
}
if ( PredictedWins3 > W ) {
Error3 = PredictedWins3 - W;
}

float p4, WP4, winp4;
double PredictedWins4, PredictedLoss4, Error4;
p4 = pow(((RS + RA) / G),0.287);
WP4 = pow(RS,p4)/(pow(RS, p4)+ pow(RA, p4));
winp4 = WP4 * 100;
PredictedWins4 = WP4 * G;
PredictedLoss4 = G - PredictedWins4;
if ( W > PredictedWins4 ) {
Error4 = W - PredictedWins4;
}
if ( PredictedWins4 > W ) {
Error4 = PredictedWins4 - W;
}
if(RS<0 || RA<0 || G<0 || W<0){
  printf("Invalid input(s) \n");
return 0;
}

printf("pvalue   Win percentage   Predicted Wins   Predicted Loss   Error\n");
printf(" %.2f        %.2f        %.0f               %.0f                %.0f \n", p1, winp1, PredictedWins1, PredictedLoss1, Error1);
printf(" %.2f        %.2f        %.0f               %.0f                %.0f \n", p2, winp2, PredictedWins2, PredictedLoss2, Error2);
printf(" %.2f        %.2f        %.0f               %.0f                %.0f \n", p3, winp3, PredictedWins3, PredictedLoss3, Error3);
printf(" %.2f        %.2f        %.0f               %.0f                %.0f \n", p4, winp4, PredictedWins4, PredictedLoss4, Error4);
return 0;
}
