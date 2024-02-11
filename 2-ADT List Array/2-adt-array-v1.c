#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    char arr[MAX]; // 5 bytes
    int count;     // 4 bytes
} LIST;            // 9 bytes

void initializeList(LIST *L);

int main()
{
    LIST Arr;

    initializeList(&Arr);

    return 0;
}

void initializeList(LIST *L)
{
    L = (LIST *)malloc(sizeof(LIST));

    if (L != NULL)
    {
        L->count = 0;
    }
    else
    {
        /* If malloc fails, it will return a NULL pointer
        instead of a valid memory address.*/
        printf("Memory allocation failed.\n");
    }
}