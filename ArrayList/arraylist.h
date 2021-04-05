#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList {
  int* list;
  int size;
  int capacity;
} ArrayList;

// Allocation and deallocation functions
ArrayList* allocList(int capacity);
void freeList(ArrayList* arrlist);

// 
void add(ArrayList* arrlist, int i);
int get(ArrayList* arrlist, int index);

// TODO: Add more functions

#endif  // ARRAYLIST_H
