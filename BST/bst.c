#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/**
 * Iterative Binary Search algorithm for a Binary Search Tree, starting at
 * the root BSTNode given. If the value is found within the BST, then a
 * pointer to that BSTNode with that value is returned. If the value is not 
 * found within the BST, then NULL is simply returned.
 */
BSTNode* search(BSTNode* root, const int value) {

  BSTNode* curr = root;
  while (curr != NULL && curr->value != value) {
    curr = ((value > curr->value) ? curr->right : curr->left);
  }

  return curr;
}

/**
 * Iterative Insert algorithm for a Binary Search Tree, starting at
 * the root BSTNode given. 
 *
 * If a duplicate node with the value given is found, the new node is 
 * not inserted and NULL is returned. 
 *
 * Otherwise, a new node with the given value is directly inserted into 
 * the BST and the parent node of the new node is returned.
 */
BSTNode* insert(BSTNode* root, const int value) {

  BSTNode* parent = NULL;
  BSTNode* curr = root;
  while (curr != NULL) {

    if (value == curr->value) {
      fprintf(stderr, "Insert Failed: Duplicate BSTNode with value %d\n", value);
      return NULL;
    }

    parent = curr;
    curr = ((value > curr->value) ? curr->right : curr->left);
  }

  curr = (BSTNode*) calloc(1, sizeof(BSTNode));
  curr->value = value;
  
  if (parent == NULL) {
    parent = curr;
  } else if (value > parent->value) {
    parent->right = curr;
  } else {
    parent->left = curr;
  }

  return parent;
}

/**
 * Iterative In-Order Traversal for a Binary Search Tree, printing the 
 * nodes in ascending order. This function returns the size of the overall 
 * Binary Search Tree, which is the current number of nodes within the tree
 */
int traverseInOrder(BSTNode* root) {
 // TODO
}

int main() {
  printf("Hello, World!\n");

  BSTNode* root = (BSTNode*) calloc(1, sizeof(BSTNode));
  printf("%d, %s, %s\n", root->value, !root->left ? "NULL" : "NOT NULL", !root->right ? "NULL" : "NOT NULL");
  root->value = 5;
  root->left = (BSTNode*) calloc(1, sizeof(BSTNode));
  root->left->value = 3;

  printf("%s\n", search(root, 5) ? "Root Found" : "Root Not Found");
  printf("%s\n", search(root, 3) ? "3 Found" : "3 Not Found");

  free(root->left);
  free(root);
  return 0;
}
