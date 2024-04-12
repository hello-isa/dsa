#include <stdio.h>
#include <stdlib.h>

// Datatype definition
typedef struct node
{
    int parent;
    struct node *LC, *RC;
} *BST;

void displayPreorder(BST T);
void insert(BST *T, int elem); // PPN

int main()
{
    BST A = NULL;

    insert(&A, 6);

    printf("Display in Preorder: \n");
    displayPreorder(A);

    return 0;
}

void displayPreorder(BST T)
{
    if (T != NULL)
    {
        printf("%d ", T->parent);
        displayPreorder(T->LC);
        displayPreorder(T->RC);
    }
}

void insert(BST *T, int elem)
{
    BST newNode = (BST)calloc(1, sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->parent = elem;
    }

    // Scenario 1: Tree is EMPTY
    if (*T == NULL)
    {
        *T = newNode;
    }
}