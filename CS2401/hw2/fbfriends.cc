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
  data = new Friend[5];
  capacity = 5;
  used = 0;
  current_index = 0;
}

// Big 3
FBFriends::~FBFriends() {
  delete []data;
  // std::cout << "Goodbyyyee" << '\n';
}

FBFriends::FBFriends(const FBFriends& other) {
  used = other.used;
  capacity = other.capacity;
  data = new Friend[capacity];
  std::copy(other.data, other.data + used, data);
}

void FBFriends::operator = (const FBFriends& other) {
  if (!(this == &other)) {
    delete []data;
    capacity = other.capacity;
    data = new Friend[capacity];
    std::copy(other.data, other.data + used, data);
  }
}

// Functions for internal iterator
void FBFriends::start()
  {current_index = 0;}

void FBFriends::advance()
  {current_index ++;}

bool FBFriends::is_item()
  {return (!(current_index >= used));}

Friend FBFriends::current()
  {return data[current_index];}

void FBFriends::remove_current() {
  for (int i = current_index; i < used; i++)
    {data[i] = data[i+1];}
  used --;
}

void FBFriends::insert(const Friend& f) {
  if (used == capacity)
    {resize();}

  for (int i = used; i > current_index; i--)
    {data[i] = data[i-1];}

  data[current_index] = f;
  used ++;
}

void FBFriends::attach(const Friend& f) {
  if (used == capacity)
    {resize();}

  for (int i = used; i > current_index+1; i--)
    {data[i] = data[i-1];}

  data[current_index + 1] = f;
  used ++;
}

void FBFriends::show_all(std::ostream& outs)const {
  for (int i = 0; i < used; i++)
    {outs << data[i] << '\n';}
}

void FBFriends::bday_sort() {
  Friend temp;

  for (int i = 0; i < used; i++) {
    for (int j = i; j < used; j++) {
      if(data[i].get_bday() > data[j].get_bday()) {
        temp = data[i]; //swith the order of the objects in the array
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}

Friend FBFriends::find_friend(const std::string& name)const {
  for (int i = 0; i < used; i++) {
    if (data[i].get_name() == name) {
      return data[i];
    }
  }
  Friend tmp;
  return tmp;
}

bool FBFriends::is_friend(const Friend& f) const {
  for (size_t i = 0; i < used; i++) {
    if (data[i] == f)
      {return true;}
  }
  return false;
}

void FBFriends::load(std::istream& ins) {
  start();
  Friend tmp;

  ins >> tmp;
  while (!ins.eof()) {
    insert(tmp);
    current_index ++;
    ins >> tmp;
  }
  start();
}

void FBFriends::save(std::ostream& outs) {
  for (int i = 0; i < used; i++)
    {outs << data[i];}
}


void FBFriends::resize() {
  Friend *tmp;
  tmp = new Friend[capacity + 5];
  for (int i = 0; i < used; i++)
    {tmp[i] = data[i];}
  delete []data;
  data = tmp;
  capacity += 5;
}
