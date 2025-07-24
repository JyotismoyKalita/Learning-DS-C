#include <stdio.h>

#define MAX_SIZE 1024

typedef struct
{
    int top;
    int arr[MAX_SIZE];
} STACK;

void init(STACK *arr)
{
    arr->top = -1;
}

void push(int val, STACK *arr)
{
    if (arr->top >= MAX_SIZE - 1)
    {
        printf("Stack Full\n");
        return;
    }
    arr->top += 1;
    arr->arr[arr->top] = val;
}

void pop(STACK *arr)
{
    if (arr->top < 0)
    {
        printf("Stack Empty\n");
    }
    arr->top -= 1;
}

void display(STACK *arr)
{
    if (arr->top < 0)
    {
        printf("Stack Empty\n");
        return;
    }
    for (int i = 0; i <= arr->top; i++)
    {
        printf("%d ", arr->arr[i]);
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
    printf("Expected:\n23 46\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n23\n");
    printf("--------------------------\n");
    push(61, &arr);
    display(&arr);
    printf("Expected:\n23 61\n");
    printf("--------------------------\n");
    push(78, &arr);
    display(&arr);
    printf("Expected:\n23 61 78\n");
    printf("--------------------------\n");
    push(196, &arr);
    display(&arr);
    printf("Expected:\n23 61 78 196\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n23 61 78\n");
    printf("--------------------------\n");
    pop(&arr);
    display(&arr);
    printf("Expected:\n23 61\n");
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
    return 0;
}