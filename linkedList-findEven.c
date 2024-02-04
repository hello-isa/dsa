/*
Given a list, find all even numbers in the list and put them in a newly created list
which will be returned to the calling function.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int elem[MAX];
    int count; // Actual size of the array
} LIST;

// Function prototype
LIST *findEven(LIST);

int main()
{
    LIST num = {{5, 6, 7, 8}, 4};
    /*
    num.elem[] = {5, 6, 7, 8}; // Error
    num.count = 4; // Correct

    Again in C, the correct way to initialize an aggregate type is during its declaration.
    If you want to initialize after declaration, you have to assign each values individually.

    num.elem[0] = 5;
    num.elem[1] = 6;
    num.elem[2] = 7;
    num.elem[3] = 8;
    */

    LIST *evenList;
    evenList = findEven(num);

    return 0;
}

// Function definition
LIST *findEven(LIST L)
{
    int n;

    LIST *M;
    M = (LIST *)malloc(sizeof(LIST));

    if (M == NULL)
    {
        printf("Memory allocation failed.");
    }
    else
    {
        M->count = 0;
    }

    for (n = 0; n < L.count; n++)
    {
        if (L.elem[n] % 2 == 0)
        {
            M->elem[M->count++] = L.elem[n];
        }
    }

    return M;
}