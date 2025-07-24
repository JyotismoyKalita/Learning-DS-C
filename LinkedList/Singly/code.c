#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *create(int val)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = NULL;
    return NN;
}

void insert_at_front(int val, NODE **head)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = *head;
    *head = NN;
}

void insert_at(int pos, int val, NODE **head)
{
    if (pos == 0)
    {
        insert_at_front(val, head);
        return;
    }
    NODE *T = *head;
    int i;
    for (i = 0; i < pos - 1 && T != NULL; i++)
    {
        T = T->next;
    }
    if (i != pos - 1)
    {
        printf("Invalid Position: Out of bounds\n");
        return;
    }
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = T->next;
    T->next = NN;
}

void insert_at_end(int val, NODE **head)
{
    NODE *T = *head;
    while (T->next != NULL)
    {
        T = T->next;
    }
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = NULL;
    T->next = NN;
}

void remove_from_front(NODE **head)
{
    NODE *T = *head;
    *head = (*head)->next;
    free(T);
}

void remove_from(int pos, NODE **head)
{
    if (pos == 0)
    {
        remove_from_front(head);
        return;
    }
    NODE *T = *head;
    int i;
    for (i = 0; i < pos - 1 && T != NULL; i++)
    {
        T = T->next;
    }
    if (i != pos - 1)
    {
        printf("Invalid Position: Out of bounds\n");
        return;
    }
    NODE *temp = T->next;
    T->next = temp->next;
    free(temp);
}

void remove_from_end(NODE **head)
{
    NODE *T = *head;
    while (T->next->next != NULL)
    {
        T = T->next;
    }
    NODE *temp = T->next;
    T->next = NULL;
    free(temp);
}

void remove_all(NODE **head)
{
    NODE *T = *head;
    while (T != NULL)
    {
        NODE *temp = T;
        T = T->next;
        free(temp);
    }
    *head = NULL;
}

void display(NODE **head)
{
    NODE *T = *head;
    while (T != NULL)
    {
        printf("%d -> ", T->data);
        T = T->next;
    }
    printf("NULL\n");
}

int main()
{
    NODE *head = create(23);
    display(&head);
    printf("Expected Result:\n23 -> NULL\n\n");
    insert_at_end(35, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> NULL\n\n");
    insert_at_end(46, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 46 -> NULL\n\n");
    insert_at_end(58, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 46 -> 58 -> NULL\n\n");
    insert_at(2, 61, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 61 -> 46 -> 58 -> NULL\n\n");
    remove_from_end(&head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 61 -> 46 -> NULL\n\n");
    remove_from(0, &head);
    display(&head);
    printf("Expected Result:\n35 -> 61 -> 46 -> NULL\n\n");
    remove_from_front(&head);
    display(&head);
    printf("Expected Result:\n61 -> 46 -> NULL\n\n");
    insert_at_front(29, &head);
    display(&head);
    printf("Expected Result:\n29 -> 61 -> 46 -> NULL\n\n");
    remove_all(&head);
    return 0;
}