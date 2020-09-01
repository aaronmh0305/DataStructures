# Makefile for building and testing the data structures
# Created by Aaron Hernandez 08/25/2020

CC = gcc
CFLAGS = -Wall -Werror

make: bst
	$(CC) -o bst bst.o

bst:
	$(CC) $(CFLAGS) -c bst.c

clean:
	-rm bst.o
	-rm bst
