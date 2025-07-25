#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
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

void insert(int val, QUEUE *q)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    if (q->front == NULL)
    {
        q->front = NN;
    }
    NN->next = q->front;
    if (q->rear != NULL)
    {
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
    NODE *T = q->front;
    if (q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
        q->rear->next = q->front;
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
    do
    {
        NODE *temp = T;
        T = T->next;
        free(temp);
    } while (T != q->rear);
    free(T);
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
    do
    {
        printf("%d ", T->data);
        T = T->next;
    } while (T != q->front);
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
    delete_all(&arr);
    return 0;
}