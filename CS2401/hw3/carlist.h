//****************************************************************
//
//  Class:   Carlist
//
//  Purpose: Container class for a linked list of cars.
//
//****************************************************************
#include "car.h"
#include "node.h"

#ifndef CARLIST_H
#define CARLIST_H

class Carlist {

public:
  Carlist();
  Carlist(const Carlist other);
  void operator =(const Carlist& other);
  ~Carlist();
  void add(Car c); // 1
  void showall(std::ostream& outs)const; // 2
  void view_all_of_year(int target)const; // 3
  void view_all_of_make(std::string target)const; // 4
  Car cheapest()const; // 5
  double tax_value()const; // 6
  // 7 is manipulating a copied list
  double miles_per_year()const; // 8
  void remove(Car c); // 9

  void load(std::ifstream& ins);
  void save(std::ofstream& outs);

private:
  node *head;
};
#endif
