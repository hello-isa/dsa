#include <stdio.h>
#define MAX 5

typedef struct node
{
    char arr[MAX];
    int top;
} *STACK;

void initializeStack(STACK *S);
void displayStack(STACK S);
void push(STACK *S, char elem);

int main()
{
    STACK SS;

    initializeStack(&SS);
    push(&SS, 'a');
    push(&SS, 'b');
    push(&SS, 'c');
    push(&SS, 'd');
    displayStack(SS);

    return 0;
}

void initializeStack(STACK *S)
{
    (*S)->top = -1; // Empty stack
}

void displayStack(STACK S)
{
    int count;

    printf("top: %d\n", S->top);

    for (count = S->top; count > -1; count--)
    {
        printf("[%c] %d\n", S->arr[count], count);
    }
    printf("\n");
}

void push(STACK *S, char elem)
{
    (*S)->arr[(*S)->top + 1] = elem;
    (*S)->top += 1;
}