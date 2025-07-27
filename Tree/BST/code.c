#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;

NODE *create(int val)
{
    NODE *NN = (NODE *)malloc(sizeof(NN));
    NN->data = val;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

void insert(int val, NODE **n)
{
    if ((*n) == NULL)
    {
        (*n) = create(val);
        return;
    }
    if (val == (*n)->data)
        return;
    if (val < (*n)->data)
    {
        if ((*n)->left == NULL)
            (*n)->left = create(val);
        else
            insert(val, &((*n)->left));
    }
    else if (val > (*n)->data)
    {
        if ((*n)->right == NULL)
            (*n)->right = create(val);
        else
            insert(val, &((*n)->right));
    }
}

NODE *search(int val, NODE *n)
{
    if (n == NULL)
        return NULL;
    if (val == n->data)
        return n;
    else if (val < n->data)
        return search(val, n->left);
    else if (val > n->data)
        return search(val, n->right);
    return NULL;
}

NODE *find_min(NODE *n)
{
    if (n == NULL)
        return NULL;
    if (n->left != NULL)
        return find_min(n->left);
    else if (n->right != NULL)
        return find_min(n->right);
    else
        return n;
}

NODE *find_max(NODE *n)
{
    if (n == NULL)
        return NULL;
    if (n->right != NULL)
        return find_max(n->right);
    else if (n->left != NULL)
        return find_max(n->left);
    else
        return n;
}

NODE *delete_node(int val, NODE *n)
{
    if (n == NULL)
        return NULL;
    if (val == n->data)
    {
        if (n->left == NULL && n->right == NULL)
        {
            free(n);
            return NULL;
        }
        else if (n->left != NULL && n->right == NULL)
        {
            NODE *temp = n->left;
            free(n);
            return temp;
        }
        else if (n->left == NULL && n->right != NULL)
        {
            NODE *temp = n->right;
            free(n);
            return temp;
        }
        else if (n->left != NULL && n->right != NULL)
        {
            NODE *T = find_min(n->right);
            n->data = T->data;
            n->right = delete_node(T->data, n->right);
            return n;
        }
    }
    if (val < n->data)
        n->left = delete_node(val, n->left);
    else
        n->right = delete_node(val, n->right);
    return n;
}

void display_inorder(NODE *n)
{
    if (n == NULL)
    {
        return;
    }
    display_inorder(n->left);
    printf("%d ", n->data);
    display_inorder(n->right);
}

void free_all(NODE *n)
{
    if (n == NULL)
    {
        return;
    }
    free_all(n->left);
    free_all(n->right);
    free(n);
}

int main()
{
    NODE *root = NULL;
    insert(5, &root);
    insert(3, &root);
    insert(8, &root);
    insert(2, &root);
    insert(7, &root);
    insert(1, &root);
    insert(9, &root);
    printf("------ Inorder Display ------\n");
    display_inorder(root);
    printf("\nExpected:\n1 2 3 5 7 8 9\n");
    printf("-----------------------------\n");
    printf("------ Search ------\n");
    NODE *temp = search(8, root);
    if (temp == NULL)
    {
        printf("Not found\n");
    }
    else
        printf("Found: %d\n", temp->data);
    printf("Expected: 8\n");
    temp = NULL;
    printf("-----------------------------\n");
    printf("------ Search ------\n");
    temp = search(12, root);
    if (temp == NULL)
    {
        printf("Not found\n");
    }
    else
        printf("Found: %d\n", temp->data);
    printf("Expected: Not found\n");
    temp = NULL;
    printf("-----------------------------\n");
    printf("------ MIN ------\n");
    temp = find_min(root);
    if (temp == NULL)
    {
        printf("Not found\n");
    }
    else
        printf("MIN: %d\n", temp->data);
    printf("Expected: 1\n");
    temp = NULL;
    printf("-----------------------------\n");
    printf("------ MAX------\n");
    temp = find_max(root);
    if (temp == NULL)
    {
        printf("Not found\n");
    }
    else
        printf("MAX: %d\n", temp->data);
    printf("Expected: 9\n");
    temp = NULL;
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(5, root);
    display_inorder(root);
    printf("\nExpected:\n1 2 3 7 8 9\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(8, root);
    display_inorder(root);
    printf("\nExpected:\n1 2 3 7 9\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(1, root);
    display_inorder(root);
    printf("\nExpected:\n2 3 7 9\n");
    printf("-----------------------------\n");
    free_all(root);
    return 0;
}