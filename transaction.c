/**
 * Author: Aryan Timla Collab: Matthew Mai
 * Hack 14
 * Date: 12-09-2019
 * This program designs a mini-project in which a large amount of transaction
* data from a financial institution is processed. The data represents transactions
 * that transfer funds from or to an account
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

Transaction *readFile(const char *file) {
  FILE *inputFile = fopen(file, "r");
  // Error checking
  if (inputFile == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", file);
    exit(1);
  }

  // read the file, line by line
  int i = 0;
  int size = 1000;
  char *temp = (char *)malloc(sizeof(char) * size);

  // read the first line and get the records in the whole file
  fgets(temp, size, inputFile);
  int newsize = atoi(temp);
  // create enough space for the data
  Transaction *transactions = (Transaction *)malloc(sizeof(Transaction) * newsize);
  // start loop until the last file and the number of record the size indicate
  while (fgets(temp, size, inputFile) != NULL && i < newsize) {
    char *UUID;
    char *typeofTrans;
    char *accountNumber;
    char *transfer_accountNumber;
    double amount, beforeTrans, afterTrans;
    // remove the endline character
    temp[strlen(temp) - 1] = '\0';
    // start token by "," to get individual data
    UUID = strtok(temp, ",");
    typeofTrans = strtok(NULL, ",");
    amount = atof(strtok(NULL, ","));
    accountNumber = strtok(NULL, ",");
    beforeTrans = atof(strtok(NULL, ","));
    afterTrans = atof(strtok(NULL, ","));
    transfer_accountNumber = strtok(NULL, ",");

    // call the function to create the transaction
    Transaction *trans =
        createTransaction(UUID, typeofTrans, amount, accountNumber,
                        beforeTrans, afterTrans, transfer_accountNumber);
    transactions[i] = *trans;
    i++;
  }

  // close the file
  fclose(inputFile);

  free(temp);

  return transactions;
}

/*
*This function creates the transaction
*/
Transaction *createTransaction(const char *UUID, const char *typeofTrans,
                           double amount, const char *accountNumber,
                           double beforeTrans, double afterTrans,
                           const char *transfer_accountNumber) {
  Transaction *transaction = (Transaction *)malloc(sizeof(Transaction) * 1);

  transaction->UUID = (char *)malloc(sizeof(char) * (strlen(UUID) + 1));
  strcpy((char *)transaction->UUID, UUID);

  transaction->typeofTrans = (char *)malloc(sizeof(char) * (strlen(typeofTrans) + 1));
  strcpy((char *)transaction->typeofTrans, typeofTrans);

  transaction->amount = amount;

  transaction->accountNumber =
      (char *)malloc(sizeof(char) * (strlen(accountNumber) + 1));
  strcpy((char *)transaction->accountNumber, accountNumber);

  transaction->beforeTrans = beforeTrans;

  transaction->afterTrans = afterTrans;

  transaction->transfer_accountNumber =
  (char *)malloc(sizeof(char) * (strlen(transfer_accountNumber) + 1));
  strcpy((char *)transaction->transfer_accountNumber, transfer_accountNumber);

  return transaction;
}

/*
* This function generates the report
*/
void generateReports(Transaction * transaction, int n) {
  int i = 0, counter1 = 0;
  double total1 = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(transaction[i].typeofTrans, "PAYMENT") == 0) {
      counter1++;
      total1 = total1 + transaction[i].amount;
    }
  }

  int counter2 = 0;
  double total2 = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(transaction[i].typeofTrans, "TRANSFER") == 0) {
      counter2++;
      total2 = total2 + transaction[i].amount;
    }
  }

  int counter3 = 0;
  double total3 = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(transaction[i].typeofTrans, "WITHDRAWAL") == 0) {
      counter3++;
      total3 = total3 + transaction[i].amount;
    }
  }

  int counter4 = 0;
  double total4 = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(transaction[i].typeofTrans, "DEBIT") == 0) {
      counter4++;
      total4 = total4 + transaction[i].amount;
    }
  }

  int counter5 = 0;
  double total5 = 0;
  for (i = 0; i < n; i++) {
    if (strcmp(transaction[i].typeofTrans, "DEPOSIT") == 0) {
      counter5++;
      total5 = total5 + transaction[i].amount;
    }
  }

  int totalcount = counter1 + counter2 + counter3 + counter4 + counter5;
  double totaltotal = total1 + total2 + total3 + total4 + total5;

  /*
  * Report Print layount
  */
  printf("===============================================\n");
  printf("Final Report\n");
  printf("===============================================\n");
  printf("Type            Count             Total\n");
  printf("===============================================\n");
  printf("Payment     %8d        $%11.2f \n", counter1, total1);
  printf("Transfer    %8d        $%11.2f \n", counter2, total2);
  printf("Withdraw    %8d        $%11.2f \n", counter3, total3);
  printf("Debit       %8d        $%11.2f \n", counter4, total4);
  printf("Deposit     %8d        $%11.2f \n", counter5, total5);
  printf("================================================\n");
  printf("Total       %8d        $%11.2f \n", totalcount, totaltotal);
}
