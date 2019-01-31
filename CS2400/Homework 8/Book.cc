//****************************************************************
//
//  Class:          Book
//
//  Name:           Derek Baker
//  Email:          db820017@ohio.edu
//
//  Section:        100 (Nasseef Abukamail)
//
//  Description:    A class used to create a Book object, with functions used to
//                  get/set a book's title, year, or author, and to search a book
//                  for a given string (title, year, author, or any field).
//
//  Date:           11-29-18
//
//****************************************************************

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

// Constructors
Book::Book() {
  title = "***";
  year = 0;
  author = "***";
}

Book::Book(string newTitle, int newYear, string newAuthor) {
  title = "***";
  year = 0;
  author = "***";

  title = newTitle;
  if (newYear > 0) {
    year = newYear;
  }
  author = newAuthor;
}

Book::Book(string allData) {
  int bar1pos = allData.find('|');
  int bar2pos = allData.find('|', bar1pos + 1);

  title = allData.substr(0, bar1pos);
  year = stoi(allData.substr(bar1pos + 1, bar2pos));
  author = allData.substr(bar2pos + 1);
}

// Setters
void Book::setTitle(string newTitle) {
  title = newTitle;
}

void Book::setYear(int newYear) {
  if (newYear > 0) {
    year = newYear;
  }
}

void Book::setAuthor(string newAuthor) {
  author = newAuthor;
}

// Getters
string Book::getTitle() {
  return title;
}

int Book::getYear() {
  return year;
}

string Book::getAuthor() {
  return author;
}

// Helpers
string Book::makeLower(string target) {
  string lower;

  for (size_t i = 0; i < target.length(); i++) {
    lower += tolower(target[i]);
  }

  return lower;
}

bool Book::matchTitle(string targetTitle) {

  string lowerTargetTitle; // Target title, lowercased.
  string lowerTitle;       // Current title, lowercased.

  lowerTargetTitle = makeLower(targetTitle); // Lowercases the target title.
  lowerTitle = makeLower(title);             // Lowercases the original title.

  if (lowerTitle.find(lowerTargetTitle) < title.length()) { // Returns position of match, if found. If not, the result is higher than title.length().
    return true;
  }

  return false; // If no match, returns false.

}

bool Book::matchYear(string targetYear) {
  string tempYear = to_string(year); // Converts current year to a string, to be compared.

  if (tempYear.find(targetYear) < tempYear.length()) { // Returns position of match, if found. If not, the result is higher than year.length().
    return true;
  }

  return false; // If no match, returns false.
}

bool Book::matchAuthor(string targetAuthor) {

  string lowerTargetAuthor; // Target author, lowercased.
  string lowerAuthor;       // Current author, lowercased.

  lowerTargetAuthor = makeLower(targetAuthor); // Lowercases the target author.
  lowerAuthor = makeLower(author);             // Lowercases the current author.

  if (lowerAuthor.find(lowerTargetAuthor) < author.length()) { // Returns position of match, if found. If not, the result is higher than author.length().
    return true;
  }

  return false; // If no match, returns false.
}

bool Book::match(string target) {
  if (matchTitle(target)) {  // Returns true if the target matches the title.
    return true;
  }
  if (matchYear(target)) {   // Returns true if the target matches the year.
    return true;
  }
  if (matchAuthor(target)) { // Returns true if the target matches the author.
    return true;
  }
  return false;              // Otherwise, returns false.
}


void Book::outputBook() {
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Author: " << author << endl;
  cout << endl;
}
