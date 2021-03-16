# Makefile for building and testing the data structures
# Created by Aaron Hernandez 08/25/2020

CC = gcc
CFLAGS = -Wall -Werror

make: clean bst
	$(CC) -o bst bst.o

bst:
	$(CC) $(CFLAGS) -c bst.c

clean:
	rm -f bst.o
	rm -f bst
