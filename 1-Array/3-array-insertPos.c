#include <stdio.h>
#define MAX 5

void displayArr(char A[]);
char *insertPos(char A[], int n, int pos, char x);

int main()
{
    /* Different scenarios:
    Position is valid.
    Array is not full.
    Position is invalid.
    Array is full.
    */
    char arr[MAX] = {'z', 'v', 'n', 'f'};
    int size = 4;

    printf("Before insertion:\n");
    displayArr(arr);

    char *newArr = insertPos(arr, size, 2, 'h');
    printf("\n\nAfter insertion:\n");
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

char *insertPos(char A[], int n, int pos, char x)
{
    int nDex;

    if (pos > 0 && pos < (MAX - 1)) // Position is within the range
    {
        if (n < MAX) // Allowed to insert
        {
            for (nDex = n; nDex > pos; nDex--)
            {
                A[nDex] = A[nDex - 1];
            }
            A[pos] = x;
        }
        else
        {
            printf("\nArray is full.");
        }
    }
    else
    {
        printf("\nPosition is invalid.");
    }

    return A;
}