#include <stdio.h>
#define MAX 10
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
void delete(Dictionary D, char elem);      // Delete an element from the Dictionary
Boolean isMember(Dictionary D, char elem); // Returns TRUE if an element is a member of the Dictionary; else FALSE

int main()
{
    Dictionary A;

    // Function call
    initDictionary(A);
    displayDictionary(A);

    insert(A, 'a');
    insert(A, 'b');
    insert(A, 'c');
    insert(A, 'd');
    insert(A, 'e');
    insert(A, 'f');
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
    int hashValue;

    // Arbitrary values
    switch (elem)
    {
    case 'a':
        hashValue = 3;
        break;
    case 'b':
        hashValue = 9;
        break;
    case 'c':
        hashValue = 4;
        break;
    case 'd':
        hashValue = 3;
        break;
    case 'e':
        hashValue = 9;
        break;
    case 'f':
        hashValue = 0;
        break;
    case 'g':
        hashValue = 1;
        break;
    case 'h':
        hashValue = 3;
        break;
    case 'i':
        hashValue = 0;
        break;
    case 'j':
        hashValue = 3;
        break;
    }

    return hashValue;
}

void insert(Dictionary D, char elem)
{
    // Implemented in circular array
    // Cell is either EMPTY, DELETED or has an element

    int pos = hash(elem); // Determine the index where to insert the elements
    int n;

    // If cell is EMPTY, insert immediately
    if (D[pos] == EMPTY)
    {
        D[pos] = elem;
    }

    // If cell iS DELETED or contains an element, look for the nearest EMPTY cell
    if (D[pos] == DELETED)
    {
        for (n = pos; n < pos; n = (n + 1) % MAX)
        {
        }
        D[n] = elem;
    }

    /*
    Expected output should be:
        0: e
        1: f
        2: EMPTY
        3: a
        4: c
        5: d
        6: EMPTY
        7: EMPTY
        8: EMPTY
        9: b
    */
}