//****************************************************************
//
//  Program:        Household class testing
//
//  Name:           Derek Baker
//  Email:          db820017@ohio.edu
//
//  Section:        100 (John Dolan)
//
//  Description:    .
//
//  Date:           1-28-19
//
//  Compiled with C++ 11
//
//****************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "Household.h"
#include "Ward.h"
using namespace std;

int main() {
  Household test;
  Ward tast;
  cout << "Enter name, address, number of occupants, and income." << endl;
  cin >> test;
  cout << test;

  cout << "add" << '\n';
  tast.add(test);
  tast.add(test);
  cout << "display" << '\n';
  tast.display(cout);
  cout << "remove" << '\n';
  tast.remove(test.get_head());
  tast.display(cout);

  return 0;
}
