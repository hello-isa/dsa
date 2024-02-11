#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char elem;
    struct node *link;
} *LIST;

void displayList(LIST L);
void insertFirst(LIST *L, char X);

int main()
{
    LIST LL = NULL;

    insertFirst(&LL, 'A');
    insertFirst(&LL, 'B');
    insertFirst(&LL, 'C');
    displayList(LL);

    return 0;
}

void displayList(LIST L)
{
    for (; L != NULL; L = L->link)
    {
        printf("[%c]-> ", L->elem);
    }
}

void insertFirst(LIST *L, char X)
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

    if (*L == NULL) // Scenario 1: List is empty
    {
        *L = newNode;
    }
    else // Scenario 2: List is not empty
    {
        LIST temp = *L;
        newNode->link = temp;
        *L = newNode;
    }
}