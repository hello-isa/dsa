#define MAX 5

typedef struct node // Structure data type: 9 bytes
{
    char arr[MAX]; // 5 bytes
    int count;     // 4 bytes
} *LIST;           // Pointer to structure: 8 bytes
