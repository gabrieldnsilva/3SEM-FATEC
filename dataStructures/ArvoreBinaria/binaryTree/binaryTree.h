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
/**
 * Creates a new node with the given data.
 * @param data The data to be stored in the node.
 * @return A pointer to the newly created node.
 */
struct Node *createNode(int data);

/**
 * Adds a new node to the binary search tree.
 * @param newNode The node to be added.
 * @param root The root of the tree or subtree where the node will be inserted.
 * @return A pointer to the new root after insertion.
 */
struct Node *addNode(struct Node *newNode, struct Node *root);

/**
 * Searches for a node with the given value in the binary search tree.
 * @param value The value to search for.
 * @param root The root of the tree or subtree to search in.
 * @return A pointer to the found node, or NULL if not found.
 */
struct Node *searchNode(int value, struct Node *root);

/**
 * Traverses the tree in pre-order (root, left, right).
 * @param root The root of the tree or subtree to traverse.
 */
void preOrder(struct Node *root);

/**
 * Traverses the tree in in-order (left, root, right).
 * @param root The root of the tree or subtree to traverse.
 */
void inOrder(struct Node *root);

/**
 * Traverses the tree in post-order (left, right, root).
 * @param root The root of the tree or subtree to traverse.
 */
void postOrder(struct Node *root);

/**
 * Finds the minimum value node in the tree.
 * @param root The root of the tree or subtree to search in.
 * @return A pointer to the node with the minimum value.
 */
struct Node *findMin(struct Node *root);

/**
 * Removes a node with the given value from the binary search tree.
 * @param value The value of the node to be removed.
 * @param root The root of the tree or subtree where the node will be removed.
 * @return A pointer to the new root after removal.
 */
struct Node *removeNode(int value, struct Node *root);

/**
 * Frees the memory allocated for the tree.
 * @param root The root of the tree or subtree to be freed.
 */
void freeTree(struct Node *root);

// Additional functions for tree analysis

/**
 * Calculates the height of the tree.
 * @param root The root of the tree or subtree.
 * @return The height of the tree (0 for an empty tree).
 */
int calculateHeight(struct Node *root);

/**
 * Counts the number of nodes in the tree.
 * @param root The root of the tree or subtree.
 * @return The total number of nodes.
 */
int countNodes(struct Node *root);

/**
 * Checks if the tree is a valid binary search tree (BST).
 * @param root The root of the tree or subtree.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return 1 if it is a BST, 0 otherwise.
 */
int isBST(struct Node *root, int min, int max);

/**
 * Prints the tree in a visual format.
 * @param root The root of the tree or subtree to be printed.
 * @param level The current level of the node (for indentation).
 */
void printTree(struct Node *root, int level);

#endif // BINARYTREE_H