/**
 * Author: Aryan Timla
 * Hack 14
 * Date: 12-09-2019
 * This is the main function for the Hack that generates the report
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

int main(int argc, char **argv) {
  Transaction *transfile = readFile(argv[1]);
  FILE *inputFile = fopen(argv[1], "r");
  char buff[20];
  fgets(buff, 10, inputFile);
  int size = atoi(buff);

  // close the file
  fclose(inputFile);
  // generate reports
  generateReports(transfile, size);
  return 0;
}
