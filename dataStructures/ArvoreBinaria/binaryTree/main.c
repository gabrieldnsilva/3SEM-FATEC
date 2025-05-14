#include <stdio.h>
#include <limits.h>
#include "binaryTree.h"

enum
{
    OP_NOT_SELECTED = 0,
    OP_ADD,
    OP_SEARCH,
    OP_REMOVE,
    OP_PRE_ORDER,
    OP_IN_ORDER,
    OP_POST_ORDER,
    OP_PRINT_TREE,
    OP_TREE_HEIGHT,
    OP_COUNT_NODES,
    OP_CHECK_BST,
    OP_EXIT
};

int menu();
void pause();

int main(void)
{
    int option = OP_NOT_SELECTED;
    int number;

    struct Node *result;

    printf("=== BINARY SEARCH TREE - DEMONSTRATION ===\n\n");
    printf("Welcome to the binary tree demonstration program!\n");
    printf("This program allows you to create and manipulate a binary search tree.\n\n");

    while (option != OP_EXIT)
    {
        option = menu();
        switch (option)
        {
        case OP_ADD:
            printf("\n == ADD NODE ==\n");
            printf("Enter a number: "); // Fixed typo in prompt
            scanf("%d", &number);
            root = addNode(createNode(number), root);
            printf("Number %d added successfully!\n", number);
            pause();
            break;

        case OP_SEARCH:
            printf("\n == SEARCH VALUE ==\n");
            printf("Enter the value to search: ");
            scanf("%d", &number);
            result = searchNode(number, root);
            if (result != NULL)
            {
                printf("Value %d found in the tree!\n", number);
            }
            else
            {
                printf("Value %d not found in the tree.\n", number);
            }
            pause();
            break;

        case OP_REMOVE:
            printf("\n == REMOVE NODE ==\n");
            printf("Enter the number to remove: ");
            scanf("%d", &number);
            root = removeNode(number, root);
            printf("Removal operation completed.\n");
            pause();
            break;

        case OP_PRE_ORDER:
            printf("\n == PRE-ORDER TRAVERSAL ==\n");
            printf("Visiting: Root -> Left -> Right\n");
            printf("Result: ");
            if (root != NULL)
            {
                preOrder(root);
                printf("\n");
            }
            else
            {
                printf("Tree is empty.\n");
            }
            pause();
            break;

        case OP_IN_ORDER:
            printf("\n == IN-ORDER TRAVERSAL ==\n");
            printf("Visiting: Left -> Root -> Right\n");
            printf("Result (sorted in BST): ");
            if (root != NULL)
            {
                inOrder(root);
                printf("\n");
            }
            else
            {
                printf("Tree is empty.\n");
            }
            pause();
            break;

        case OP_POST_ORDER:
            printf("\n == POST-ORDER TRAVERSAL ==\n");
            printf("Visiting: Left -> Right -> Root\n");
            printf("Result: ");
            if (root != NULL)
            {
                postOrder(root);
                printf("\n");
            }
            else
            {
                printf("Tree is empty.\n");
            }
            pause();
            break;

        case OP_PRINT_TREE:
            printf("\n == PRINT TREE ==\n");
            printf("Tree structure:\n");
            if (root != NULL)
            {
                printTree(root, 0);
                printf("\n");
            }
            else
            {
                printf("Tree is empty.\n");
            }
            pause();
            break;

        case OP_TREE_HEIGHT:
            printf("\n == TREE HEIGHT ==\n");
            if (root != NULL)
            {
                printf("The height of the tree is: %d\n", calculateHeight(root));
                printf("(A tree with only root has height 1)\n");
            }
            else
            {
                printf("Empty tree (height 0).\n");
            }
            pause();
            break;

        case OP_COUNT_NODES:
            printf("\n == COUNT NODES ==\n");
            printf("Total nodes in the tree: %d\n", countNodes(root));
            pause();
            break;

        case OP_CHECK_BST:
            printf("\n == CHECK BST ==\n");
            if (root == NULL)
            {
                printf("Empty tree is considered a valid BST.\n");
            }
            else if (isBST(root, INT_MIN, INT_MAX))
            {
                printf("The tree is a valid BST!\n");
            }
            else
            {
                printf("The tree is NOT a valid BST.\n");
            }
            pause();
            break;

        case OP_EXIT:
            printf("\nExiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            pause();
            break;
        }
    }

    // Free the memory allocated for the tree
    freeTree(root);
    printf("Memory freed. Exiting the program.\n");
    return 0;
}

int menu()
{
    int option;

    printf("\n=== MENU ===\n");
    printf("[%d]. Add Node\n", OP_ADD);
    printf("[%d]. Search Value\n", OP_SEARCH);
    printf("[%d]. Remove Node\n", OP_REMOVE);
    printf("[%d]. Pre-Order Traversal\n", OP_PRE_ORDER);
    printf("[%d]. In-Order Traversal\n", OP_IN_ORDER);
    printf("[%d]. Post-Order Traversal\n", OP_POST_ORDER);
    printf("[%d]. Print Tree\n", OP_PRINT_TREE);
    printf("[%d]. Tree Height\n", OP_TREE_HEIGHT);
    printf("[%d]. Count Nodes\n", OP_COUNT_NODES);
    printf("[%d]. Check BST\n", OP_CHECK_BST);
    printf("[%d]. Exit\n", OP_EXIT);
    printf("Select an option: ");
    scanf("%d", &option);

    return option;
}
void pause()
{
    printf("Press Enter to continue...");
    while (getchar() != '\n')
        ;
    getchar();
}