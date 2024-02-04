/*
Given an array and its size, find all even numbers in the array and put them in a newly created array
starting at index 1 while Index 0 will contain the count of the even numbers. The newly created array
will be returned to the calling function.
*/

#include <stdio.h>
#include <stdlib.h> // For malloc
#include <string.h> // For memcpy

// Function prototype
int *evenNum(int A[], int n);

int main()
{
    int arr[] = {0, 2, 3, 4, 5};
    int size = 5;
    int *evenArr; // Catcher of the returned array

    // Function call
    evenArr = evenNum(arr, size);

    return 0;
}

// Function definition
int *evenNum(int A[], int n)
{
    int x, *B;
    int C[n];
    int count = 0;

    for (x = 0; x < n; x++)
    {
        if (A[x] % 2 == 0)
        {
            C[count++] = A[x];
        }
    }

    B = (int *)malloc(sizeof(int) * (count + 1));

    memcpy(&(B[1]), C, sizeof(int) * count);

    B[0] = count;

    return B;
}