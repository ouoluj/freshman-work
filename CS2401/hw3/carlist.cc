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

// void Carlist::operator =(const Carlist& other) {
//   if (this == &other) {return;}
//   node *sptr = other.head; // source pointer
//   node *dptr = head; // destination pointer
//   head = new node(sptr.head.data(), NULL);
//   sptr = sptr.link();
//   while (sptr.link() != NULL) {
//     dptr= new node(sptr.data(), NULL);
//
//   }
// }

Carlist::~Carlist() {
  node *del = head;
  node *current = head.link();
  while (current != NULL) {
    head = current;
    delete del;
    del = current;
    current = current.link();
  }
}

void Carlist::add(Car c) {
  node *previous = head;
  node *current = head.link();
  if (head == NULL) {head = new node(c, NULL);}
  else {
    if (c < head) {
      node *tmp = new node(c, head);
      head = tmp;
    }
    else {
      while (current != NULL) {
        if (c > current.data()) {
          previous.set_link(new node(c, current));
        }
        previous = previous.link();
        current = current.link();
      }
    }
  }
}
