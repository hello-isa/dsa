// Array list version 2 implementation
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node
{
    char arr[MAX];
    int top;
} *STACK;

typedef enum
{
    F, // False
    T  // True
} boolean;

void initializeStack(STACK *S);
void displayStack(STACK S);
void push(STACK *S, char elem);
char pop(STACK *S);
char peek(STACK S);
boolean isEmpty(STACK S);
boolean isFull(STACK S);

int main()
{
    STACK SS;

    initializeStack(&SS);

    push(&SS, 'a');
    push(&SS, 'b');
    push(&SS, 'c');
    push(&SS, 'd');
    push(&SS, 'e');
    displayStack(SS);

    char popped = pop(&SS);
    printf("Popped element: %c\n", popped);
    displayStack(SS);

    char peeked = peek(SS);
    printf("Peeked element: %c\n", peeked);
    displayStack(SS);

    if (isEmpty(SS) == T)
    {
        printf("Stack is EMPTY.\n");
    }
    else
    {
        printf("Stack is NOT empty.\n");
    }

    if (isFull(SS) == T)
    {
        printf("Stack is FULL.\n");
    }
    else
    {
        printf("Stack is NOT full.\n");
    }

    return 0;
}

void initializeStack(STACK *S)
{
    (*S) = (STACK)malloc(sizeof(struct node));
    if (*S != NULL)
    {
        (*S)->top = -1; // Empty stack
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
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
    (*S)->top += 1;
    (*S)->arr[(*S)->top] = elem;
}

char pop(STACK *S)
{
    char elem = (*S)->arr[(*S)->top];
    (*S)->top -= 1;

    return elem;
}

char peek(STACK S)
{
    return S->arr[S->top];
}

boolean isEmpty(STACK S)
{
    return S->top == -1 ? T : F;
}

boolean isFull(STACK S)
{
    return S->top == (MAX - 1) ? T : F;
}