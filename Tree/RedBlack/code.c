#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    DOUBLE_BLACK = -1,
    BLACK,
    RED
} Color;

typedef struct node
{
    int data;
    Color color;
    struct node *left, *right;
} NODE;

const NODE ghost = {0, DOUBLE_BLACK, NULL, NULL};

NODE *create(int val, Color color)
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    NN->data = val;
    NN->color = color;
    NN->left = NULL;
    NN->right = NULL;
    return NN;
}

NODE *right_rotate(NODE *z)
{
    NODE *y = z->left;

    NODE *temp = y->right;
    y->right = z;

    z->left = temp;
    return y;
}

NODE *left_rotate(NODE *x)
{
    NODE *y = x->right;

    NODE *temp = y->left;
    y->left = x;

    x->right = temp;
    return y;
}

int is_red(NODE *T)
{
    return T != NULL && T->color == RED;
}

void flip_color(NODE *T)
{
    if (T == NULL)
        return;
    T->color = T->color == BLACK ? RED : BLACK;
}

NODE *color_check(NODE *T)
{
    if (T == NULL)
        return NULL;

    int ll = is_red(T->left) && is_red(T->left->left);
    int lr = is_red(T->left) && is_red(T->left->right);
    int rr = is_red(T->right) && is_red(T->right->right);
    int rl = is_red(T->right) && is_red(T->right->left);

    if (ll || lr)
    {
        if (is_red(T->right))
        {
            T->right->color = BLACK;
            T->left->color = BLACK;
            flip_color(T);
        }
        else
        {
            if (lr)
                T->left = left_rotate(T->left);
            T = right_rotate(T);
            flip_color(T);
            flip_color(T->right);
        }
    }
    else if (rr || rl)
    {
        if (is_red(T->left))
        {
            T->right->color = BLACK;
            T->left->color = BLACK;
            flip_color(T);
        }
        else
        {
            if (rl)
                T->right = right_rotate(T->right);
            T = left_rotate(T);
            flip_color(T);
            flip_color(T->left);
        }
    }
    return T;
}

NODE *insert_recursive(int val, NODE *n)
{
    if (n == NULL)
        return create(val, RED);
    else if (val < n->data)
        n->left = insert_recursive(val, n->left);
    else if (val > n->data)
        n->right = insert_recursive(val, n->right);

    return color_check(n);
}

