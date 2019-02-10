#Makefile for the household project
CFLAGS = -Wall -std=c++11
CC = g++

#Linking all the files
# Create the exectutable program "main"
main: fbfriends.o friend.o date.o
	$(CC) -g $(CFLAGS) fbfriends.o friend.o date.o main.cc -o main

# Create the executable program "driver"
driver: fbfriends.o friend.o date.o driver.o
	$(CC) -g $(CFLAGS) fbfriends.o friend.o date.o driver.o -o driver

#Create object file for class "fbfriends"
fbfriends.o: fbfriends.cc fbfriends.h friend.h
	$(CC) -c $(CFLAGS) fbfriends.cc

#Create object file for class "friend"
friend.o: friend.cc friend.h
	$(CC) -c $(CFLAGS) friend.cc

#Create object file for class "date"
date.o: date.cc date.h
	$(CC) -c $(CFLAGS) date.cc

driver.o: driver.cc fbfriends.h friend.h date.h
	$(CC) -c $(CFLAGS) driver.cc

#Remove all the object and executable files
clean:
	rm -f *.o driver main
