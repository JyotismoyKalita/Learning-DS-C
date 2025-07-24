#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct
{
    NODE *top;
} STACK;

void init(STACK *stk)
{
    stk->top = NULL;
}

void push(int val, STACK *stk)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = stk->top;
    stk->top = NN;
}

void pop(STACK *stk)
{
    if (stk->top == NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    NODE *T = stk->top;
    stk->top = stk->top->next;
    free(T);
}

void pop_all(STACK *stk)
{
    NODE *T = stk->top;
    while (T != NULL)
    {
        NODE *temp = T;
        T = T->next;
        free(temp);
    }
    stk->top = NULL;
}

void display(STACK *stk)
{
    NODE *T = stk->top;
    if (T == NULL)
    {
        printf("Stack Empty\n");
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
    STACK arr;
    init(&arr);
    printf("--------------------------\n");
    push(23, &arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    push(46, &arr);
    display(&arr);
    printf("Expected:\n46 23\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    push(61, &arr);
    display(&arr);
    printf("Expected:\n61 23\n");
    printf("--------------------------\n");
    push(78, &arr);
    display(&arr);
    printf("Expected:\n78 61 23\n");
    printf("--------------------------\n");
    push(196, &arr);
    display(&arr);
    printf("Expected:\n196 78 61 23\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n78 61 23\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n61 23\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\nStack Empty\n");
    printf("--------------------------\n");
    pop(&arr);
    printf("Expected:\nStack Empty\n");
    printf("--------------------------\n");
    pop_all(&arr);
    return 0;
}