NODE *insert(int val, NODE *n)
{
    if (n == NULL)
        return create(val, BLACK);
    insert_recursive(val, n);
    n->color = BLACK;
    return n;
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

NODE *fix_black(NODE *n)
{
    if (n == NULL)
        return NULL;

    int l_db = n->left != NULL && n->left->color == DOUBLE_BLACK;
    int r_db = n->right != NULL && n->right->color == DOUBLE_BLACK;
    if (!(l_db || r_db))
        return n;
    NODE **db_ptr = l_db ? &n->left : &n->right;
    NODE *sibling = l_db ? n->right : n->left;
    NODE *near, *far;
    if (sibling == NULL)
    {
        near = NULL;
        far = NULL;
    }
    else
    {
        near = l_db ? sibling->left : sibling->right;
        far = l_db ? sibling->right : sibling->left;
    }

    int sibling_red = is_red(sibling);
    int near_red = is_red(near);
    int far_red = is_red(far);

    if (sibling_red)
    {
        Color temp = sibling->color;
        sibling->color = n->color;
        n->color = temp;
        if (l_db)
        {
            n = left_rotate(n);
            n->left = fix_black(n->left);
        }
        else
        {
            n = right_rotate(n);
            n->right = fix_black(n->right);
        }
        return n;
    }
    if (!near_red && !far_red)
    {
        if (sibling != NULL)
            sibling->color = RED;
        if (*db_ptr == (NODE *)&ghost)
            *db_ptr = NULL;
        else
            (*db_ptr)->color = BLACK;
        n->color = n->color == RED ? BLACK : DOUBLE_BLACK;
        return n;
    }
    if (near_red && !far_red)
    {
        if (sibling != NULL)
            sibling->color = RED;
        near->color = BLACK;
        if (l_db)
            n->left = right_rotate(n->left);
        else
            n->right = left_rotate(n->right);
        sibling = l_db ? n->left : n->right;
        near = l_db ? sibling->left : sibling->right;
        far = l_db ? sibling->right : sibling->left;
        near_red = is_red(near);
        far_red = is_red(far);
    }
    if (far_red)
    {
        Color temp = sibling != NULL ? sibling->color : BLACK;
        if (sibling != NULL)
            sibling->color = n->color;
        n->color = temp;
        if (l_db)
            n = left_rotate(n);
        else
            n = right_rotate(n);
        sibling = l_db ? n->right : n->left;
        sibling->color = BLACK;
        if (*db_ptr == (NODE *)&ghost)
            *db_ptr = NULL;
        else
            (*db_ptr)->color = BLACK;
        return n;
    }
}

NODE *delete_recursive(int val, NODE *n)
{
    if (n == NULL)
        return NULL;
    if (val == n->data)
    {
        if (n->left == NULL && n->right == NULL)
        {
            NODE *temp = n;
            if (temp->color == BLACK)
                n = (NODE *)&ghost;
            else
                n = NULL;
            free(temp);
            return n;
        }
        else if (n->left != NULL && n->right == NULL)
        {
            NODE *temp = n->left;
            n->data = temp->data;
            n->left = NULL;
            free(temp);
            return n;
        }
        else if (n->left == NULL && n->right != NULL)
        {
            NODE *temp = n->right;
            n->data = temp->data;
            n->right = NULL;
            free(temp);
            return n;
        }
        else if (n->left != NULL && n->right != NULL)
        {
            NODE *T = find_min(n->right);
            n->data = T->data;
            n->right = delete_recursive(T->data, n->right);
            return n;
        }
    }
    if (val < n->data)
    {
        n->left = delete_recursive(val, n->left);
        n->left = fix_black(n->left);
    }
    else
    {
        n->right = delete_recursive(val, n->right);
        n->right = fix_black(n->right);
    }

    return n;
}

NODE *delete_node(int val, NODE *n)
{
    n = delete_recursive(val, n);
    if (n != NULL)
        n->color = BLACK;
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

Color validate_color(NODE *n)
{
    if (n == NULL)
        return BLACK;
    Color l = validate_color(n->left);
    Color r = validate_color(n->right);
    if (n->color == RED && l == RED)
        printf("Red-Red Color combo at %d <- %d\n", n->left->data, n->data);
    else if (n->color == RED && r == RED)
        printf("Red-Red Color combo at %d -> %d\n", n->data, n->right->data);
    printf("Valid Color of Node %d\n", n->data);
}

int validate_black_height(NODE *n, int *is_valid)
{
    if (n == NULL)
        return 0;
    int l = validate_black_height(n->left, is_valid) + (n->color == BLACK);
    int r = validate_black_height(n->right, is_valid) + (n->color == BLACK);
    if (l != r)
    {
        *is_valid = 0;
        printf("Black height mismatch at node %d\n", n->data);
    }
    return l + (n->color == BLACK);
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
    validate_color(root);
    printf("------ Black Height Validation ------\n");
    int is_valid = 1;
    validate_black_height(root, &is_valid);
    if (is_valid)
        printf("Black Height consistent accorss all paths\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(3, root);
    display_inorder(root);
    printf("\nExpected:\n0 1 2 5 7 8 9\n");
    printf("-----------------------------\n");
    validate_color(root);
    printf("------ Black Height Validation ------\n");
    is_valid = 1;
    validate_black_height(root, &is_valid);
    if (is_valid)
        printf("Black Height consistent accorss all paths\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(5, root);
    display_inorder(root);
    printf("\nExpected:\n0 1 2 7 8 9\n");
    printf("-----------------------------\n");
    validate_color(root);
    printf("------ Black Height Validation ------\n");
    is_valid = 1;
    validate_black_height(root, &is_valid);
    if (is_valid)
        printf("Black Height consistent accorss all paths\n");
    printf("-----------------------------\n");
    printf("------ Delete ------\n");
    root = delete_node(8, root);
    display_inorder(root);
    printf("\nExpected:\n0 1 2 7 9\n");
    printf("-----------------------------\n");
    validate_color(root);
    printf("------ Black Height Validation ------\n");
    is_valid = 1;
    validate_black_height(root, &is_valid);
    if (is_valid)
        printf("Black Height consistent accorss all paths\n");
    printf("-----------------------------\n");
    free_all(root);
    return 0;
}