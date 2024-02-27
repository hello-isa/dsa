#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// User-defined data type
typedef struct node
{
    int elem;
    struct node *link;
} *SET;

typedef SET Dictionary[MAX];

typedef enum
{
    False,
    True
} Boolean;

// Function prototypes

int main()
{
    return 0;
}