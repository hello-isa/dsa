#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// User-defined data type
typedef struct node
{
    int elem;
    struct node *link;
} *SET;

typedef SET Dictionary[MAX];

typedef enum
{
    False,
    True
} Boolean;

// Function prototype
void initDictionary(Dictionary D);        // Initialize Dictionary
void displayDictionary(Dictionary D);     // Display the elements of the Dictionary
int hash(int elem);                       // Returns the ones value to locate which index (i.e. 0 to 9) to insert the new element
Boolean isMember(Dictionary D, int elem); // Returns TRUE if the element is a member; else returns FALSE
void insert(Dictionary D, int elem);      // Insert an element into the Dictionary
void delete(Dictionary D, int elem);      // Delete an element from the Dictionary

int main()
{
    Dictionary A;

    // Function call
    initDictionary(A);
    displayDictionary(A);

    insert(A, 20);
    insert(A, 0);
    insert(A, 30);
    insert(A, 13);
    insert(A, 33);
    insert(A, 45);
    insert(A, 108);
    insert(A, 28);
    insert(A, 48);
    // insert(A, 20); // Existing element
    displayDictionary(A);

    delete (A, 20);
    delete (A, 33);
    delete (A, 28);
    // delete (A, 11); // Non-existent element
    displayDictionary(A);

    return 0;
}

void initDictionary(Dictionary D)
{
    int n;
    for (n = 0; n < MAX; n++)
    {
        D[n] = NULL;
    }
}

void displayDictionary(Dictionary D)
{
    int n;
    SET trav;

    printf("SET #\n");
    for (n = 0; n < MAX; n++)
    {
        printf("%d:\t", n);
        for (trav = D[n]; trav != NULL; trav = trav->link)
        {
            printf("%d\t", trav->elem);
        }
        printf("\n");
    }
    printf("\n");
}

int hash(int elem)
{
    return elem % 10;
}

Boolean isMember(Dictionary D, int elem)
{
    int pos = hash(elem);
    SET trav;
    Boolean member = False;

    for (trav = D[pos]; trav != NULL; trav = trav->link)
    {
        if (trav->elem == elem)
        {
            member = True;
        }
    }

    return member;
}

void insert(Dictionary D, int elem)
{
    if ((isMember(D, elem)) == True)
    {
        printf("Insertion is not allowed. Element MUST be UNIQUE.\n");
    }
    else
    {
        // Element does not exist hence insertion is allowed
        // Elements must be sorted
        // Implement PPN since insertion

        // Create new node because element is unique
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode != NULL)
        {
            newNode->elem = elem;
            newNode->link = NULL;
        }
        else
        {
            printf("Memory allocation failed.\n");
        }

        int pos = hash(elem);

        SET *trav, temp;
        for (trav = &(D[pos]); *trav != NULL && (*trav)->elem < newNode->elem; trav = &(*trav)->link)
        {
        }
        temp = *trav;
        *trav = newNode;
        newNode->link = temp;
    }
}

void delete(Dictionary D, int elem)
{
    if ((isMember(D, elem)) == False)
    {
        printf("Element does NOT exist. Deletion is NOT allowed.\n");
    }
    else
    {
        // Element exist in the list hence deletion is allowed
        // Implement PPN since deletion
        SET *trav, temp;

        int pos = hash(elem);

        for (trav = &(D[pos]); *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->link)
        {
        }
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}