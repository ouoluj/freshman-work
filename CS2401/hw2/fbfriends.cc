//****************************************************************
//
//  Class:   FBFriends
//
//  Purpose: .
//
//
//****************************************************************
#include "fbfriends.h"

FBFriends::FBFriends()

FBFriends::~FBFriends()

FBFriends::FBFriends(const FBFriends& other)

void FBFriends::operator = (const FBFriends& other)

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

void FBFriends::save(std::ostream& out



void FBFriends::resize() // increases the capacity of the container by 5
