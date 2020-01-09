/**
 * Author: Aryan Timla
 * Final Exam
 * Date: 12-17-2019
 * This program designs C structure to encapsulate the attributes to model a book record.
 * It also designs several functions to support your structure including factory functions, functions to create a string representation, print records, etc. and
 * other several utility functions.
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "book.h"

Book * createBook(const char * title,
                  const char * authorFirstName,
                  const char * authorLastName,
                  int releaseYear,
                  double rating) {
                    if(title == NULL || authorFirstName == NULL ||
                      authorLastName == NULL || releaseYear == NULL){
                      printf("ERROR\n");
                      return NULL;
                    }
                    Book* book = (Book *)malloc(sizeof(Book) * 1);

                    book->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
                    strcpy(book->title, title);

                    book->authorFirstName = (char *)malloc(sizeof(char) * (strlen(authorFirstName) + 1));
                    strcpy(book->authorFirstName, authorFirstName);

                    book->authorLastName = (char *)malloc(sizeof(char) * (strlen(authorLastName) + 1));
                    strcpy(book->authorLastName, authorLastName);

                    book->releaseYear = releaseYear;

                    book->rating = rating;

                    return book;
                  }

void initBook(Book * book,
              const char *title,
              const char * authorFirstName,
              const char *authorLastName,
              int releaseYear,
              double rating) {
                book->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
                strcpy(book->title, title);

                book->authorFirstName = (char *)malloc(sizeof(char) * (strlen(authorFirstName) + 1));
                strcpy(book->authorFirstName, authorFirstName);

                book->authorLastName = (char *)malloc(sizeof(char) * (strlen(authorLastName) + 1));
                strcpy(book->authorLastName, authorLastName);

                book->releaseYear = releaseYear;

                book->rating = rating;
}

char * bookToString(const Book *b) {
  if (b == NULL) {
    char *result = (char *)malloc(sizeof(char) * 7);
    strcpy(result, "(null)");
    return result;
  }

  // compute the number of characters we'll need:
  int n = strlen(b->title) + strlen(b->authorFirstName)+ strlen(b->authorLastName)+
  sizeof(int) + sizeof(double) + 20;

  // create a result string
  char *str = (char *)malloc(sizeof(char) * n);

  // format the student into the temporary string
  sprintf(str, "%s  by %s, %s, (%d) %.2f", b->title,
           b->authorLastName, b->authorFirstName, b->releaseYear, b->rating);

  // return the result
  return str;
}

int cmpByAuthorYear(const void *a, const void *b) {
  const Book *a1 = (const Book *)a;
  const Book *a2 = (const Book *)b;
  char result = strcmp(a1->authorLastName, a2->authorLastName);
  if (result == 0) {
  double a1yr = a1->releaseYear;
  double a2yr = a2->releaseYear;
  if (a1yr > a2yr) {
    return 1;
  } else if (a1yr == a2yr) {
    return 0;
  } else {
    return -1;
  }
} else {
  return result;
}
}

int cmpByTitle(const void *a, const void *b) {
  const Book *a1 = (const Book *)a;
  const Book *a2 = (const Book *)b;
  return strcmp(a1->title, a2->title);
}

int cmpByRating(const void *a, const void *b) {
  const Book *a1 = (const Book *)a;
  const Book *a2 = (const Book *)b;
  double a1rt = a1->rating;
  double a2rt = a2->rating;
  if (a1rt < a2rt) {
    return 1;
  } else if (a1rt == a2rt) {
    return 0;
  } else {
    return -1;
  }
}

void generateReports(Book *books, int n) {

  printf("\n\nList of books - Sorted by Title\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  //TODO: sort books by title
  qsort(books, n, sizeof(Book), cmpByTitle);
  printBookArray(books, n);

  printf("\n\nList of books - Sorted by Author/Year\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  //TODO: sort books by author (last name/first name),
  //      then by year (oldest first) for
  //      books by the same author
  qsort(books, n, sizeof(Book), cmpByAuthorYear);
  printBookArray(books, n);

  printf("\n\nList of books - Sorted by Rating\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  //TODO: sort books by rating, highest to lowest
  qsort(books, n, sizeof(Book), cmpByRating);
  printBookArray(books, n);

  return;
}

/* utility functions -- these have been done for you */
char * deepCopy(const char *s) {
  char *copy = (char *) malloc( (strlen(s) + 1) * sizeof(char) );
  strcpy(copy, s);
  return copy;
}

void printBookArray(const Book *b, int n) {
  int i;
  for(i=0; i<n; i++) {
    char *s = bookToString(&b[i]);
    printf("%s\n", s);
    free(s);
  }
}
