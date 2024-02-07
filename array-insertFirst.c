#include <stdio.h>
#define MAX 5 // Maximum size of the array

void displayArr(char A[]);
char *insertFirst(char A[], int n, char x);

int main()
{
    // Scenario 1: Array is not full
    char arr[MAX] = {'c', 'z', 'j', 'v'};
    int size = 4; // Actual size of the array

    // Scenario 2: Array is full
    // char arr[MAX] = {'c', 'z', 'j', 'v', 'q'};
    // int size = 5;

    printf("Before insertion:\n");
    displayArr(arr);

    printf("\n\nAfter insertion:\n");
    char *newArr = insertFirst(arr, size, 'b');
    displayArr(newArr);

    return 0;
}

void displayArr(char A[])
{
    int count;
    for (count = 0; count < MAX; count++)
    {
        printf("[%c] ", A[count]);
    }
}

char *insertFirst(char A[], int n, char x)
{
    int nDex;

    if (n < MAX) // Allowed to insert
    {
        for (nDex = n; nDex > 0; nDex--)
        {
            A[nDex] = A[nDex - 1];
        }
        A[0] = x;
    }
    else
    {
        printf("Array is full.\n");
    }

    return A; /* Does it need *?
    No, because the array holds the address of the first element.
    Adding *A will be dereferencing.
    */
}