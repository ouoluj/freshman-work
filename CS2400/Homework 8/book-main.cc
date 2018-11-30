//****************************************************************
//
//  Program:        .
//
//  Name:           Derek Baker
//  Email:          db820017@ohio.edu
//
//  Section:        100 (Nasseef Abukamail)
//
//  Description:    .
//
//  Date:           .
//
//****************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Book.h"
using namespace std;

int main() {
  Book b1("Help", 2018, "Baker");
  Book b2("Save us|2023|Hep");

  cout << b1.getTitle() << " | " << b1.getYear() << " | " << b1.getAuthor();
  cout << endl << endl;

  b1.setTitle("Destroy");
  b1.setYear(2022);
  b1.setAuthor("Wing");

  cout << b1.matchAuthor("Wing") << endl;

  if (b1.matchTitle("Destroy")) {
    cout << "hi" << endl;
  }

  b1.outputBook();
  b2.outputBook();
  return 0;
}
