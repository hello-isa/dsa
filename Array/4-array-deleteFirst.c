#include <stdio.h>
#define MAX 5

void displayArr(char A[], int n);
void deleteFirst(char A[], int *n);

int main()
{
    char arr[MAX] = {'l', 'j', 'g', 'd', 'a'};
    int size = MAX;

    printf("Before deletion:\n");
    displayArr(arr, size);

    deleteFirst(arr, &size); // Pass by address, so the integer variable can be modified
    printf("\n\nAfter deletion:\n");
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
}

void deleteFirst(char A[], int *n) // Since you are passing by address, this is a pointer
{
    int nDex;
    for (nDex = 0; nDex < *n; nDex++) // Dereferencing the pointer so you can compare with an integer
    {
        A[nDex] = A[nDex + 1];
    }
    (*n)--; // Dereferencing so that you can decrement the value where the pointer points to
}