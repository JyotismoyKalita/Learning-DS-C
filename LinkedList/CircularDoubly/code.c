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
    NN->next = NN;
    NN->prev = NN;
    *head = NN;
    *end = NN;
}

void insert_at_front(int val, NODE **head, NODE **end)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = *head;
    (*head)->prev = NN;
    *head = NN;
    (*head)->prev = *end;
    (*end)->next = *head;
}

void insert_at(int pos, int val, NODE **head, NODE **end)
{
    if (pos == 0)
    {
        insert_at_front(val, head, end);
        return;
    }
    NODE *T = *head;
    int i = 0;
    do
    {
        T = T->next;
        i++;
    } while (i < pos - 1 && T != *head);
    if (i != pos - 1)
    {
        printf("Invalid Position: Out of bounds\n");
        return;
    }
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;

    NN->next = T->next;
    T->next->prev = NN;

    NN->prev = T;
    T->next = NN;

    if (NN->next == *head)
    {
        *end = NN;
    }
}

void insert_at_end(int val, NODE **end)
{
    NODE *T = *end;
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = T->next;
    NN->prev = T;
    T->next = NN;
    *end = NN;
}

void remove_from_front(NODE **head, NODE **end)
{
    NODE *T = *head;
    *head = (*head)->next;
    (*head)->prev = *end;
    (*end)->next = *head;
    free(T);
}

void remove_from(int pos, NODE **head, NODE **end)
{
    if (pos == 0)
    {
        remove_from_front(head, end);
        return;
    }
    NODE *T = *head;
    int i = 0;
    do
    {
        T = T->next;
        i++;
    } while (i < pos - 1 && T != *head);
    if (i != pos - 1)
    {
        printf("Invalid Position: Out of bounds\n");
        return;
    }
    NODE *temp = T->next;
    T->next = temp->next;
    temp->next->prev = T;
    if (T->next == *head)
    {
        *end = T;
    }
    free(temp);
}

void remove_from_end(NODE **end)
{
    NODE *T = (*end)->prev;
    NODE *temp = *end;
    T->next = temp->next;
    temp->next->prev = T;
    *end = T;
    free(temp);
}

void remove_all(NODE **head)
{
    NODE *T = *head;
    do
    {
        NODE *temp = T;
        T = T->next;
        free(temp);
    } while (T != *head);
    *head = NULL;
}

void display(NODE **head)
{
    NODE *T = *head;
    do
    {
        printf("%d <=> ", T->data);
        T = T->next;
    } while (T != *head);
    printf("HEAD\n");
}

void display_reverse(NODE **end)
{
    NODE *T = *end;
    printf("HEAD <=> ");
    do
    {
        printf("%d <=> ", T->data);
        T = T->prev;
    } while (T->prev != *end);
    printf("%d\n", T->data);
}

int main()
{
    NODE *head, *end;
    create(23, &head, &end);
    display(&head);
    printf("Expected Result:\n23 <=> HEAD\n\n");
    insert_at_end(35, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> HEAD\n\n");
    insert_at_end(46, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 46 <=> HEAD\n\n");
    insert_at_end(58, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 46 <=> 58 <=> HEAD\n\n");
    insert_at(2, 61, &head, &end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 61 <=> 46 <=> 58 <=> HEAD\n\n");
    remove_from_end(&end);
    display(&head);
    printf("Expected Result:\n23 <=> 35 <=> 61 <=> 46 <=> HEAD\n\n");
    remove_from(0, &head, &end);
    display(&head);
    printf("Expected Result:\n35 <=> 61 <=> 46 <=> HEAD\n\n");
    remove_from_front(&head, &end);
    display(&head);
    printf("Expected Result:\n61 <=> 46 <=> HEAD\n\n");
    insert_at_front(29, &head, &end);
    display(&head);
    printf("Expected Result:\n29 <=> 61 <=> 46 <=> HEAD\n\n");
    display_reverse(&end);
    printf("Expected Result:\nHEAD <=> 46 <=> 61 <=> 29\n\n");
    remove_all(&head);
    return 0;
}