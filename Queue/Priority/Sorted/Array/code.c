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
    int pos = arr->rear - 1;
    int i = (arr->rear - 1 + MAX_SIZE) % MAX_SIZE;
    while (priority < arr->prio[i] && i != (arr->front - 1 + MAX_SIZE) % MAX_SIZE)
    {
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        pos = i;
    }
    i = arr->rear;
    pos = (pos + 1) % MAX_SIZE;
    while (i != pos)
    {
        arr->arr[i] = arr->arr[(i - 1 + MAX_SIZE) % MAX_SIZE];
        arr->prio[i] = arr->prio[(i - 1 + MAX_SIZE) % MAX_SIZE];
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
    }
    arr->arr[pos] = val;
    arr->prio[pos] = priority;
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
    insert(23, 5, &arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    insert(61, 2, &arr);
    display(&arr);
    printf("Expected:\n61 23\n");
    printf("--------------------------\n");
    insert(33, 7, &arr);
    display(&arr);
    printf("Expected:\n61 23 33\n");
    printf("--------------------------\n");
    delete(&arr);
    display(&arr);
    printf("Expected:\n23 33\n");
    printf("--------------------------\n");
    insert(42, 1, &arr);
    display(&arr);
    printf("Expected:\n42 23 33\n");
    printf("--------------------------\n");
    insert(79, 10, &arr);
    display(&arr);
    printf("Expected:\n42 23 33 79\n");
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