#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000
#define MIN -10000000
#define bool int
#define true 1
#define false 0

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode Tree;

Tree* createBT(int *A, int *ind, int N)
{
    if((*ind) >= N || A[*ind] <= 0)
        return NULL;
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->val = A[*ind]; t->left = t->right = NULL;

    (*ind)++;
    t->left = createBT(A, ind, N);
    (*ind)++;
    t->right = createBT(A, ind, N);
    return t;
}

void inorderTravel(Tree *T)
{
    if(T){
        inorderTravel(T->left);
        printf("%d ", T->val);
        inorderTravel(T->right);
    }
    return;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    int A[] = {1,2,0,0,3,0,0};
    int B[] = {1,2,0,0,3,0,0};
    int N1 = sizeof(A)/sizeof(A[0]);
    int N2 = sizeof(B)/sizeof(B[0]);
    int ind1 = 0, ind2 = 0;
    Tree* T1 = createBT(A, &ind1, N1);
    Tree* T2 = createBT(B, &ind2, N2);
    bool ans = isSameTree(T1, T2);
    printf("%d\n", ans);

    return 0;   
}