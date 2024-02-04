#include <stdio.h>
#define MAX 5

int binarySearch(int list[], int size, int elem);

int main()
{
    int arr[MAX] = {7, 15, 23, 30, 46};
    int pos;

    pos = binarySearch(arr, MAX, 23);
    printf("%d", pos);

    return 0;
}

int binarySearch(int list[], int size, int elem)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (elem == list[mid])
        {
            return mid;
        }
        // Search to the left
        else if (elem > list[mid])
        {
            low = mid + 1;
        }
        // Search to the right
        else // elem <= list[mid]
        {
            high = mid - 1;
        }
    }

    return -1;
}