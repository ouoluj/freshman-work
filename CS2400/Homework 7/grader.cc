//****************************************************************
//
//  Program:        Test Grader
//
//  Name:           Derek Baker
//  Email:          db820017@ohio.edu
//
//  Section:        100 (Nasseef Abukamail)
//
//  Description:    .
//
//  Date:           11-13-18
//
//****************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

int main(int argc, const char **argv) {
  if (argc < 2 || argc > 3) {  // Returns 1 if there is not an input file or output file.
    cout << "No valid input file." << endl;
    return 1;
  }

  ifstream inputFile;
  inputFile.open(argv[1]);
  if (inputFile.fail()) { // Returns 1 if the input file cannot be opened.

  }
  // if (argc == 3) { // Opens the output file if one is given. If not, prints to the console.
  //   ofstream outputFile;
  //   outputFile.open(argv[2]);
  // }

  // vector <char> key = {'A', 'C', 'D', 'B', 'C', 'B', 'D', 'C', 'C', 'A', 'C', 'D', 'A', 'C', 'C'};
  char key[20];
  char answers[20];
  char ch;
  string firstName, lastName;

  inputFile >> key;
  for (size_t i = 0; i < 15; i++) {
    cout << key[i];
  }
  while (!inputFile.eof()) {
    inputFile >> firstName >> lastName;

    inputFile.get(ch);
    while (ch != '\n') {
      for (size_t i = 1; i < 15; i++) {

      }
    }
  }


  inputFile.close();
  // if (argc == 3) {
  //   outputFile.close();
  // }
  return 0;
}
