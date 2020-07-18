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

void inorderRecord(Tree* t, Tree* p, Tree** max, Tree** min)
{
    if(t != NULL){
        inorderRecord(t->left, t, max, min);
        if(p && p->val > t->val){
            if((*max)==NULL || (*min)==NULL){
                *max = p;
                *min = t;
            }
            else{
                *min = t;
            }
        }
        inorderRecord(t->right, t, max, min);
    }
}

void recoverTree(struct TreeNode *root)
{
    if(root==NULL)
        return;
    Tree* errMax = NULL;
    Tree* errMin = NULL;
    Tree* pre = NULL;
    inorderRecord(root, pre, &errMax, &errMin);
    int tmp = errMax->val;
    errMax->val = errMin->val;
    errMin->val = tmp;
}

int main()
{
    int A[] = {3,1,0,0,4,2,0,0,0};
    int N = sizeof(A)/sizeof(A[0]);
    int ind = 0;
    Tree* T = createBT(A, &ind, N);
    inorderTravel(T); printf("\n");
    recoverTree(T);
    inorderTravel(T);
    recoverTree(T);

    return 0;   
}