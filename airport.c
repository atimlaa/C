/**
 * Author: Aryan Timla
 * Hack 13
 * Date: 11-21-2019
 * This program designs C structure to encapsulate the attributes to model an airport record from the ICAO database.
 * It also designs several functions to support your structure including factory functions, functions to create a string representation, print records, etc. and
 * other several utility functions using the structure to compute the air distance(s) between airport locations using their latitude and longitude.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "airport.h"

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv){
                         if(type == NULL || name == NULL || city == NULL || countryAbbrv == NULL){
                           printf("ERROR\n");
                           return NULL;
                         }
                         Airport* airport = (Airport *)malloc(sizeof(Airport) * 1);

                         airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
                         strcpy(airport->gpsId, gpsId);

                         airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
                         strcpy(airport->type, type);

                         airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
                         strcpy(airport->name, name);

                         airport->latitude = latitude;

                         airport->longitude = longitude;

                         airport->elevationFeet = elevationFeet;

                         airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
                         strcpy(airport->city, city);

                         airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
                         strcpy(airport->countryAbbrv, countryAbbrv);

                         return airport;
                       }

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv){
                   airport->gpsId = (char *)malloc(sizeof(char) * (strlen(gpsId) + 1));
                   strcpy(airport->gpsId, gpsId);

                   airport->type = (char *)malloc(sizeof(char) * (strlen(type) + 1));
                   strcpy(airport->type, type);

                   airport->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
                   strcpy(airport->name, name);

                   airport->latitude = latitude;

                   airport->longitude = longitude;

                   airport->elevationFeet = elevationFeet;

                   airport->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
                   strcpy(airport->city, city);

                   airport->countryAbbrv = (char *)malloc(sizeof(char) * (strlen(countryAbbrv) + 1));
                   strcpy(airport->countryAbbrv, countryAbbrv);
                 }

char* airportToString(const Airport* a){
  if (a == NULL) {
    char *result = (char *)malloc(sizeof(char) * 7);
    strcpy(result, "(null)");
    return result;
  }

  // compute the number of characters we'll need:
  int n = strlen(a->gpsId) + strlen(a->type)+ strlen(a->name)+ sizeof(double) + sizeof(double) + sizeof(int) +
  strlen(a->city)+ strlen(a->countryAbbrv) + 20;

  // create a result string
  char *str = (char *)malloc(sizeof(char) * n);

  // format the student into the temporary string
  sprintf(str, "%s, %s, %s, %f, %f %d, %s, %s", a->gpsId,
          a->type, a->name, a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);

  // return the result
  return str;
}

double getAirDistance(const Airport* origin, const Airport* destination){
  //declarations
  double distance = 0.0;
  double Radius_of_Earth = 6371;
  double latitude1 = origin->latitude;
  double latitude2 = destination->latitude;
  double longitude1 = origin->longitude;
  double longitude2 = destination->longitude;

  double latitude_in_Radians1 = (latitude1/180) * M_PI;
  double latitude_in_Radians2 = (latitude2/180) * M_PI;
  double longitude_in_Radians1 = (longitude1/180) * M_PI;
  double longitude_in_Radians2 = (longitude2/180) * M_PI;

  //formula
  distance = acos((sin(latitude_in_Radians1) * sin(latitude_in_Radians2)) + (cos(latitude_in_Radians1) * cos(latitude_in_Radians2)) * cos(longitude_in_Radians2 - longitude_in_Radians1)) * Radius_of_Earth;
  return distance;
}

double getEstimatedTravelTime(const Airport* stops,
                            int size,
                            double aveKmsPerHour,
                            double aveLayoverTimeHrs){
    //Error Checking
    if(stops == NULL){
      return 1;
    }
    if(aveKmsPerHour < 0){
      return 1;
    }

    double distance = 0.0;
    //loop
    for(int i = 1; i < size; i++){
      distance += getAirDistance(&stops[i - 1], &stops[i]);
    }

    double totalTime = distance/aveKmsPerHour + (aveLayoverTimeHrs * (size - 2));
    return totalTime;
}

/**
 * A comparator function that orders the two Airport structures by
 * their GPS IDs in lexicographic order.
 */
int cmpByGPSId(const void *a, const void *b) {
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return strcmp(a1->gpsId, a2->gpsId);
}

/**
 * A comparator function that orders the two Airport structures by
 * their type.
 */
int cmpByType(const void *a, const void *b) {
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return strcmp(a1->type, a2->type);
}

/**
 * A comparator function that orders the two Airport structures by
 * their name in lexicographic order.
 */
int cmpByName(const void *a, const void *b) {
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  return strcmp(a1->name, a2->name);
}

/**
 * A comparator function that orders the two Airport structures by
 * their name in reverse lexicographic order.
 */
