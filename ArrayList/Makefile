# Makefile for building and testing the data structures
# Created by Aaron Hernandez 08/25/2020
CC = gcc
CFLAGS = -Wall -Werror

make: clean arraylist
	$(CC) -o arraylist arraylist.o

arraylist:
	$(CC) $(CFLAGS) -c arraylist.c

clean:
	rm -f arraylist.o
	rm -f arraylist
