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
  if(other.head == NULL) {head = NULL;}
  else {
    node *sptr = other.head;
    node *dptr = head;
    head = new node(other.head.data(), NULL);

    sptr = sptr.link();
    while (sptr != NULL) {
      dptr.set_link(new node(sptr.data(), NULL));
      dptr = dptr.link();
      sptr = sptr.link();
    }
  }
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

void Carlist::showall(std::ostream& outs)const {
  node *cursor = head;
  while (cursor != NULL) {
    cout << cursor << endl;
    cursor = cursor.link();
  }
}

void Carlist::view_all_of_year(int target)const {
  node *cursor = head;
  while (cursor != NULL) {
    if (cursor.data().get_year() == target) {
      cout << cursor << endl;
    }
    cursor = cursor.link();
  }
}

void Carlist::view_all_of_make(std::string target)const {
  node *cursor = head;
  while (cursor != NULL) {
    if (cursor.data().get_make() == target) {
      cout << cursor << endl;
    }
    cursor = cursor.link();
  }
}

Car Carlist::cheapest()const {
  node *cursor = head;
  Car cheapest = head.data();

  while (cursor != NULL) {
    if (cursor.data().get_price() < cheapest.get_price()) {
      cheapest = cursor.data();
    }
    cursor = cursor.link();
  }
}

double Carlist::tax_value()const {
  double total = 0, num = 0, value = 0;
  node *cursor = head;

  while (cursor != NULL) {
    total += cursor.data().get_price();
    num ++;
    cursor = cursor.link();
  }
  value = total/num;
  return value;
}

void Carlist::remove(Car c) {
  node *cursor = head;
  if (head.data() == c) {
    head = head.link();
    delete cursor;
  }

  else {
    node *previous = head;
    cursor = head.link();
    while (cursor != NULL) { // Cursor is already initialized to head's link, which, if null, will not enter loop
      if (cursor.data() == c) {
        previous.set_link(cursor.link());
        delete cursor;
      }
      previous = previous.link();
      cursor = cursor.link();
    }
  }
}
