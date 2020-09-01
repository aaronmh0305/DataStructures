#ifndef BST_H
#define BST_H

// Binary Search Tree Node
typedef struct BSTNode {
  int value;
  struct BSTNode* left;
  struct BSTNode* right;
} BSTNode;

BSTNode* search(BSTNode* root, const int value);      // search function
BSTNode* insertNode(BSTNode* root, const int value);  // insert function
BSTNode* removeNode(BSTNode* root, const int value);  // remove function
void clearBST(BSTNode* root);                         // frees resources
int traverseInOrder(BSTNode* root);                   // in-order BST traversal

#endif  // BST_H
