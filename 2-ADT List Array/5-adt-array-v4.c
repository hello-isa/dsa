#define MAX 5

typedef struct node // Structure data type: 12 bytes
{
    char *elemPtr; // 8 bytes
    int count;     // 4 bytes
} *LIST;           // Pointer to structure: 8 bytes
