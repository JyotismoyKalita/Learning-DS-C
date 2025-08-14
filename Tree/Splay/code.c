#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;

NODE *create(int val)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

NODE *zig(NODE *z)
{
    NODE *y = z->left;

    NODE *temp = y->right;
    y->right = z;

    z->left = temp;
    return y;
}

NODE *zag(NODE *x)
{
    NODE *y = x->right;

    NODE *temp = y->left;
    y->left = x;

    x->right = temp;
    return y;
}

NODE *splay(int val, NODE *n)
{
    if (n == NULL)
        return n;
    if (val < n->data)
    {
        n->left = splay(val, n->left);
        if (n->left == NULL)
            return n;
        if (val < n->left->data && n->left->left != NULL)
        {
            n = zig(n);
            n = zig(n);
        }
        else if (val > n->left->data && n->left->right != NULL)
        {
            n->left = zag(n->left);
            n = zig(n);
        }
    }
    else if (val > n->data)
    {
        n->right = splay(val, n->right);
        if (n->right == NULL)
            return n;
        if (val > n->right->data && n->right->right != NULL)
        {
            n = zag(n);
            n = zag(n);
        }
        else if (val < n->right->data && n->right->left != NULL)
        {
            n->right = zig(n->right);
            n = zag(n);
        }
    }
    return n;
}

NODE *splay_wrapper(int val, NODE *n)
{
    if (n == NULL || val == n->data)
        return n;
    if (n->left == NULL && n->right == NULL)
        return n;
    n = splay(val, n);
    if (val < n->data)
    {
        if (n->left != NULL && val == n->left->data)
            n = zig(n);
        else if (n->left != NULL && val < n->left->data && n->left->left == NULL)
            n = zig(n);
        else if (n->left != NULL && val > n->left->data && n->left->right == NULL)
            n = zig(n);
    }
    else if (val > n->data)
    {
        if (n->right != NULL && val == n->right->data)
            n = zag(n);
        else if (n->right != NULL && val < n->right->data && n->right->left == NULL)
            n = zag(n);
        else if (n->right != NULL && val > n->right->data && n->right->right == NULL)
            n = zag(n);
    }
    return n;
}

NODE *insert(int val, NODE *n)
{
    if (n == NULL)
    {
        NODE *NN = create(val);
        return NN;
    }
    n = splay_wrapper(val, n);
    if (n->data == val)
        return n;
    NODE *NN = create(val);
    if (val < n->data)
    {
        NN->right = n;
        NN->left = n->left;
        n->left = NULL;
    }
    else if (val > n->data)
    {
        NN->left = n;
        NN->right = n->right;
        n->right = NULL;
    }
    n = NN;
    return n;
}

NODE *delete_node(int val, NODE *n)
{
    if (n == NULL)
        return NULL;

    n = splay_wrapper(val, n);
    if (n->data != val)
        return n;
    if (n->left == NULL && n->right == NULL)
    {
        free(n);
        return NULL;
    }
    if (n->left == NULL)
    {
        NODE *T = n;
        n = n->right;
        free(T);
        return n;
    }
    else if (n->right == NULL)
    {
        NODE *T = n;
        n = n->left;
        free(T);
        return n;
    }
    else
    {
        NODE *T = n;
        NODE *L = n->left;
        NODE *R = n->right;
        L = splay_wrapper(val, L);
        L->right = R;
        free(T);
        n = L;
        return n;
    }
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
    root = insert(5, root);
    root = insert(3, root);
    root = insert(8, root);
    root = insert(2, root);
    root = insert(7, root);
    root = insert(1, root);
    root = insert(9, root);
    printf("------ Inorder Display ------\n");
    display_inorder(root);
    printf("\nExpected:\n1 2 3 5 7 8 9\n");
    printf("-----------------------------\n");
    printf("------ Search ------\n");
    root = splay_wrapper(8, root);
    if (root->data != 8)
    {
        printf("Not found\n");
    }
    else
        printf("Found: %d\n", root->data);
    printf("Expected: 8\n");
    printf("-----------------------------\n");
    printf("------ Search ------\n");
    root = splay_wrapper(12, root);
    if (root->data != 12)
    {
        printf("Not found\n");
    }
    else
        printf("Found: %d\n", root->data);
    printf("Expected: Not found\n");
    printf("-----------------------------\n");
    printf("------ Search ------\n");
    root = splay_wrapper(9, root);
    if (root->data != 9)
    {
        printf("Not found\n");
    }
    else
        printf("Found: %d\n", root->data);
    printf("Expected: 9\n");
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