//****************************************************************
//
//  Class:   Ward
//
//  Purpose: A container class for the Household class
//
//  Functions:
//           Constructors
//             Ward()
//           Mutators
//             void display(std::ostream& outs)
//             void add(Household tmp)
//             void remove(std::string name)
//           Accessors
//             void load(std::istream& ins)
//             void save(std::ostream& outs)
//           Helpers
//             Household find(std::string name)
//             void display_richest()
//             void display_avg_income()
//             void display_avg_people()
//             void sort_by_income()
//             void sort_by_name()
//
//****************************************************************

#include <iostream>
#include <fstream>
#include "Household.h"
#include "Ward.h"

// Constructor
Ward::Ward() {
  used = 0;
}


// Display all Households in the Ward's array
void Ward::display(std::ostream& outs) {
  for (size_t i = 0; i < used; i++) {
    outs << neighborhood[i] << "\n";
  }
}

// Add a Household to the array
void Ward::add(Household tmp) {
  neighborhood[used] = tmp;
  used ++;
}

// Remove a Household from the array
void Ward::remove(std::string name) {
  for (size_t i = 0; i < used; i++) {
    if (neighborhood[i].get_head() == name) {
      neighborhood[i] = neighborhood[used-1];
      used --;
      return;
    }
    else {
      std::cout << "Household not found." << "\n";
      return;
    }
  }
}


// Find a Household using a given name
Household Ward::find(std::string name) {
  size_t found;
  for (size_t i = 0; i < used; i++) {
    if (neighborhood[i].get_head() == name) {
      found = i;
    }
  }
  return neighborhood[found];
}


// Display the Household with the highest income
void Ward::display_richest() {
  int largestIncome = 0;
  size_t richest = 0;
  for (size_t i = 0; i < used; i++) {
    if (neighborhood[i].get_income() > largestIncome) {
      richest = i;
    }
  }
  std::cout << neighborhood[richest];
}

// Display the average income of all Households
void Ward::display_avg_income() {
  double totalIncome;
  for (size_t i = 0; i < used; i++) {
    totalIncome += neighborhood[i].get_income();
  }
  std::cout << (totalIncome / used) << '\n';
}

// Display the average occupancy of all Households
void Ward::display_avg_people() {
  double totalPeople;
  for (size_t i = 0; i < used; i++) {
    totalPeople += neighborhood[i].get_occupants();
  }
  std::cout << (totalPeople / used) << '\n';
}


// Sort the array by each Household's income
void Ward::sort_by_income() {
  bool done = false;
  Household tmp;

  while (!done) {
    done = true;
    for (size_t i = 0; i < (used - 1); i++) {
      if (neighborhood[i].get_income() > neighborhood[i+1].get_income()) {
        done = false;
        tmp = neighborhood[i];
        neighborhood[i] = neighborhood[i+1];
        neighborhood[i+1] = tmp;
      }
    }
  }
}

// Sort the array by each Household's house_head name
void Ward::sort_by_name() {
  bool done = false;
  Household tmp;

  while (!done) {
    done = true;
    for (size_t i = 0; i < (used - 1); i++) {
      if (neighborhood[i].get_head() > neighborhood[i+1].get_head()) {
        done = false;
        tmp = neighborhood[i];
        neighborhood[i] = neighborhood[i+1];
        neighborhood[i+1] = tmp;
      }
    }
  }
}


// Load the Ward array using an instream of Households
void Ward::load(std::istream& ins) {
  size_t i = 0;
  Household temp;

  ins >> temp;
  while(!ins.eof()) {
    neighborhood[i] = temp;
    used ++;
    i++;
    ins >> temp;
  }
}

// Save the Ward to a given ostream
void Ward::save(std::ostream& outs) {
  for (size_t i = 0; i < used; i++) {
    outs << neighborhood[i];
  }
}
