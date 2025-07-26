#include <stdio.h>

#define MAX_SIZE 4

typedef struct
{
    int front;
    int rear;
    int arr[MAX_SIZE];
    int prio[MAX_SIZE];
} QUEUE;

void init(QUEUE *arr)
{
    arr->front = -1;
    arr->rear = -1;
}

void insert(int val, int priority, QUEUE *arr)
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
    arr->prio[arr->rear] = priority;
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
    int min = 999, pos = -1;
    if (arr->rear < arr->front)
    {
        for (int i = arr->front; i < MAX_SIZE; i++)
        {
            if (arr->prio[i] < min)
            {
                min = arr->prio[i];
                pos = i;
            }
        }
        for (int i = 0; i <= arr->rear; i++)
        {
            if (arr->prio[i] < min)
            {
                min = arr->prio[i];
                pos = i;
            }
        }
    }
    else
    {
        for (int i = arr->front; i <= arr->rear; i++)
        {
            if (arr->prio[i] < min)
            {
                min = arr->prio[i];
                pos = i;
            }
        }
    }
    if (pos < arr->front)
    {
        for (int i = pos; i > 0; i--)
        {
            arr->arr[i] = arr->arr[i - 1];
            arr->prio[i] = arr->prio[i - 1];
        }
        arr->arr[0] = arr->arr[MAX_SIZE - 1];
        arr->prio[0] = arr->prio[MAX_SIZE - 1];
        for (int i = MAX_SIZE - 1; i > arr->front; i--)
        {
            arr->arr[i] = arr->arr[i - 1];
            arr->prio[i] = arr->prio[i - 1];
        }
    }
    else
    {
        for (int i = pos; i > arr->front; i--)
        {
            arr->arr[i] = arr->arr[i - 1];
            arr->prio[i] = arr->prio[i - 1];
        }
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
    insert(23, 5, &arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    insert(61, 2, &arr);
    display(&arr);
    printf("Expected:\n23 61\n");
    printf("--------------------------\n");
    insert(33, 7, &arr);
    display(&arr);
    printf("Expected:\n23 61 33\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n23 33\n");
    printf("--------------------------\n");
    insert(42, 1, &arr);
    display(&arr);
    printf("Expected:\n23 33 42\n");
    printf("--------------------------\n");
    insert(79, 10, &arr);
    display(&arr);
    printf("Expected:\n23 33 42 79\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n23 33 79\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n33 79\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n79\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\nQUEUE Empty\n");
    printf("--------------------------\n");

    return 0;
}