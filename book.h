/**
 * This structure models a book.
 */
typedef struct {
  const char * title;
  const char * authorFirstName;
  const char * authorLastName;
  int releaseYear;
  double rating;
} Book;

/**
 * A function that creates a new Book instance with
 * the given values.  Deep copies of the strings are
 * made.
 */
Book * createBook(const char *title,
                  const char *authorFirstName,
                  const char *authorLastName,
                  int releaseYear,
                  double rating);

/**
 * Initializes the given book with the given
 * values, making deep copies of the strings.
 */
void initBook(Book * book,
              const char *title,
              const char * authorFirstName,
              const char *authorLastName,
              int releaseYear,
              double rating);

/**
 * A function that produces a human-readable
 * string of the given book.
 */
char * bookToString(const Book *b);

/**
 * A comparator function that orders books first
 * by author (last name/first name) and then by
 * year oldest to newest
 */
int cmpByAuthorYear(const void *a, const void *b);

/**
 * A comparator function that orders books by title
 */
int cmpByTitle(const void *a, const void *b);

/**
 * A comparator function that orders books by
 * rating, highest to lowest
 */
int cmpByRating(const void *a, const void *b);

/**
 * Generates several different orderings of the given
 * array of Book structures
 */
void generateReports(Book *books, int n);

/**
 * Utility function that performs a deep copy of a string.
 *
 * This function has been implemented for you.
 */
char * deepCopy(const char *s);

/**
 * This function prints an entire array of Books
 * to the standard output.
 *
 * This function has been implemented for you.
 */
void printBookArray(const Book *b, int n);
