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
void initDictionary(Dictionary D);
void displayDictionary(Dictionary D);

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

        printf("%d:\t\t[ %c ]\n", n, D[n]);
    }
    printf("\n");
}