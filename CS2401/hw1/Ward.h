#ifndef WARD_H
#define WARD_H
#include <iostream>
#include <fstream>
#include "Household.h"

class Ward {
  public:
  static const size_t SIZE = 200;

  // Constructors
  Ward();

  void display(std::ostream& outs);
  void add(Household tmp);
  void remove(std::string name);

  Household find(std::string name);

  void display_richest();
  void display_avg_income();
  void display_avg_people();

  void sort_by_income();
  void sort_by_name();

  void load(std::istream& ins);
  void save(std::ostream& outs);

private:
  Household neighborhood[SIZE];
  size_t used;
};
#endif
