//****************************************************************
//
//  Program:        fbfriends driver
//
//  Name:           Derek Baker
//  Email:          db820017@ohio.edu
//
//  Section:        100 (John Dolan)
//
//  Description:    .
//
//  Date:           2-19-19
//
//  Compiled with C++ 11
//
//****************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "date.h"
#include "friend.h"
//#include "fbfriends.h"

using namespace std;

int main() {
  Friend test;
  Friend test2;

  cin >> test;
  cin >> test2;
  cout << "output: ";
  cout << test.get_name() << ": " << test.get_bday() << endl;

  cout << test << endl;

  if (!(test == test2)) {
    cout << test2 << endl;
  }

  if (test == test2) {
    cout << "These are the same person >:0" << endl;
  }

  return 0;
}
