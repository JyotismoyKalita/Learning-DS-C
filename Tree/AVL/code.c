#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int height;
    struct node *left, *right;
} NODE;

NODE *create(int val)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->height = 0;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

int update_height(NODE *n)
{
    if (n == NULL)
        return 0;
    int height_l = n->left != NULL ? n->left->height + 1 : 0;
    int height_r = n->right != NULL ? n->right->height + 1 : 0;
    n->height = height_l > height_r ? height_l : height_r;
    int bf = height_l - height_r;
    return bf;
}

int get_balance(NODE *n)
{
    if (n == NULL)
        return 0;
    int height_l = n->left != NULL ? n->left->height : 0;
    int height_r = n->right != NULL ? n->right->height : 0;
    return height_l - height_r;
}

NODE *right_rotate(NODE *z)
{
    NODE *y = z->left;

    NODE *temp = y->right;
    y->right = z;

    z->left = temp;
    update_height(z);
    update_height(y);
    return y;
}

NODE *left_rotate(NODE *x)
{
    NODE *y = x->right;

    NODE *temp = y->left;
    y->left = x;

    x->right = temp;
    update_height(x);
    update_height(y);
    return y;
}

NODE *balance_nodes(int val, int bf, NODE *n)
{
    if (bf > 1)
    {
        int lbf = get_balance(n->left);
        if (lbf >= 0)
            return right_rotate(n);
        else
        {
            n->left = left_rotate(n->left);
            return right_rotate(n);
        }
    }
    else if (bf < -1)
    {
        int rbf = get_balance(n->right);
        if (rbf <= 0)
            return left_rotate(n);
        else
        {
            n->right = right_rotate(n->right);
            return left_rotate(n);
        }
    }
    return n;
}

NODE *insert(int val, NODE *n)
{
    if (n == NULL)
    {
        n = create(val);
        return n;
    }
    else if (val < n->data)
    {
        n->left = insert(val, n->left);
    }
    else if (val > n->data)
    {
        n->right = insert(val, n->right);
    }

    int bf = update_height(n);

    return balance_nodes(val, bf, n);
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
    else
        return n;
}

NODE *find_max(NODE *n)
{
    if (n == NULL)
        return NULL;
    if (n->right != NULL)
        return find_max(n->right);
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
    int bf = update_height(n);
    return balance_nodes(val, bf, n);
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
    root = insert(0, root);
    printf("------ Inorder Display ------\n");
    display_inorder(root);
    printf("\nExpected:\n0 1 2 3 5 7 8 9\n");
    printf("------ Left of 5 ------\n");
    printf("%d <- 5\n", root->left->data);
    printf("Expected:\n2 <- 5\n");
    printf("-----------------------------\n");
    printf("------ Height ------\n");
    printf("Height: %d\n", root->height);
    printf("Expected: 3\n");
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
    printf("Expected: 0\n");
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
    root = delete_node(3, root);
    display_inorder(root);
    printf("\nExpected:\n0 1 2 5 7 8 9\n");
    printf("Left of 5 = %d\n", root->left->data);
    printf("Expected:\nLeft of 5 = 1\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(5, root);
    display_inorder(root);
    printf("\nExpected:\n0 1 2 7 8 9\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(8, root);
    display_inorder(root);
    printf("\nExpected:\n0 1 2 7 9\n");
    printf("-----------------------------\n");
    root = insert(3, root);
    printf("------ Inorder Display ------\n");
    display_inorder(root);
    printf("\nExpected:\n0 1 2 3 7 9\n");
    printf("------ Left -> Root -> Right ------\n");
    printf("%d <- %d -> %d\n", root->left->data, root->data, root->right->data);
    printf("Expected:\n1 <- 2 -> 7\n");
    printf("------ Left of 7 ------\n");
    printf("%d <- %d\n", root->right->left->data, root->right->data);
    printf("Expected:\n3 <- 7\n");
    printf("-----------------------------\n");
    free_all(root);
    return 0;
}