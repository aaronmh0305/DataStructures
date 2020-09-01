#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct QueueBSTNode {
  struct BSTNode* node;
  struct QueueBSTNode* next;
} QueueBSTNode;

/**
 * Helper function for creating a new queue node 
 */
QueueBSTNode* createQueueNode(BSTNode* bstNode) {

  QueueBSTNode* newNode = (QueueBSTNode*) malloc(sizeof(QueueBSTNode));
  newNode->node = bstNode;
  newNode->next = NULL;

  return newNode;
}

/**
 * Iterative Binary Search algorithm for a Binary Search Tree, starting at
 * the root BSTNode given. If the value is found within the BST, then a
 * pointer to that BSTNode with that value is returned. If the value is not 
 * found within the BST, then NULL is simply returned.
 */
BSTNode* searchBST(BSTNode* root, const int value) {

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
BSTNode* insertNode(BSTNode* root, const int value) {

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
 * Iteratively removes and frees all the memory of the nodes in a BST based 
 * on the root given. This uses a Level-Order Traversal (or Breadth-First Search)
 * to achieve this task iteratively.
 */
void clearBST(BSTNode* root) {

  QueueBSTNode *front, *rear;
  front = createQueueNode(root);
  rear = front;

  while (front != NULL) {
  
    if (front->node->left != NULL) {
      rear->next = createQueueNode(front->node->left);
      rear = rear->next;
    }

    if (front->node->right != NULL) {
      rear->next = createQueueNode(front->node->right);
      rear = rear->next;
    }

    QueueBSTNode* nextQueueNode = front->next;    
    free(front->node);
    free(front);
    front = nextQueueNode;

  }

}

/**
 * Iterative In-Order Traversal for a Binary Search Tree, printing the 
 * nodes in ascending order. This function returns the size of the overall 
 * Binary Search Tree, which is the current number of nodes within the tree
 */
int traverseInOrder(BSTNode* root) {
  
  BSTNode* curr = root;
  BSTNode* pred = NULL;
  int count = 0;

  while (curr != NULL) {

    if (curr->left == NULL) {
      printf("%d, ", curr->value);
      count++;
      curr = curr->right;
    } else {

      // find in-order predecessor      
      pred = curr->left;
      while (pred->right != NULL && pred->right != curr) {
        pred = pred->right;
      }

      if (pred->right == NULL) {
        pred->right = curr;
        curr = curr->left;
      } else {
        pred->right = NULL;
        printf("%d, ", curr->value);
        count++;
        curr = curr->right;
      }
    }
  }

  printf("\n");
  return count;
}


// TODO: ABSTRACT INTO UNIT TESTS LATER
// TEST FUNCTIONALITY
void testInsert() {
  BSTNode* root = insertNode(NULL, 10);
  printf("%s\n", root != NULL ? "Root NOT NULL" : "Root = NULL");
  printf("%d\n", root != NULL ? root->value : -1);
  printf("root->left = %s\n", root->left != NULL ? "NOT NULL" : "NULL");
  printf("root->right = %s\n", root->right != NULL ? "NOT NULL" : "NULL");

  printf("\nInserting 5 into tree!\n");
  insertNode(root, 5);
 
  printf("root = %d\n", root->value); 
  printf("root->left = %d\n", root->left->value);  
  printf("root->right = %s\n", root->right != NULL ? "NOT NULL" : "NULL");

  printf("\nInserting 14 into tree!\n");
  insertNode(root, 14);
  printf("root->right = %d\n", root->right->value);

  int size = traverseInOrder(root);
  printf("COUNT: %d\n", size);

  clearBST(root);
  root = NULL;
}

int main() {

  testInsert();
  return 0;
}
