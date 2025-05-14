#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

extern struct Node *root;

// Function prototypes
struct Node *createNode(int data);
void addNode(struct Node *newNode, struct Node *root);
struct Node *searchNode(int value, struct Node *root);
void preOrder(struct Node *root);
void inOrder(struct Node *root);
void postOrder(struct Node *root);
struct Node *findMin(struct Node *root);
struct Node *removeNode(int value, struct Node *root);
void freeTree(struct Node *root);

// Additional functions for tree analysis
int calculateHeight(struct Node *root);
int countNodes(struct Node *root);
int isBST(struct Node *root, int min, int max);
void printTree(struct Node *root, int level);

#endif // BINARYTREE_H