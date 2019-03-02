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

Carlist::Carlist(const Carlist& other) {
  head = other.head;

}

Carlist::~Carlist() {

}

void Carlist::add(Car c) {
  node *current;
  node *previous;
  if (head == NULL) {head = new node(c, NULL); return;}
  else if (c < head) {
    node *tmp =
  }
}
