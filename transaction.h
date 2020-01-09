// Structure for the Transaction
typedef struct {
  char* UUID;
  char* typeofTrans;
  double amount;
  char* accountNumber;
  double beforeTrans;
  double afterTrans;
  char* transfer_accountNumber;
} Transaction;

// a function that reads the file and returns to an array
Transaction* readFile(const char* file);

/*
* A function to create a new Transdata with the given attributes.
* This function should make *deep* copies of each of the relevant fields and
* return a pointer to the newly created Transdata structure.
*/
Transaction *createTransaction(const char *UUID, const char *typeofTrans,
                           double amount, const char *accountNumber,
                           double beforeTrans, double afterTrans,
                           const char *transfer_accountNumber);

// a function that generates reports
void generateReports(Transaction* transaction, int n);
