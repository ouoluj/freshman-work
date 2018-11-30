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
//  Date:           11-28-18
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

  string lowerTargetTitle;
  string lowerTitle;

  lowerTargetTitle = makeLower(targetTitle);
  lowerTitle = makeLower(title);

  if (lowerTitle.find(lowerTargetTitle) < title.length()) {
    return true;
  }

  return false;

}

bool Book::matchYear(string targetYear) {
  string tempYear = to_string(year);

  if (tempYear.find(targetYear) < tempYear.length()) {
    return true;
  }

  return false;
}

bool Book::matchAuthor(string targetAuthor) {

  string lowerTargetAuthor;
  string lowerAuthor;
  cout << author << endl;

  lowerTargetAuthor = makeLower(targetAuthor);
  lowerAuthor = makeLower(author);

  if (lowerAuthor.find(lowerTargetAuthor) < author.length()) {
    return true;
  }

  return false;

}

bool Book::match(string target) {
  if (matchTitle(target)) {
    return true;
  }
  if (matchYear(target)) {
    return true;
  }
  if (matchAuthor(target)) {
    return true;
  }
  else {
    return false;
  }
}


void Book::outputBook() {
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Author: " << author << endl;
  cout << endl;
}
