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
    NN->next = NN;
    return NN;
}

void insert_at_front(int val, NODE **head)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = *head;
    *head = NN;
    NODE *T = NN->next;
    do
    {
        T = T->next;
    } while (T->next != NN->next);
    T->next = *head;
}

void insert_at(int pos, int val, NODE **head)
{
    if (pos == 0)
    {
        insert_at_front(val, head);
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
    T->next = NN;
}

void insert_at_end(int val, NODE **head)
{
    NODE *T = *head;
    while (T->next != *head)
    {
        T = T->next;
    }
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->next = T->next;
    T->next = NN;
}

void remove_from_front(NODE **head)
{
    NODE *H = *head;
    *head = (*head)->next;
    NODE *T = *head;
    while (T->next != H)
    {
        T = T->next;
    }
    T->next = *head;
    free(H);
}

void remove_from(int pos, NODE **head)
{
    if (pos == 0)
    {
        remove_from_front(head);
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
    free(temp);
}

void remove_from_end(NODE **head)
{
    NODE *T = *head;
    while (T->next->next != *head)
    {
        T = T->next;
    }
    NODE *temp = T->next;
    T->next = temp->next;
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
        printf("%d -> ", T->data);
        T = T->next;
    } while (T != *head);
    printf("HEAD\n");
}

int main()
{
    NODE *head = create(23);
    display(&head);
    printf("Expected Result:\n23 -> HEAD\n\n");
    insert_at_end(35, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> HEAD\n\n");
    insert_at_end(46, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 46 -> HEAD\n\n");
    insert_at_end(58, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 46 -> 58 -> HEAD\n\n");
    insert_at(2, 61, &head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 61 -> 46 -> 58 -> HEAD\n\n");
    remove_from_end(&head);
    display(&head);
    printf("Expected Result:\n23 -> 35 -> 61 -> 46 -> HEAD\n\n");
    remove_from(0, &head);
    display(&head);
    printf("Expected Result:\n35 -> 61 -> 46 -> HEAD\n\n");
    remove_from_front(&head);
    display(&head);
    printf("Expected Result:\n61 -> 46 -> HEAD\n\n");
    insert_at_front(29, &head);
    display(&head);
    printf("Expected Result:\n29 -> 61 -> 46 -> HEAD\n\n");
    remove_all(&head);
    return 0;
}