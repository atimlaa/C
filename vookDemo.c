/**
 * This is just a demo file for local testing
 * of your book functions.  You may modify it if
 * you wish, but it is not to be turned in.
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "book.h"

int main(int argc, char **argv) {

  int n = 5;
  Book *books = (Book *) malloc(sizeof(Book) * n);
  initBook(&books[0], "Harry Potter and the Deathly Hallows",
           "J.K.","Rowling",2007,4.62);
  initBook(&books[1], "Pachinko",
           "Min Jin","Lee",2017,4.26);
  initBook(&books[2], "The Name of the Wind",
           "Patrick","Rothfuss",2007,4.55);
  initBook(&books[3], "The Wise Man's Fear",
           "Patrick","Rothfuss",2011,4.58);
  initBook(&books[4], "The Three-Body Problem",
           "Cixin","Liu",2014,4.06);

  generateReports(books, n);

  return 0;
}
