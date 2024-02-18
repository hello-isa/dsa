#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node
{
    char *elemPtr;
    int front;
    int rear;
} *QUEUE;

void initializeQueue(QUEUE *Q);
void displayQueue(QUEUE Q);
void enqueue(QUEUE Q, char elem);

int main()
{
    QUEUE QQ;

    initializeQueue(&QQ);
    enqueue(QQ, 'A');
    displayQueue(QQ);
    enqueue(QQ, 'B');
    displayQueue(QQ);
    enqueue(QQ, 'C');
    displayQueue(QQ);

    return 0;
}

void initializeQueue(QUEUE *Q)
{
    (*Q) = (QUEUE)malloc(sizeof(struct node));
    if ((*Q) != NULL)
    {
        (*Q)->elemPtr = (char *)malloc(sizeof(char) * MAX);
        (*Q)->front = -1; // Empty queue
        (*Q)->rear = -1;  // Empty queue
    }
}

void displayQueue(QUEUE Q)
{
    int count;
    printf("front: %d\trear: %d\n", Q->front, Q->rear);
    for (count = Q->front; count <= Q->rear; count++)
    {
        printf("[%c] ", Q->elemPtr[count]);
    }
    printf("\n\n");
}

void enqueue(QUEUE Q, char elem)
{
    if (Q->front == -1)
    {
        // Only 1 element in the queue, front = rear
        Q->front += 1;
        Q->rear = Q->front;
        Q->elemPtr[Q->rear] = elem;
    }
    else
    {
        Q->rear += 1;
        Q->elemPtr[Q->rear] = elem;
    }
}