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
#include "fbfriends.h"

using namespace std;

int main() {
  ifstream ins;
  Friend test;
  Friend test2;
  FBFriends fb, fb2;

  // ins.open("rplant.txt");

  cin >> test;
  cin >> test2;

  cout << test << endl;
  cout << test2 << endl;

  // fb.load(ins);
  // fb.show_all(cout);

  // ins.close();

  return 0;
}
