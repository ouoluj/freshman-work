//****************************************************************
//
//  Class:   Book
//
//  Purpose: To save and interact with a book object, with a title, author,
//           and year.
//
//  Functions:
//           Constructors
//             Book() default constructor
//             Book(string newTitle, int newYear, string newAuthor) Each datatype given separately
//             Book(string allData) Book information given all at once, separated by pipes.
//           Setters
//             void setTitle(string newTitle)   Sets Book's title
//             void setYear(int newYear)        Sets Book's year
//             void setAuthor(string newAuthor) Sets Book's author
//           Getters
//             string getTitle()                Gets Book's title
//             int getYear()                    Gets Book's year
//             string getAuthor()               Gets Book's author
//           Helpers
//             string makeLower(string target);
//             bool matchTitle(string targetTitle);
//             bool matchAuthor(string targetAuthor);
//             bool matchYear(string targetYear);
//             bool match(string target);
//             void outputBook();
//
//****************************************************************

#ifndef BOOK
#define BOOK

using namespace std;
class Book {

  private:
  string title;
  int year;
  string author;

  public:
  // Constructors
  Book();
  Book(string newTitle, int newYear, string newAuthor);
  Book(string allData);

  // Setters
  void setTitle(string newTitle);
  void setYear(int newYear);
  void setAuthor(string newAuthor);

  // Getters
  string getTitle();
  int getYear();
  string getAuthor();

  // Helpers
  string makeLower(string target);
  bool matchTitle(string targetTitle);
  bool matchAuthor(string targetAuthor);
  bool matchYear(string targetYear);
  bool match(string target);
  void outputBook();
};
#endif
