#Makefile for the household project
CFLAGS = -Wall -std=c++11
CC = g++

#Linking all the files
# Create the exectutable program "main"
main: Ward.o Household.o
	$(CC) -g $(CFLAGS) Household.o Ward.o main.cc -o main

# Create the executable program "driver"
driver: driver.o Household.o Ward.o
	$(CC) -g $(CFLAGS) Ward.o Household.o driver.o -o driver

#Create object file for class "Ward"
Ward.o: Ward.cc Ward.h Household.h
	$(CC) -c $(CFLAGS) Ward.cc

#Create object file for class "Household"
Household.o: Household.cc Household.h
	$(CC) -c $(CFLAGS) Household.cc

driver.o: driver.cc Household.h Ward.h
	$(CC) -c $(CFLAGS) driver.cc

#Remove all the object and executable files
clean:
	rm -f driver.o Household.o Ward.o driver main
