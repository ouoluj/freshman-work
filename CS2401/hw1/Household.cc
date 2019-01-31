//****************************************************************
//
//  Class:   Household
//
//  Purpose: Create an object representing a single household, using
//            the head of household, address, number of occupants, and income.
//
//  Functions:
//           Constructors
//             Household()
//           Setters
//             void set_head(const std::string& hd)
//             void set_address(const std::string& add)
//             void set_occupants(int num)
//             void set_income(int inc)
//           Getters
//             std::string get_head()const
//             std::string get_address()const
//             int get_occupants()const
//             int get_income()const
//           Helpers
//             void input(std::istream& ins)
//             void output(std::ostream& outs)const
//
//           Overloaded operators
//             std::istream& operator >>(std::istream& ins, Household& h)
//             std::ostream& operator <<(std::ostream& outs, const Household& h)
//
//****************************************************************
  #include "Household.h"
  #include <iostream>
  #include <string>
  #include <fstream>

// Constructor
Household::Household() {
  house_head = "***";
  address = "***";
  occupants = 0;
  income = 0;
}

// Mutators
void Household::set_head(const std::string& hd) {
  house_head = hd;
}

void Household::set_address(const std::string& add) {
  address = add;
}

void Household::set_occupants(int num) {
  occupants = num;
}

void Household::set_income(int inc) {
  income = inc;
}

// Accessors
std::string Household::get_head()const {
  return house_head;
}

std::string Household::get_address()const {
  return address;
}

int Household::get_occupants()const {
  return occupants;
}

int Household::get_income() const {
  return income;
}

// Input and output
void Household::input(std::istream& ins) {
  while (ins.peek() == '\n')
  {ins.ignore();}
  getline(ins, house_head);
  getline(ins, address);
  ins >> occupants;
  ins >> income;
}

void Household::output(std::ostream& outs)const{
  outs << house_head << std::endl;
  outs << address << std::endl;
  outs << occupants << std::endl;
  outs << income << std::endl;
}

//overloaded i/o operators
std::istream& operator >>(std::istream& ins, Household& h) {
  h.input(ins);
  return ins;
}

std::ostream& operator <<(std::ostream& outs, const Household& h){
  h.output(outs);
  return outs;
}
