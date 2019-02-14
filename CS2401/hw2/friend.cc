//****************************************************************
//  Class:   Friend
//
//  Purpose: implementation file for the Friend class.
//
//****************************************************************
#include "friend.h"

Friend::Friend() {
  name = "";
  bday;
}

std::string Friend::get_name()const {
  return name;
}

Date Friend::get_bday()const {
  return bday;
}

bool Friend::operator == (const Friend& other)const {
  return (name == other.name && bday == other.bday);
}

bool Friend::operator != (const Friend& other)const {
  return (!(name == other.name && bday == other.bday));
  // if (name != other.name && d != other.d) {
  //   return true;
  // }
  // return false;
}

void Friend::input(std::istream& ins) {
  while (ins.peek() == '\n')
  {ins.ignore();}
  getline(ins, name);
  ins >> bday;
}

void Friend::output(std::ostream& outs)const {
  outs << name << '\n';
  outs << bday << '\n';
}

std::istream& operator >>(std::istream& ins, Friend& f) {
  f.input(ins);
  return ins;
}

std::ostream& operator <<(std::ostream& outs, const Friend& f) {
  f.output(outs);
  return outs;
}
