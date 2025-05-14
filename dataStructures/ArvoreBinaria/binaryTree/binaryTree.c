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

struct Node *addNode(struct Node *newNode, struct Node *root)
{
    if (root == NULL)
    {
        return newNode;
    }

    if (newNode->data < root->data)
    {
        root->left = addNode(newNode, root->left);
    }
    else
    {
        root->right = addNode(newNode, root->right);
    }

    return root;
}

struct Node *searchNode(int value, struct Node *root)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return searchNode(value, root->left);
    }

    return searchNode(value, root->right);
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *findMin(struct Node *root)
{
    struct Node *currentlyNode = root;

    while (currentlyNode && currentlyNode->left != NULL)
    {
        currentlyNode = currentlyNode->left;
    }

    return currentlyNode;
}

// Fix the comparison in removeNode function
struct Node *removeNode(int value, struct Node *root)
{
    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = removeNode(value, root->left);
    }
    else if (value > root->data) // Fixed comparison operator
    {
        root->right = removeNode(value, root->right);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left; // Fixed: was using root->right incorrectly
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = removeNode(temp->data, root->right);
    }

    return root;
}

int calculateHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isBST(struct Node *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data < min || root->data > max)
    {
        return 0;
    }

    return isBST(root->left, min, root->data - 1) &&
           isBST(root->right, root->data, max);
}

void printTree(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    level += 5;

    printTree(root->right, level);

    printf("\n");
    for (int i = 5; i < level; i++)
    {
        printf("  ");
    }
    printf("%d\n", root->data);

    printTree(root->left, level);
}

void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        // Recursively free left and right subtrees
        freeTree(root->left);
        freeTree(root->right);

        // Free the current node
        free(root);
    }
}
