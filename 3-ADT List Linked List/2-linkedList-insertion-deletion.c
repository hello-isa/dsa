#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char elem;
    struct node *link;
} *LIST;

void displayList(LIST L);

// Insertion
void insertFirst(LIST *L, char X);             // PN
void insertLast(LIST *L, char X);              // PPN
void insertPos(LIST *L, char X, int position); // PPN

// Deletion
void deleteFirst(LIST *L); // PN
void deleteLast(LIST *L);  // PPN
void deletePos(LIST *L, int position);

int main()
{
    LIST LL = NULL;

    printf("Insert first:\n");
    insertFirst(&LL, 'A');
    insertFirst(&LL, 'B');
    insertFirst(&LL, 'C');
    displayList(LL);

    printf("\nInsert last:\n");
    insertLast(&LL, 'Z');
    insertLast(&LL, 'Y');
    insertLast(&LL, 'X');
    displayList(LL);

    printf("\nInsert at position 0:\n");
    insertPos(&LL, 'F', 0);
    displayList(LL);

    printf("\nInsert at position 6:\n");
    insertPos(&LL, 'H', 6);
    displayList(LL);

    printf("\nDelete first:\n");
    deleteFirst(&LL);
    deleteFirst(&LL);
    displayList(LL);

    printf("\nDelete last:\n");
    deleteLast(&LL);
    deleteLast(&LL);
    displayList(LL);

    printf("\nDelete at position 1:\n");
    deletePos(&LL, 1);
    displayList(LL);

    printf("\nDelete at position 2:\n");
    deletePos(&LL, 2);
    displayList(LL);

    printf("\nDelete at position 0:\n");
    deletePos(&LL, 0);
    displayList(LL);

    return 0;
}

void displayList(LIST L)
{
    for (; L != NULL; L = L->link)
    {
        printf("[%c]-> ", L->elem);
    }
    printf("\n");
}

void insertFirst(LIST *L, char X)
{
    LIST newNode = (LIST)malloc(sizeof(struct node));
    /*
    Why does type casting in malloc needs a pointer?

    malloc returns a pointer to the beginning of a block of memory.
    Since malloc returns a pointer to void `(void *)`, type casting
    allows you to convert this generic pointer to a desired pointer.

    In this cast LIST is already a pointer to a structure hence no need to type cast.
    */

    if (newNode != NULL)
    {
        newNode->elem = X;
        newNode->link = NULL;
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    if (*L == NULL) // Scenario 1: List is empty
    {
        *L = newNode;
    }
    else // Scenario 2: List is not empty
    {
        LIST temp = *L; // Pointer to node
        newNode->link = temp;
        *L = newNode;
    }
}

void insertLast(LIST *L, char X)
{
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->elem = X;
        newNode->link = NULL;
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    LIST *trav; // Pointer to pointer to node
    for (trav = L; *trav != NULL; trav = &(*trav)->link)
    {
    }
    *trav = newNode;
}

void insertPos(LIST *L, char X, int position)
{
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->elem = X;
        newNode->link = NULL;
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    LIST *trav; // Pointer to pointer to node
    int count = 0;
    for (trav = L; *trav != NULL && count < position; trav = &(*trav)->link)
    {
        count++;
    }
    LIST temp = *trav;
    newNode->link = temp;
    *trav = newNode;
}

void deleteFirst(LIST *L)
{
    if (*L == NULL) // Scenario 1: List is empty
    {
        printf("List is empty.\n");
    }
    else
    {
        // Scenario 2: List is not empty
        LIST temp = *L;  // Pointer to node
        *L = temp->link; // L is a pointer to a pointer to a node hence you need to dereference it
        free(temp);
    }
}

void deleteLast(LIST *L)
{
    LIST *trav; // Pointer to pointer to node
    for (trav = L; (*trav)->link != NULL; trav = &(*trav)->link)
    {
    }
    LIST temp;
    temp = (*trav)->link;
    *trav = temp;
    free(temp);
}

void deletePos(LIST *L, int position)
{
    LIST *trav; // Pointer to pointer to node
    int count = 0;
    for (trav = L; (*trav)->link != NULL && count < position; trav = &(*trav)->link)
    {
        count++;
    }

    LIST temp;
    temp = (*trav)->link;
    (*trav) = temp;
    free(temp);
}