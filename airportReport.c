#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <search.h>

#include "airport.h"

int main(){

  Airport *airport1 = createAirport("LNK", "small_airport", "Lincoln Airport", 40.846176, -96.75471, 1219, "Lincoln", "US");
  Airport *airport2 = createAirport("KCI", "Civillian", "Kansas City International Airport", 40.820600, -96.705600, 1203, "Kansas City", "US");
  Airport *airport3 = createAirport("ORD", "large_airport", "O’Hare International Airport", 41.978611, -87.904724, 668, "Chicago", "US");
  Airport *airport4 = createAirport("WKD", "Military", "Wakanda Airport", 76.2300, -68.9890, 895, "Wakanda", "African Nations");
  Airport *airport5 = createAirport("JFK", "International", "John F. Kennedy Airport", 40.6413, 73.7781, 13.12, "New York", "US");

  Airport *test = (Airport *)malloc(sizeof(Airport) * 5);

  test[0] = *airport1;
  test[1] = *airport2;
  test[2] = *airport3;
  test[3] = *airport4;
  test[4] = *airport5;

  generateReports(test, 5);

  free(airport1);
  free(airport2);
  free(airport3);
  free(airport4);
  free(airport5);

  return 0;
}
