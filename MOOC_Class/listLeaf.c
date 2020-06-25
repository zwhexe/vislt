#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct Tree Node;
struct Tree {
    int indice;
    Node* left;
    Node* right;
};

typedef struct QList {
    Node* node;
    struct QList* next;
} Queue;

Node* BuildTree()
{
    int i, j;
    int N;
    printf("Input nodes number: ");
    scanf("%d", &N);
    if (N <= 0)
        return NULL;

    int check[MaxSize];
    for (j = 0; j < MaxSize; j++)
        check[j] = 0;
    Node* T = (Node*)malloc(N * (sizeof(struct Tree)));
    for (i = 0; i < N; i++)
    {
        char cl, cr;
        printf("Node %d: ", i);
        (T + i)->indice = i;
        scanf("\n%c", &cl);
        scanf(" %c", &cr);
        if (cl != '-') {
            int l = cl - '0';
            (T + i)->left = (T + l);
            check[l] = 1;
        }
        else {
            (T + i)->left = NULL;
        }
        if (cr != '-') {
            int r = cr - '0';
            (T + i)->right = (T + r);
            check[r] = 1;
        }
        else {
            (T + i)->right = NULL;
        }
    }

    for (j = 0; j < N; j++)
        if (check[j] == 0) break;
    return (T+j);
}

void AddQueue(Queue** list, Node* p)
{
    if (*list == NULL) {
        Queue* q = (Queue*)malloc(sizeof(struct QList));
        q->node = p;
        q->next = NULL;
        *list = q;

    }
    else {
        Queue* q = (Queue*)malloc(sizeof(struct QList));
        q->node = p;
        q->next = NULL;
        Queue* tmp = *list;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = q;
        tmp = q;
    }
}

Node* PopQueue(Queue** list)
{
    if (*list == NULL)
        return NULL;
    else {
        Node* p = (*list)->node;
        Queue* q = *list;
        *list = (*list)->next;
        free(q);
        return p;
    }
}

void findLeaf(Node* p)
{
    if (!p) return;
    Queue* head = NULL;
    Node* t = NULL;
/* In order to change pointer address in func, 
    we have also to pass pointer reference to func */
    AddQueue(&head, p); 
    while (head) {
        t = PopQueue(&head);
        if (!t->left && !t->right) {
            printf("%d ", t->indice);
        }
        if (t->left) {
            AddQueue(&head, t->left);
        }
        if (t->right) {
            AddQueue(&head, t->right);
        }
    }
}

int main()
{
    Node* root = BuildTree();
    printf("root is: %d\n", root->indice);
    findLeaf(root);

    return 0;
}