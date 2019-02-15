//****************************************************************
//
//  Class:   FBFriends
//
//  Purpose: .
//
//
//****************************************************************
#include <algorithm>
#include "fbfriends.h"

FBFriends::FBFriends() {
  data = new Friend[capacity];
  capacity = 5;
  used = 0;
  current_index = 0;
}

// Big 3
FBFriends::~FBFriends() {
  delete []data;
  std::cout << "Goodbyyyee" << '\n';
}

FBFriends::FBFriends(const FBFriends& other) {
  used = other.used;
  capacity = other.capacity;
  data = new Friend data[capacity];
  copy(other.data, other.data + used, data);
}

void FBFriends::operator = (const FBFriends& other) {
  if (!(this == &other)) {
    delete []data;
    capacity = other.capacity;
    data = new Friend data[capacity];
    copy(other.data, other.data + used, data);
  }
}

// Functions for internal iterator
void FBFriends::start()

void FBFriends::advance()

bool FBFriends::is_item()

Friend FBFriends::current()

void FBFriends::remove_current()

void FBFriends::insert(const Friend& f)

void FBFriends::attach(const Friend& f)

void FBFriends::show_all(std::ostream& outs)const

void FBFriends::bday_sort()

Friend FBFriends::find_friend(const std::string& name)const

bool FBFriends::is_friend(const Friend& f) const

void FBFriends::load(std::istream& ins)

void FBFriends::save(std::ostream& out)



void FBFriends::resize() {
  Friend *tmp;
  tmp = new Friend[capacity + 5];
  for (size_t i = 0; i < used; i++)
    {tmp[i] = data[i];}
  delete []data;
  data = tmp;
  capacity += 5;
} // increases the capacity of the container by 5
