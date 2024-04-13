#include <stdio.h>
#include <stdlib.h>

// Datatype definition
typedef struct node
{
    int data;
    struct node *LC, *RC;
} *BST;

typedef enum
{
    F,
    T
} Boolean;

// Function prototype
void preorder(BST T);              // Traverse the tree in preorder manner
void initialize(BST *T);           // Initialize an empty tree
Boolean isMember(BST T, int elem); // Check if an element is a member of the tree
void insert(BST *T, int elem);     // Insert an element into its proper position in the tree
void delete(BST *T, int elem);     // Delete an element from the tree

int main()
{
    BST root;

    initialize(&root);

    insert(&root, 48);
    insert(&root, 57);
    insert(&root, 39);
    insert(&root, 25);
    insert(&root, 50);
    insert(&root, 71);
    insert(&root, 40);

    preorder(root);

    return 0;
}

// Function definitions
void preorder(BST T)
{
    if (T != NULL)
    {
        printf("%d ", T->data);
        preorder(T->LC);
        preorder(T->RC);
    }
}

void initialize(BST *T)
{
    *T = NULL;
}

void insert(BST *T, int elem)
{
    // Create new node
    BST newNode = (BST)calloc(1, sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->data = elem;
    }
    else
    {
        printf("Memory allocation failed.");
        return; // Exit the function if memory allocation fails
    }

    // Scenario 1: Tree is empty
    if (*T == NULL)
    {
        *T = newNode;
        return; // Insertion done, exit the function
    }

    // Scenario 2: Tree is NOT empty
    BST trav = *T;
    BST parent = NULL;

    while (trav != NULL)
    {
        parent = trav; // Update parent pointer
        if (elem <= trav->data)
        {
            trav = trav->LC;
        }
        else
        {
            trav = trav->RC;
        }
    }

    // Now, 'parent' points to the parent of the new node
    if (elem <= parent->data)
    {
        parent->LC = newNode;
    }
    else
    {
        parent->RC = newNode;
    }
}
