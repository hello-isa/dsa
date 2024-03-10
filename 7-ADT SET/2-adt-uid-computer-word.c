#include <stdio.h>
#define MAX 8

// Function prototype
void displayBitPattern(char elem);

int main()
{
    char a = 44;

    displayBitPattern(a);

    return 0;
}

void displayBitPattern(char elem)
{
    int n;
    for (n = MAX - 1; n >= 0; n--)
    {
        printf("%d", (elem >> n) & 1);
    }
}