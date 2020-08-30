#ifndef BST_H
#define BST_H

// Binary Search Tree Node
typedef struct BSTNode {
  int value;
  struct BSTNode* left;
  struct BSTNode* right;
} BSTNode;

BSTNode* search(BSTNode* root, const int value);  // search function
BSTNode* insert(BSTNode* root, const int value);  // insert function
int traverseInOrder(BSTNode* root);               // in-order BST traversal

#endif  // BST_H
