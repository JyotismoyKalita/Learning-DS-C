#include <stdio.h>

#define MAX_SIZE 4

typedef struct
{
    int front;
    int rear;
    int arr[MAX_SIZE];
} QUEUE;

void init(QUEUE *arr)
{
    arr->front = -1;
    arr->rear = -1;
}

void insert(int val, QUEUE *arr)
{
    if ((arr->rear + 1) % MAX_SIZE == arr->front)
    {
        printf("QUEUE Full\n");
        return;
    }
    if (arr->front == -1)
    {
        arr->front = 0;
    }
    arr->rear = (arr->rear + 1) % MAX_SIZE;
    arr->arr[arr->rear] = val;
}

void delete(QUEUE *arr)
{
    if (arr->front < 0)
    {
        printf("QUEUE Empty\n");
        return;
    }
    if (arr->front == arr->rear)
    {
        arr->front = -1;
        arr->rear = -1;
        return;
    }
    arr->front = (arr->front + 1) % MAX_SIZE;
}

void display(QUEUE *arr)
{
    if (arr->rear < 0)
    {
        printf("QUEUE Empty\n");
        return;
    }
    if (arr->rear < arr->front)
    {
        for (int i = arr->front; i < MAX_SIZE; i++)
        {
            printf("%d ", arr->arr[i]);
        }
        for (int i = 0; i <= arr->rear; i++)
        {
            printf("%d ", arr->arr[i]);
        }
    }
    else
    {
        for (int i = arr->front; i <= arr->rear; i++)
        {
            printf("%d ", arr->arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    QUEUE arr;
    init(&arr);
    printf("--------------------------\n");
    insert(23, &arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    insert(46, &arr);
    display(&arr);
    printf("Expected:\n23 46\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n46\n");
    printf("--------------------------\n");
    insert(61, &arr);
    display(&arr);
    printf("Expected:\n46 61\n");
    printf("--------------------------\n");
    insert(78, &arr);
    display(&arr);
    printf("Expected:\n46 61 78\n");
    printf("--------------------------\n");
    insert(196, &arr);
    display(&arr);
    printf("Expected:\n46 61 78 196\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n61 78 196\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n78 196\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n196\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\nQUEUE Empty\n");
    printf("--------------------------\n");
    delete(&arr);
    printf("Expected:\nQUEUE Empty\n");
    printf("--------------------------\n");
    return 0;
}