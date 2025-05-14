#include "binaryTree.h"
#include <limits.h>

struct Node *root = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void addNode(struct Node *newNode, struct Node *root)
{
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    if (newNode->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = newNode;
        }
        else
        {
            addNode(newNode, root->left);
        }
    }
}