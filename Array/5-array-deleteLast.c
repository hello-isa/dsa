#include <stdio.h>
#define MAX 5

void displayArr(char A[], int n);
void deleteLast(char A[], int *n);

int main()
{
    char arr[MAX] = {'a', 'f', 'h', 'k', 'x'};
    int size = MAX;

    printf("Before deletion:\n");
    displayArr(arr, size);

    deleteLast(arr, &size);
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

void deleteLast(char A[], int *n)
{
    (*n)--;
}