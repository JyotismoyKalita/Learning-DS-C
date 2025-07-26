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

void insert_rear(int val, QUEUE *arr)
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

void insert_front(int val, QUEUE *arr)
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
    arr->front = (arr->front + MAX_SIZE - 1) % MAX_SIZE;
    arr->arr[arr->front] = val;
}

void delete_rear(QUEUE *arr)
{
    if (arr->rear < 0)
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
    arr->rear = (arr->rear + MAX_SIZE - 1) % MAX_SIZE;
}

void delete_front(QUEUE *arr)
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
    insert_rear(23, &arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    insert_rear(46, &arr);
    display(&arr);
    printf("Expected:\n23 46\n");
    printf("--------------------------\n");
    delete_front(&arr);
    display(&arr);
    printf("Expected:\n46\n");
    printf("--------------------------\n");
    insert_front(61, &arr);
    display(&arr);
    printf("Expected:\n61 46\n");
    printf("--------------------------\n");
    insert_rear(78, &arr);
    display(&arr);
    printf("Expected:\n61 46 78\n");
    printf("--------------------------\n");
    insert_front(196, &arr);
    display(&arr);
    printf("Expected:\n196 61 46 78\n");
    printf("--------------------------\n");
    delete_rear(&arr);
    display(&arr);
    printf("Expected:\n196 61 46\n");
    printf("--------------------------\n");
    insert_front(21, &arr);
    display(&arr);
    printf("Expected:\n21 196 61 46\n");
    printf("--------------------------\n");
    delete_front(&arr);
    display(&arr);
    printf("Expected:\n196 61 46\n");
    printf("--------------------------\n");
    delete_front(&arr);
    display(&arr);
    printf("Expected:\n61 46\n");
    printf("--------------------------\n");
    delete_front(&arr);
    display(&arr);
    printf("Expected:\n46\n");
    printf("--------------------------\n");
    delete_rear(&arr);
    display(&arr);
    printf("Expected:\nQUEUE Empty\n");
    printf("--------------------------\n");
    delete_rear(&arr);
    printf("Expected:\nQUEUE Empty\n");
    printf("--------------------------\n");
    return 0;
}