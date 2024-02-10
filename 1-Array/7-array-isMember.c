#include <stdio.h>
#define MAX 5

typedef enum
{
    False,
    True
} Boolean;

Boolean isMember(char A[], int n, char elem); // Returns True or False if the element is a member
int isMemberPos(char A[], int n, char elem);  // Return the position of the element if found in the list, else -1

int main()
{
    char arr[MAX] = {'g', 'h', 'j', 'k', 'l'};
    int size = MAX;
    char element = 'l'; // Change the element

    Boolean boolArr = isMember(arr, size, element);
    if (boolArr == False)
    {
        printf("Element is not a member.\n");
    }
    else
    {
        printf("Element is a member.\n");
    }

    int posArr = isMemberPos(arr, size, element);
    printf("Element position: %d\n", posArr);

    return 0;
}

Boolean isMember(char A[], int n, char elem)
{
    int count;
    Boolean result = False; // Making a default return value

    /*
    for (count = 0; count < n; count++)
    {
        return A[count] == elem ? True : False;
    }

    The moment it goes through the first iteration, it will return a value.
    In other words, the loop will exit prematurely without checking the rest of the array.
    Hence, return statement should be outside the loop.
    */

    for (count = 0; count < n; count++)
    {
        if (A[count] == elem)
        {
            result = True;
        }
    }

    return result;
}

int isMemberPos(char A[], int n, char elem)
{
    int count;
    int position = -1;

    for (count = 0; count < n; count++)
    {
        if (A[count] == elem)
        {
            position = count;
        }
    }

    return position;
}