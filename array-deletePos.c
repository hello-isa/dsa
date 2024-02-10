#include <stdio.h>
#define MAX 5

void displayArr(char A[], int n);
void deletePos(char A[], int *n, int pos);

int main()
{
    char arr[MAX] = {'m', 'b', 'c', 'z', 'a'};
    int size = MAX;

    printf("Before deletion:\n");
    displayArr(arr, size);

    deletePos(arr, &size, 4);
    printf("\nAfter deletion:\n");
    displayArr(arr, size);

    return 0;
}

void displayArr(char A[], int n)
{
    int count;

    for (count = 0; count < n; count++)
    {
        printf("[%c] ", A[count]);
    }
    printf("\n");
}

void deletePos(char A[], int *n, int pos)
{
    int count;

    for (count = pos; count < *n; count++)
    {
        A[count] = A[count + 1];
    }
    (*n)--;
}