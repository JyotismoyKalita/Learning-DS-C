#include <stdio.h>
#include <stdlib.h>

#define MUL 2
#define INITAL_SIZE 2

typedef struct
{
    int capacity;
    int end;
    int *arr;
} Array;

Array *create()
{
    Array *ptr = (Array *)malloc(sizeof(Array));
    if (ptr == NULL)
    {
        printf("Error Allocating Memory\n");
        return NULL;
    }
    ptr->arr = (int *)malloc(sizeof(int) * INITAL_SIZE);
    ptr->end = -1;
    ptr->capacity = INITAL_SIZE;
    return ptr;
}

void insert(int pos, int val, Array *arr)
{
    if (arr == NULL || arr->arr == NULL)
    {
        printf("Invalid Array\n");
        return;
    }
    if (pos > arr->end + 1 || pos < 0)
    {
        printf("Invalid Position: Out of bounds\n");
        return;
    }
    if (arr->end >= arr->capacity - 1)
    {
        int *temp = arr->arr;
        arr->arr = (int *)realloc(arr->arr, sizeof(int) * arr->capacity * MUL);
        if (arr->arr == NULL)
        {
            printf("Error Resizing Array\n");
            arr->arr = temp;
            return;
        }
        arr->capacity = arr->capacity * MUL;
    }
    arr->end += 1;
    for (int i = arr->end; i > pos; i--)
    {
        arr->arr[i] = arr->arr[i - 1];
    }
    arr->arr[pos] = val;
}

void insert_at_end(int val, Array *arr)
{
    if (arr == NULL || arr->arr == NULL)
    {
        printf("Invalid Array\n");
        return;
    }
    if (arr->end >= arr->capacity - 1)
    {
        int *temp = arr->arr;
        arr->arr = (int *)realloc(arr->arr, sizeof(int) * arr->capacity * MUL);
        if (arr->arr == NULL)
        {
            printf("Error Resizing Array\n");
            arr->arr = temp;
            return;
        }
        arr->capacity = arr->capacity * MUL;
    }
    arr->end += 1;
    arr->arr[arr->end] = val;
}

void remove_item(int pos, Array *arr)
{
    if (arr == NULL || arr->arr == NULL)
    {
        printf("Invalid Array\n");
        return;
    }
    if (arr->end < 0)
    {
        printf("Array Empty\n");
        return;
    }
    for (int i = pos; i < arr->end; i++)
    {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->end -= 1;
}

void remove_from_end(Array *arr)
{
    if (arr == NULL || arr->arr == NULL)
    {
        printf("Invalid Array\n");
        return;
    }
    if (arr->end < 0)
    {
        printf("Array Empty\n");
        return;
    }
    arr->end -= 1;
}

void display(Array *arr)
{
    if (arr == NULL || arr->arr == NULL)
    {
        printf("Invalid Array\n");
        return;
    }
    for (int i = 0; i <= arr->end; i++)
    {
        printf("%d  ", arr->arr[i]);
    }
    printf("\n");
}

int main()
{
    Array *arr1 = create();
    insert_at_end(23, arr1);
    display(arr1);
    printf("Expected Result:\n23\n\n");
    insert_at_end(35, arr1);
    display(arr1);
    printf("Expected Result:\n23  35\n\n");
    insert_at_end(46, arr1);
    display(arr1);
    printf("Expected Result:\n23  35  46\n\n");
    insert_at_end(58, arr1);
    display(arr1);
    printf("Expected Result:\n23  35  46  58\n\n");
    insert(2, 61, arr1);
    display(arr1);
    printf("Expected Result:\n23  35  61  46  58\n\n");
    remove_from_end(arr1);
    display(arr1);
    printf("Expected Result:\n23  35  61  46\n\n");
    remove_item(0, arr1);
    display(arr1);
    printf("Expected Result:\n35  61  46\n\n");
    free(arr1->arr);
    free(arr1);
    return 0;
}