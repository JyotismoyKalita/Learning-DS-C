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
    if (q->front == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        q->front = NN;
        q->rear = NN;
        return;
    }
    NODE *T = q->rear;
    while (T != NULL && priority < T->priority)
    {
        T = T->prev;
    }
    if (T == NULL)
    {
        NN->next = q->front;
        NN->prev = NULL;
        q->front->prev = NN;
        q->front = NN;
    }
    else if (T->next != NULL)
    {
        NN->next = T->next;
        NN->prev = T;
        T->next = NN;
    }
    else
    {
        q->rear->next = NN;
        NN->prev = q->rear;
        NN->next = NULL;
        q->rear = NN;
    }
}

void delete(QUEUE *q)
{
    if (q->front == NULL)
    {
        printf("QUEUE Empty\n");
        return;
    }
    NODE *T = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    else
    {
        q->front->prev = NULL;
    }
    free(T);
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
    delete_all(&arr);
    return 0;
}