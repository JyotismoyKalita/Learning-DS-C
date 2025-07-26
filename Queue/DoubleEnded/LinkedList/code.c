#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
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

void insert_front(int val, QUEUE *q)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = q->front;
    NN->prev = NULL;
    if (q->rear == NULL)
    {
        q->rear = NN;
    }
    q->front = NN;
}

void insert_rear(int val, QUEUE *q)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = NULL;
    if (q->front == NULL)
    {
        q->front = NN;
    }
    if (q->rear != NULL)
    {
        q->rear->next = NN;
    }
    NN->prev = q->rear;
    q->rear = NN;
}

void delete_front(QUEUE *q)
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

void delete_rear(QUEUE *q)
{
    if (q->rear == NULL)
    {
        printf("QUEUE Empty\n");
        return;
    }
    NODE *T = q->rear;
    q->rear = q->rear->prev;
    if (q->rear == NULL)
    {
        q->front = NULL;
    }
    else
    {
        q->rear->next = NULL;
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
    delete_all(&arr);
    return 0;
}