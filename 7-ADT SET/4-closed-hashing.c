#include <stdio.h>
#include <ctype.h>
#define MAX 0xA
#define EMPTY '-'
#define DELETED '*'

// User defined data type
typedef char Dictionary[MAX];

typedef enum
{
    False,
    True
} Boolean;

// Function prototype
void initDictionary(Dictionary D);         // Initialize Dictionary to be EMPTY
void displayDictionary(Dictionary D);      // Display the content of the Dictionary
int hash(char elem);                       // Returns the arbitrary hash values
void insert(Dictionary D, char elem);      // Insert an element into the Dictionary
Boolean isMember(Dictionary D, char elem); // Returns TRUE if an element is a member of the Dictionary; else FALSE
void delete(Dictionary D, char elem);      // Delete an element from the Dictionary

int main()
{
    Dictionary A;

    // Function call
    initDictionary(A);
    displayDictionary(A);

    insert(A, 'a');
    insert(A, 'b');
    insert(A, 'b');
    insert(A, 'd');
    insert(A, 'c');
    insert(A, 'g');
    insert(A, 'j');
    insert(A, 'e');
    insert(A, 'a');
    insert(A, 'h');
    insert(A, 'i'); // Cannot insert, dictionary is full
    insert(A, 'k'); // Cannot insert, dictionary is full
    displayDictionary(A);

    delete (A, 'a');
    delete (A, 'c');
    delete (A, 'g');
    delete (A, 'h');
    delete (A, 'a');
    delete (A, 'a'); // Non-existent
    displayDictionary(A);

    return 0;
}

// Function definition
void initDictionary(Dictionary D)
{
    int n;

    for (n = 0; n < MAX; n++)
    {
        D[n] = EMPTY;
    }
}

void displayDictionary(Dictionary D)
{
    int n;

    printf("Index\tElement\n");
    for (n = 0; n < MAX; n++)
    {
        if (D[n] == EMPTY)
        {
            printf("%d:\t\t[ EMPTY ]\n", n);
        }
        else if (D[n] == DELETED)
        {
            printf("%d:\t\t[ DELETED ]\n", n);
        }
        else
        {
            printf("%d:\t\t[ %c ]\n", n, D[n]);
        }
    }
    printf("\n");
}

int hash(char elem)
{
    return tolower(elem - 'a');
}

void insert(Dictionary D, char elem)
{
    int n, count;

    for (n = hash(elem), count = 0; D[n] != EMPTY && D[n] != DELETED && count < MAX; n = (n + 1) % MAX, count++)
    {
    }
    if (count < MAX)
    {
        D[n] = elem;
    }
    else
    {
        printf("Dictionary is FULL. Cannot insert '%c'.\n", elem);
    }
}

Boolean isMember(Dictionary D, char elem)
{
    int n, count;
    Boolean member = False;

    for (n = hash(elem), count = 0; count < MAX && D[n] != elem; n = (n + 1) % MAX, count++)
    {
    }
    if (D[n] == elem)
    {
        member = True;
    }

    return member;
}

void delete(Dictionary D, char elem)
{
    int n, count;

    for (n = hash(elem), count = 0; D[n] != elem && count < MAX; n = (n + 1) % MAX, count++)
    {
    }
    if (isMember(&D[n], elem) == True)
    {
        D[n] = DELETED;
    }
    else
    {
        printf("Deletion of '%c' is NOT allowed. Element is not found in the Dictionary.\n", elem);
    }
}
