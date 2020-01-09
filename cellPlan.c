/**
 * Author: Aryan Timla
 *
 * This program interactively prompts the user for
 * their Number of GB in the plan per 30 day period
 *The current day in the 30 day period (in the range 1, first day, 30 for the last day)
 *The total number of GB used so far and compute whether the customer is over, under, or right on the
 *average daily usage of their plan and also inform them of how many GB are left
 *and how many, on average, they can use per day for the rest of the 30 day period.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv){

float GB, GBused;
int day;
if(argc !=4)
{printf("Invalid!! Please enter only 3 arguments\n");
exit (1);
}
GB = atof(argv[1]);
day = atof(argv[2]);
GBused = atof(argv[3]);

int daysused, daysremaining;
double Average, Averagedaily;
daysremaining = 30 - day;
Average = GBused / day;
Averagedaily = GB / 30;
printf("%d days used, %d days remaining\n", day, daysremaining);
printf("Average daily use: %lf GB/day\n", Average);
double Exceedby, stay;
Exceedby = (Average * 30) - (Averagedaily* 30);
stay = (GB - GBused) / (30 - day);
if (Average > Averagedaily) {
printf("You are EXCEEDING your average daily use (%.2lf GB/day)\n", Averagedaily );
printf("Continuing this high usage, you'll exceed your data plan by %lf GB\n", Exceedby );
printf("To stay below your data plan, use no more than %lf GB/day.\n", stay );
}
double Under;
Under = (Averagedaily * 30) - (Average * 30);
if (Averagedaily > Average) {
printf("You are UNDER your average daily use (%.2lf GB/day)\n", Averagedaily );
printf("To stay in your data plan, use %lf GB/day.\n", stay );
}
if (Averagedaily == Average) {
printf("You are at your average daily use (%.2lf GB/day)\n", Averagedaily );
printf("Continuing this usage, you'll be exactly in your data plan\n");
printf("To stay in your data plan, use %lf GB/day.\n", Averagedaily );
}
if (GBused >= GB) {
printf("You have already met your limit for this month. Looks like you're gettin some overage charges\n");
}
return 0;
}
