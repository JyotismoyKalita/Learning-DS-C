#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct
{
    NODE *front;
    NODE *rear;
} QUEUE;

void init(QUEUE *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void insert(int val, int priority, QUEUE *q)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->priority = priority;
    NN->next = NULL;
    if (q->front == NULL)
    {
        NN->prev = NULL;
        q->front = NN;
    }
    if (q->rear != NULL)
    {
        NN->prev = q->rear;
        q->rear->next = NN;
    }
    q->rear = NN;
}

void delete(QUEUE *q)
{
    if (q->front == NULL)
    {
        printf("QUEUE Empty\n");
        return;
    }
    int min = 999;
    NODE *U = NULL;
    for (NODE *T = q->front; T != NULL; T = T->next)
    {
        if (T->priority < min)
        {
            U = T;
            min = T->priority;
        }
    }
    if (U->prev != NULL && U->next != NULL)
    {
        U->prev->next = U->next;
        U->next->prev = U->prev;
    }
    else if (U->prev == NULL && U->next != NULL)
    {
        U->next->prev = NULL;
        q->front = U->next;
    }
    else if (U->prev != NULL && U->next == NULL)
    {
        U->prev->next = NULL;
        q->rear = U->prev;
    }
    else
    {
        q->front = NULL;
        q->rear = NULL;
    }
    free(U);
}

void delete_all(QUEUE *q)
{
    NODE *T = q->front;
    if (T == NULL)
    {
        printf("QUEUE Empty\n");
        return;
    }
    while (T != NULL)
    {
        NODE *temp = T;
        T = T->next;
        free(temp);
    }
    q->front = NULL;
    q->rear = NULL;
}

void display(QUEUE *q)
{
    NODE *T = q->front;
    if (T == NULL)
    {
        printf("QUEUE Empty\n");
        return;
    }
    while (T != NULL)
    {
        printf("%d ", T->data);
        T = T->next;
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
    delete_all(&arr);
    return 0;
}