#Makefile for the book project
CFLAGS = -Wall -std=c++11
CC = g++

#Linking all the files
#Create the executable program "book-main"
book-main: book-main.o Book.o
	$(CC) $(CFLAGS) Book.o book-main.o -o book-main

Book.o: Book.cc Book.h
	$(CC) -c $(CFLAGS) Book.cc

book-main.o: book-main.cc Book.h
	$(CC) -c $(CFLAGS) book-main.cc

#Remove all the object and executable files
clean:
	rm -f book-main.o Book.o book-main
