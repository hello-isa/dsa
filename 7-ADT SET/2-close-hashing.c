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
void initDictionary(Dictionary D);    // Initialize Dictionary to be EMPTY
void displayDictionary(Dictionary D); // Display the content of the Dictionary
int hash(char elem);                  // Return the arbitrary hash values
void insert(Dictionary D, char elem); // Insert an element into the Dictionary

int main()
{
    Dictionary A;

    // Function call
    initDictionary(A);
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
    /*
    Arbitrary hash values
    a - 3
    b - 9
    c - 4
    d - 3
    e - 9
    f - 0
    g - 1
    j - 3
    */
}