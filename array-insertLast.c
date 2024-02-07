#include <stdio.h>
#define MAX 5 // Maximum size of the array

void displayArr(char A[]);
char *insertLast(char A[], int n, char x);

int main()
{
    // Scenario 1: Array is not full
    char arr[MAX] = {'w', 'y', 'i', 'p'};
    int size = 4; // Actual size of the array

    // Scenario 2: Array is full
    // char arr[MAX] = {'w', 'y', 'i', 'p', 'z'};
    // int size = 5;

    printf("Before insertion:\n");
    displayArr(arr);

    printf("\n\nAfter insertion:\n");
    char *newArr = insertLast(arr, size, 's');
    displayArr(arr);

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

char *insertLast(char A[], int n, char x)
{
    if (n < MAX) // Allowed to insert
    {
        A[n] = x;
    }
    else
    {
        printf("Array is full.\n");
    }

    return A;
}