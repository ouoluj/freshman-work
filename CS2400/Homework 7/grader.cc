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
#include <string>
#include <vector>
using namespace std;

void convertKey(char key[], ifstream& inputFile);

int main(int argc, const char **argv) {
  if (argc < 2 || argc > 3) {  // Returns 1 if there is not an input file or output file.
    cout << "No valid input file." << endl;
    return 1;
  }

  ifstream inputFile;
  inputFile.open(argv[1]);
  if (inputFile.fail()) { // Returns 1 if the input file cannot be opened.

  }
  if (argc == 3) { // Opens the output file if one is given. If not, prints to the console.
    ofstream outputFile;
    outputFile.open(argv[2]);
  }

  // vector <char> key = {'A', 'C', 'D', 'B', 'C', 'B', 'D', 'C', 'C', 'A', 'C', 'D', 'A', 'C', 'C'};
  char key[15];
  char answers[15];
  char ch = 0;
  string firstName, lastName;

  // inputFile >> key;
  // for (size_t i = 0; i < 15; i++) {
  //   cout << key[i];
  //   // Function to convert to lowercase.
  // }
  convertKey(key, inputFile);
  while (!inputFile.eof()) {
    inputFile >> firstName >> lastName;
    cout << endl << "Name: " << lastName << ", " << firstName << endl;
    inputFile.ignore(100, ' ');
    inputFile.get(ch);

    // inputFile.get(ch);
    while (ch != '\n') {
      for (size_t i = 0; i < 15; i++) {
        answers[i] = ch;
        cout << answers[i];
        inputFile.get(ch);
      }
      if (argc == 3) {
        // Function to output to file.
        cout << "File" << endl;
      }
      else {
        // Function to output to console.
        cout << "Console" << endl;
      }

      // return 0;
      // inputFile.get(ch);
      // cout << endl;
    }
  }


  inputFile.close();
  // if (argc == 3) {
  //   outputFile.close();
  // }
  return 0;
}

void convertKey(char key[], ifstream& inputFile) {
  inputFile >> key;
  for (size_t i = 0; i < 15; i++) {
    key[i] = tolower(key[i]);
    cout << key[i];
  }
}
