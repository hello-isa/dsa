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