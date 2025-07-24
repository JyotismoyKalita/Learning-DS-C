#include <stdio.h>

#define MAX_SIZE 1024

typedef struct
{
    int end;
    int arr[MAX_SIZE];
} Array;

void init(Array *arr)
{
    arr->end = -1;
}

void insert(int pos, int val, Array *arr)
{
    if (pos > arr->end + 1 || pos < 0)
    {
        printf("Invalid Position: Out of bounds\n");
        return;
    }

    if (arr->end >= MAX_SIZE - 1)
    {
        printf("Array Full\n");
        return;
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
    if (arr->end >= MAX_SIZE - 1)
    {
        printf("Array Full\n");
        return;
    }
    arr->end += 1;
    arr->arr[arr->end] = val;
}

void remove_item(int pos, Array *arr)
{
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
    if (arr->end < 0)
    {
        printf("Array Empty\n");
        return;
    }
    arr->end -= 1;
}

void display(Array *arr)
{
    for (int i = 0; i <= arr->end; i++)
    {
        printf("%d  ", arr->arr[i]);
    }
    printf("\n");
}

int main()
{
    Array arr1;
    init(&arr1);
    insert_at_end(23, &arr1);
    display(&arr1);
    insert_at_end(35, &arr1);
    display(&arr1);
    insert_at_end(46, &arr1);
    display(&arr1);
    insert_at_end(58, &arr1);
    display(&arr1);
    insert(2, 61, &arr1);
    display(&arr1);
    remove_from_end(&arr1);
    display(&arr1);
    remove_item(0, &arr1);
    display(&arr1);
    printf("Expected Result:\n35  61  46\n");
    return 0;
}