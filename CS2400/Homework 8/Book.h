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
