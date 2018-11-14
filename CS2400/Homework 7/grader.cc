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
using namespace std;

void convertAnswer(char answer[], ifstream& inputFile);
double getScore(char answers[], char key[]);
char getGradeLetter(double score);
void outputToConsole(string firstName, string lastName, double score, char answers[], char key[]);
void outputToFile(string firstName, string lastName, double score, char answers[], char key[], string outputName);

int main(int argc, const char **argv) {
  bool outputFilePresent = false;
  string outputName;
  if (argc < 2 || argc > 3) {  // Returns 1 if there is not an input file or output file.
    cout << "No valid input file." << endl;
    return 1;
  }

  ifstream inputFile;
  inputFile.open(argv[1]);
  if (inputFile.fail()) { // Returns 1 if the input file cannot be opened.
    cout << "No valid input file." << endl;
    return 1;
  }
  if (argc == 3) { // Creates a flag, used later, to indicate an output file will be created.
    outputFilePresent = true;
    outputName = argv[2];
  }

  char key[15];
  char answers[15];
  char ch = 0;
  double score = 0.0;
  string firstName, lastName;

  inputFile >> key; // Take the answer key.
  convertAnswer(key, inputFile); // Function to convert key to lowercase, for easier comparison.

  while (!inputFile.eof()) { // Loop to go through all the students' names and answers.
    score = 0; // Re-initialize score after each student.
    inputFile >> firstName >> lastName; // Find each student's name.
    inputFile.ignore(100, ' '); // Flush after taking the name, to start taking answers.

    inputFile.get(ch); // Start of sentinel loop.
    while (ch != '\n') { // Loop to go for each student.
      for (size_t i = 0; i < 15; i++) { // Fill an array with the student's answers.
        answers[i] = ch;
        inputFile.get(ch);
      }
      convertAnswer(answers, inputFile); // Function to convert answers to lowercase, for easier comparison.
      score = getScore(answers, key);// Function to get grade.

      if (outputFilePresent == true) {
      outputToFile(firstName, lastName, score, answers, key, outputName);
      }
      else {
        outputToConsole(firstName, lastName, score, answers, key);
      }

    }
  }


  inputFile.close();
  return 0;
}

//****************************************************************
//
//  Function:         convertAnswer
//
//  Purpose:          To convert a string of students' answers to all lowercase,
//                    and replace non-answers with dashes.
//
//  Parameters:       char answers[], which represents the array of a single
//                      student's answers, or the array of answers used by the key.
//
//  Pre Conditions:   .
//
//  Post Conditions:  .
//
//****************************************************************
void convertAnswer(char answers[], ifstream& inputFile) {
  for (size_t i = 0; i < 15; i++) {
    if (isupper(answers[i])) {
      answers[i] = tolower(answers[i]);
    }
    if (isspace(answers[i])) {
      answers[i] = '-';
    }
    // cout << answers[i];
  }
}

//****************************************************************
//
//  Function:         getScore
//
//  Purpose:          To find the percentage grade of a single student's test.
//
//  Parameters:       char answers[], the array for the student's answers.
//                    char key[], used to compare the student's answers to the
//                      correct answers.
//
//  Pre Conditions:   valid arrays for the student's answers, and a valid key.
//
//  Post Conditions:  .
//
//****************************************************************
double getScore(char answers[], char key[]) {
  int correctAnswers = 0; // Used to
  double score = 0.0;
  for (size_t i = 0; i < 15; i++) {
    if (answers[i] == key[i]) {
      correctAnswers ++;
    }
  }
  score = (correctAnswers / 15.0) * 100.0;
  return score;
}

//****************************************************************
//
//  Function:         getGradeLetter
//
//  Purpose:          Function to return the character of a single student's
//                      letter grade.
//
//  Parameters:       score
//
//  Pre Conditions:   A valid student's score
//
//  Post Conditions:  .
//
//****************************************************************
char getGradeLetter(double score) {
  char grade;

  if (score >= 90.0) {
    grade = 'A';
  }
  else if (80.0 <= score && score < 90.0) {
    grade = 'B';
  }
  else if (70.0 <= score && score < 80.0) {
    grade = 'C';
  }
  else if (60.0 <= score && score < 70.0) {
    grade = 'D';
  }
  else {
    grade = 'F';
  }

  return grade;
}

//****************************************************************
//
//  Function:         outputToConsole
//
//  Purpose:          Function to output the scores and answers of one student
//                      to the console.
//
//  Parameters:       firstName
//                    lastName
//                    score
//                    answers[]
//                    key[]
//
//  Pre Conditions:   .
//
//  Post Conditions:  .
//
//****************************************************************
void outputToConsole(string firstName, string lastName, double score, char answers[], char key[]) {
  cout << lastName << ", " << firstName << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Answers, correct answer in parentheses." << endl;

  for (size_t i = 0; i < 15; i++) {
    cout << setw(3) << (i + 1) << ": ";
    cout << answers[i] << "(" << key[i] << ")";
    if (( i + 1 ) % 5 == 0) {
      cout << endl;
    }
  }

  cout.setf(ios::fixed);
  cout.precision(1);
  cout << endl << "Score: " << score << "% " << getGradeLetter(score) << endl;
  cout << "------------------------------------------------" << endl << endl;
}

//****************************************************************
//
//  Function:         outputToFile
//
//  Purpose:          Function to output the scores and answers of one student
//                      to the console.
//
//  Parameters:       firstName
//                    lastName
//                    score
//                    answers[]
//                    key[]
//
//  Pre Conditions:   .
//
//  Post Conditions:  .
//
//****************************************************************
void outputToFile(string firstName, string lastName, double score, char answers[], char key[], string outputName) {
  ofstream outputFile;
  outputFile.open(outputName.c_str(), ios::app);

  outputFile << lastName << ", " << firstName << endl;
  outputFile << "------------------------------------------------" << endl;
  outputFile << "Answers, correct answer in parentheses." << endl;

  for (size_t i = 0; i < 15; i++) {
    outputFile << setw(3) << (i + 1) << ": ";
    outputFile << answers[i] << "(" << key[i] << ")";
    if (( i + 1 ) % 5 == 0) {
      outputFile << endl;
    }
  }

  outputFile.setf(ios::fixed);
  outputFile.precision(1);
  outputFile << endl << "Score: " << score << "% " << getGradeLetter(score) << endl;
  outputFile << "------------------------------------------------" << endl << endl;

  outputFile.close();
}
