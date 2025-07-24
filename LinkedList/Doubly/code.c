#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;

void create(int val, NODE **head, NODE **end)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = NULL;
    NN->prev = NULL;
    *head = NN;
    *end = NN;
}

void insert_at_front(int val, NODE **head)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = *head;
    NN->prev = NULL;
    (*head)->prev = NN;
    *head = NN;
}

void insert_at(int pos, int val, NODE **head, NODE **end)
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
    if (T->next == NULL)
    {
        *end = NN;
    }
    else
    {
        T->next->prev = NN;
    }
    NN->next = T->next;
    NN->prev = T;
    T->next = NN;
}

void insert_at_end(int val, NODE **end)
{
    NODE *T = *end;
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = NULL;
    NN->prev = T;
    T->next = NN;
    *end = NN;
}

void remove_from_front(NODE **head)
{
    NODE *T = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(T);
}

void remove_from(int pos, NODE **head, NODE **end)
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
    if (temp->next != NULL)
    {
        temp->next->prev = T;
    }
    else
    {
        *end = T;
    }
    free(temp);
}

void remove_from_end(NODE **end)
{
    NODE *T = (*end)->prev;
    NODE *temp = *end;
    T->next = NULL;
    temp->next->prev = T;
    *end = T;
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
        printf("%d <=> ", T->data);
        T = T->next;
    }
    printf("NULL\n");
}

void display_reverse(NODE **end)
{
    NODE *T = *end;
    printf("NULL <=> ");
    while (T->prev != NULL)
    {
        printf("%d <=> ", T->data);
        T = T->prev;
    }
    printf("%d\n", T->data);
}

int main()
{
    NODE *head, *end;
    create(23, &head, &end);
    display(&head);
    printf("Expected Result:\n23 <=> NULL\n\n");
    insert_at_end(35, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> NULL\n\n");
    insert_at_end(46, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 46 <=> NULL\n\n");
    insert_at_end(58, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 46 <=> 58 <=> NULL\n\n");
    insert_at(2, 61, &head, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 61 <=> 46 <=> 58 <=> NULL\n\n");
    remove_from_end(&end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 61 <=> 46 <=> NULL\n\n");
    remove_from(0, &head, &end);
    display(&head);
    printf("Expected Result:\n35 <=> 61 <=> 46 <=> NULL\n\n");
    remove_from_front(&head);
    display(&head);
    printf("Expected Result:\n61 <=> 46 <=> NULL\n\n");
    insert_at_front(29, &head);
    display(&head);
    printf("Expected Result:\n29 <=> 61 <=> 46 <=> NULL\n\n");
    display_reverse(&end);
    printf("Expected Result:\nNULL <=> 46 <=> 61 <=> 29\n\n");
    remove_all(&head);
    return 0;
}