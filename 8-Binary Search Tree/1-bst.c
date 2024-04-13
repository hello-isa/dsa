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
    False,
    True
} Boolean;

// Function prototype
void preorder(BST T);              // Traverse the tree in preorder manner
void postorder(BST T);             // Traverse the tree in postorder manner
void inorder(BST T);               // Traverse the tree in inorder manner
void initialize(BST *T);           // Initialize an empty tree
Boolean isMember(BST T, int elem); // Check if an element is a member of the tree
BST createNode(int elem);          // Create node
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

    printf("Preorder Traversal:\n");
    preorder(root);

    printf("\n\nPostorder Traversal:\n");
    postorder(root);

    printf("\n\nInorder Traversal:\n");
    inorder(root);

    printf("\n\nInsert 71:\n");
    insert(&root, 71);

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

void postorder(BST T)
{
    if (T != NULL)
    {
        postorder(T->LC);
        postorder(T->RC);
        printf("%d ", T->data);
    }
}

void inorder(BST T)
{
    if (T != NULL)
    {
        inorder(T->LC);
        printf("%d ", T->data);
        inorder(T->RC);
    }
}

void initialize(BST *T)
{
    *T = NULL;
}

Boolean isMember(BST T, int elem)
{
    BST trav = T;
    Boolean found = False;

    // Traverse the tree until we reach a leaf node or find the element
    while (trav != NULL && !found)
    {
        if (elem == trav->data)
        {
            found = True; // Set found to True if element is found
        }
        else if (elem < trav->data)
        {
            trav = trav->LC; // Move to the left child
        }
        else
        {
            trav = trav->RC; // Move to the right child
        }
    }

    return found; // Return whether the element is found or not
}

BST createNode(int elem)
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
    }

    return newNode;
}

void insert(BST *T, int elem)
{
    // Scenario 1: Tree is empty
    if (*T == NULL)
    {
        // Create node
        BST newNode = createNode(elem);
        *T = newNode;
    }
    else
    {
        // Scenario 2: Tree is NOT empty

        // Check first if element is a member OR not
        if (isMember(*T, elem) == False)
        {
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

            // Create node
            BST newNode = createNode(elem);

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
        else
        {
            printf("Element exists in the tree. Insertion not allowed.\n");
        }
    }
}
