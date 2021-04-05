#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arraylist.h"

/**
* Allocates memory for an ArrayList of a specified capacity
*/
ArrayList* allocList(int capacity) {

  if (capacity <= 0) {
    fprintf(stderr, "Error: ArrayList cannot be created with a capacity <= 0\n");
    return NULL;
  }

  ArrayList* arrlist = (ArrayList*) malloc(sizeof(ArrayList));
  if (arrlist == NULL) {
    fprintf(stderr, "Out of Memory Error\n");
    exit(-1);
  }

  arrlist->list = (int*) malloc(sizeof(int) * capacity);
  if (arrlist->list == NULL) {
    fprintf(stderr, "Out of Memory Error\n");
    exit(-1);
  }
  
  arrlist->size = 0;
  arrlist->capacity = capacity;

  return arrlist;
}

/**
* Helper Function for growing or shrinking the arraylist to a new size in bytes
*/
static void resizeList(ArrayList* arrlist, int newSizeBytes) {
  arrlist->list = (int*) realloc(arrlist->list, newSizeBytes);
  if (arrlist->list == NULL) {
    fprintf(stderr, "Out of Memory Error\n");
    exit(-1);
  }
}

/**
* Frees up the dynamic memory of the arraylist
*/
void freeList(ArrayList* arrlist) {
  free(arrlist->list);
  free(arrlist);
}

/**
* Adds a single integer to the arraylist  
*/
void add(ArrayList* arrlist, int i) {

  if (arrlist == NULL) {
    fprintf(stderr, "add() Error: arraylist is null. allocList must be called before adding items\n");
    return;
  }

  // if full capacity is reached, then double the capacity 
  if (arrlist->size == arrlist->capacity) {
    int newCapacity = (arrlist->capacity << 1);
    resizeList(arrlist, sizeof(int) * newCapacity);
    arrlist->capacity = newCapacity;
  }
 
  arrlist->list[arrlist->size] = i;
  (arrlist->size)++;
}

/**
* Gets the integer at the specified index of the arraylist given that it is not out of bounds
*/
int get(ArrayList* arrlist, int index) {

  if (arrlist == NULL) {
    fprintf(stderr, "get() Error: arraylist is null.\n");
    return INT_MIN;
  } 
  
  if (index < 0 || index >= arrlist->size) {
    fprintf(stderr, "get() Error: ArrayList index i=%d out of bounds for size of %d\n", index, arrlist->size);
    return INT_MIN;
  }

  return arrlist->list[index];
}




// TESTING FUNCTIONALITY
int main(int argc, char* argv[]) {

  printf("Allocating new ArrayList of capacity 5\n");
  ArrayList* testList = allocList(5); // allocates a list with a capacity of 5
  printf("Test List size: %d\n", testList->size);
  printf("Test List capacity: %d\n\n", testList->capacity);

  // testing get on an empty list. 
  printf("get(0) on empty list. Should be get() error with INT_MIN returned\n");
  int value = get(testList, 0);
  printf(value == INT_MIN ? "Success!\n" : "Failure!\n");

  // testing adds and how it updates the size of the arraylist
  printf("Adding a single item 2 to the list\n");
  add(testList, 2);
  printf("Test List size: %d\n\n", testList->size);

  // testing get() on single item list
  printf("Calling get() on a single item list\n");
  value = get(testList, 0);
  printf(value == 2 ? "get(0) = 2 as expected, Success!\n\n" : "get(0) != 2, Failure\n\n");

  // multiple adds
  printf("Adding 3, 4, 5, and 6 to the list\n");
  add(testList, 3);
  add(testList, 4);
  add(testList, 5);
  add(testList, 6);
  printf("Test List size: %d\n", testList->size);
  printf("Test List capacity: %d\n\n", testList->capacity);

  printf("Adding 7 to the list, capacity should == 10 now\n");
  add(testList, 7);
  printf("Test List size: %d\n", testList->size);
  printf("Test List capacity: %d\n\n", testList->capacity);

  // testing get
  printf("get(0) = %d. Should be 2\n", get(testList, 0));
  printf("get(1) = %d. Should be 3\n", get(testList, 1));
  printf("get(2) = %d. Should be 4\n", get(testList, 2));
  printf("get(3) = %d. Should be 5\n", get(testList, 3));
  printf("get(4) = %d. Should be 6\n", get(testList, 4));
  printf("get(5) = %d. Should be 7\n", get(testList, 5));

  // free resources and defensive coding 
  freeList(testList);
  testList = NULL;

  return 0;
}