int cmpByNameDesc(const void *a, const void *b) {
  return cmpByName(b, a);
}

/**
 * A comparator function that orders the two Airport structures first by
 * country, then by city
 */
int cmpByCountryCity(const void *a, const void *b) {
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  char result = strcmp(a1->countryAbbrv, a2->countryAbbrv);
  if (result == 0) {
    return strcmp(a1->city, a2->city);
  } else {
    return result;
  }
}

/**
 * A comparator function that orders the given Airport structures
 * by their latitudes north to south
 */
int cmpByLatitude(const void *a, const void *b) {
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  double a1lt = a1->latitude;
  double a2lt = a2->latitude;
  if (a1lt > a2lt) {
    return 1;
  } else if (a1lt == a2lt) {
    return 0;
  } else {
    return -1;
  }
}

/**
 * A comparator function that orders the given Airport structures
 * by their longitudes west to east
 */
int cmpByLongitude(const void *a, const void *b) {
  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  double a1lg = a1->longitude;
  double a2lg = a2->longitude;
  if (a1lg < a2lg) {
    return -1;
  } else if (a1lg == a2lg) {
    return 0;
  } else {
    return 1;
  }
}

/**
 * A comparator function that orders the two Airport structures by
 * their relative distance from Lincoln Municipal Airport
 * (0R2, 40.846176, -96.75471)
 * in ascending order according (closest to Lincoln would come first)
 */
int cmpByLincolnDistance(const void *a, const void *b) {
  Airport *LNK =
      createAirport("3FD5", "heliport", "Arnold Palmer Hospital Heliport",
                    40.8507, 96.7581, 150, "Orlando", "US-FL");

  const Airport *a1 = (const Airport *)a;
  const Airport *a2 = (const Airport *)b;
  double a1Dist = getAirDistance(LNK, a1);
  double a2Dist = getAirDistance(LNK, a2);
  if (a1Dist < a2Dist) {
    return -1;
  } else if (a1Dist == a2Dist) {
    return 0;
  } else {
    return 1;
  }
}

void printAirport(const Airport *airports) {
  if (airports == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%s, %s, %s, %f, %f, %d, %s, %s\n", airports->gpsId, airports->type,
         airports->name, airports->latitude, airports->longitude,
         airports->elevationFeet, airports->city, airports->countryAbbrv);
}

void printAllAirports(Airport *airports, int size) {
  for (int i = 0; i < size; i++) {
    printAirport(&airports[i]);
  }
}

void generateReports(Airport * airports, int n) {
  //Sorting by gpsId:
  printf("Airports sorted by gpsId:\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  printAllAirports(airports, n);
  printf("\n");

  //Sorting by type:
  printf("Airports sorted by type:\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  printAllAirports(airports, n);
  printf("\n");

  //Sorting by name:
  printf("Airports sorted by name:\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  printAllAirports(airports, n);

  //Sorting by name in desc order:
  printf("Airports sorted by name in desc order:\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  printAllAirports(airports, n);
  printf("\n");

  //Sorting by country then city:
  printf("Airports sorted by country/city:\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  printAllAirports(airports, n);
  printf("\n");

  //Sorting by latitude:
  printf("Airports sorted by latitiude:\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  printAllAirports(airports, n);

  //Sorting by longitude:
  printf("Airports sorted by longitude:\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printAllAirports(airports, n);
  printf("\n");

  //Sorting by Lincoln distance:
  printf("\nAirports sorted by distance from Lincoln:\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAllAirports(airports, n);
  printf("\n");

  //Closest airport to Lincoln
  printf("The closest airport to Lincoln is:\n");
  printf("%s\n", airportToString(&airports[0]));
  printf("\n");

  //Furthest airport from Lincoln
  printf("Furthest Aiport from Lincoln:\n");
  printf("%s\n", airportToString(&airports[4]));
  printf("\n");

  //The median airport with respect to longitude
  printf("West-East Median:\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printf("%s\n", airportToString(&airports[n / 2]));
  printf("\n");

  //checking for New York, US airport
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  for (int i = 0; i < n; i++) {
    if (strcmp(airports[i].countryAbbrv, "US") == 0 && strcmp(airports[i].city, "New York") == 0) {
     printf("This Airport is in New York, US:\n");
     printf("%s\n", airportToString(&airports[i]));
   } else {
     printf("Airport in New York, US is not in this list\n");
   }
  }

  //Checking for large_airport
  qsort(airports, n, sizeof(Airport), cmpByType);
  for (int i = 0; i < n; i++) {
     if (strcmp(airports[i].type, "large_airport") == 0) {
      printf("This Airport is in Large airport type:\n");
      printf("%s\n", airportToString(&airports[i]));
    } else {
      printf("No large airport in this list\n");
    }
  }
}
