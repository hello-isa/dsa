#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Data type definition
typedef int SET[MAX];

void displaySET(SET X);
SET *unionSET(SET X, SET Y);
SET *intersectionSET(SET X, SET Y);
SET *differenceSET(SET X, SET Y);

int main()
{
    SET A = {1, 0, 1, 0, 1}; // {0, 2, 4}
    SET B = {0, 1, 1, 0, 0}; // {1, 2}

    SET *C = unionSET(A, B);
    displaySET(*C); // Dereference to pass the actual array
                    // `&C` will pass the address of pointer C

    SET *D = intersectionSET(A, B);
    displaySET(*D);

    SET *E = differenceSET(A, B);
    displaySET(*E);

    return 0;
}

void displaySET(SET X)
{
    int n;
    for (n = 0; n < MAX; n++)
    {
        printf("%d [ %d ]\n", n, X[n]);
    }
    printf("\n");
}

SET *unionSET(SET X, SET Y)
{
    int n;

    SET *Z = (SET *)calloc(MAX, sizeof(int));
    if (*Z == NULL)
    {
        printf("Memory allocation failed.\n");
    }

    for (n = 0; n < MAX; n++)
    {
        if (X[n] || Y[n]) // Check if either `X[n]` or `Y[n]` is TRUE
        {
            (*Z)[n] = 1; // Dereference to pass the actual array
        }
    }

    return Z;
}

SET *intersectionSET(SET X, SET Y)
{
    int n;

    SET *Z = (SET *)calloc(MAX, sizeof(int));
    if (Z == NULL)
    {
        printf("Memory allocation failed.\n");
    }

    for (n = 0; n < MAX; n++)
    {
        if (X[n] && Y[n])
        {
            (*Z)[n] = 1;
        }
    }

    return Z;
}

SET *differenceSET(SET X, SET Y)
{
    int n;

    SET *Z = (SET *)calloc(MAX, sizeof(int));
    if (Z == NULL)
    {
        printf("Memory allocation failed.\n");
    }

    for (n = 0; n < MAX; n++)
    {
        if (X[n] == 1 && Y[n] == 0)
        {
            (*Z)[n] = 1;
        }
    }

    return Z;
}