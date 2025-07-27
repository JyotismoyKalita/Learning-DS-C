#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

typedef struct qnode
{
    NODE *tnode;
    struct qnode *next;
} QNODE;

typedef struct
{
    QNODE *front;
    QNODE *rear;
} QUEUE;

void q_init(QUEUE *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void q_insert(QUEUE *q, NODE *t)
{
    if (t == NULL)
        return;
    QNODE *QN = (QNODE *)malloc(sizeof(QNODE));
    QN->tnode = t;
    QN->next = NULL;
    if (q->front == NULL)
    {
        q->front = QN;
        q->rear = QN;
        return;
    }
    q->rear->next = QN;
    q->rear = QN;
}

NODE *q_remove(QUEUE *q)
{
    if (q->front == NULL)
    {
        printf("Queue Empty\n");
        return NULL;
    }
    QNODE *temp = q->front;
    NODE *n = temp->tnode;
    q->front = q->front->next;
    free(temp);
    return n;
}

void *q_remove_all(QUEUE *q)
{
    if (q->front == NULL)
    {
        printf("Queue Empty\n");
        return NULL;
    }
    while (q->front != NULL)
    {
        QNODE *qn = q->front;
        q->front = q->front->next;
        free(qn);
    }
    q->rear = NULL;
}

NODE *create()
{
    NODE *NN = (NODE *)malloc(sizeof(NODE));
    int temp;
    printf("Enter Value: ");
    scanf("%d", &temp);
    NN->data = temp;

    printf("Insert Child Nodes to %d?\n0 = No, 1 = Left Only, 2 = Right Only, 3 = Left and Right: ", NN->data);
    scanf("%d", &temp);

    if (temp == 0)
    {
        NN->left = NULL;
        NN->right = NULL;
        return NN;
    }
    if (temp == 1 || temp == 3)
    {
        printf("Left of NODE valued %d: ", NN->data);
        NN->left = create(NN);
        if (temp == 1)
            NN->right = NULL;
    }
    if (temp == 2 || temp == 3)
    {
        printf("Right of NODE valued %d: ", NN->data);
        NN->right = create(NN);
        if (temp == 2)
            NN->left = NULL;
    }

    return NN;
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

void display_preorder(NODE *n)
{
    if (n == NULL)
    {
        return;
    }
    printf("%d ", n->data);
    display_preorder(n->left);
    display_preorder(n->right);
}

void display_postorder(NODE *n)
{
    if (n == NULL)
    {
        return;
    }
    display_postorder(n->left);
    display_postorder(n->right);
    printf("%d ", n->data);
}

void display_levelorder(QUEUE *q, NODE *n)
{
    q_insert(q, n);
    while (q->front != NULL)
    {
        NODE *t = q_remove(q);
        printf("%d ", t->data);
        q_insert(q, t->left);
        q_insert(q, t->right);
    }
}

int count_nodes(NODE *n)
{
    if (n == NULL)
        return 0;
    int count_l = count_nodes(n->left);
    int count_r = count_nodes(n->right);
    return count_l + count_r + 1;
}

int count_leaf(NODE *n)
{
    if (n == NULL)
        return 0;
    if (n->right == NULL && n->left == NULL)
        return 1;
    int count_l = count_leaf(n->left);
    int count_r = count_leaf(n->right);
    return count_l + count_r;
}

int count_internal(NODE *n)
{
    if (n == NULL)
        return 0;
    if (n->right == NULL && n->left == NULL)
        return 0;
    int count_l = count_internal(n->left);
    int count_r = count_internal(n->right);
    return count_l + count_r + 1;
}

int count_height(NODE *n)
{
    if (n == NULL)
        return 0;
    if (n->right == NULL && n->left == NULL)
        return 0;
    int count_l = count_height(n->left);
    int count_r = count_height(n->right);
    if (count_l > count_r)
        return count_l + 1;
    return count_r + 1;
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
    NODE *root = create();
    QUEUE q;
    q_init(&q);
    printf("Inorder\n");
    display_inorder(root);
    printf("\n");
    printf("Pre-order\n");
    display_preorder(root);
    printf("\n");
    printf("Post-order\n");
    display_postorder(root);
    printf("\n");
    printf("Level-order\n");
    display_levelorder(&q, root);
    printf("\n");
    int count_n = count_nodes(root);
    printf("Count Nodes: %d\n", count_n);
    int count_l = count_leaf(root);
    printf("Count Leaves: %d\n", count_l);
    int count_i = count_internal(root);
    printf("Count Internal: %d\n", count_i);
    int count_h = count_height(root);
    printf("Count Height: %d\n", count_h);
    q_remove_all(&q);
    free_all(root);
    return 0;
}