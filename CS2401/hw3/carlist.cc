//****************************************************************
//
//  Class:   Carlist
//
//  Purpose: Implementation file for the carlist class.
//
//
//****************************************************************
#include "carlist.h"

Carlist::Carlist() {
  head = NULL;
}

Carlist::Carlist(Carlist other) {
  head = other.head;
  
}

Carlist::~Carlist() {

}
