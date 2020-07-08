#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define bool int
#define true 1
#define false 0

typedef struct TreeNode Tree;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

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

int inOrder(Tree* t, int* ans)
{
    int l = -MAX;
    int r = MAX;

    if(t->left && *ans != 0)
        l = inOrder(t->left, ans);

    if(t->val <= l)
        *ans = 0;

    if(t->right && *ans != 0)
        r = inOrder(t->right, ans);
    
    if(t->val >= r)
        *ans = 0;
    
    return t->val;
}

bool isValidBST(struct TreeNode* root)
{
    int ans = 1;
    if(root == NULL)
        return true;
    int v = inOrder(root, &ans);
    
    if(ans == 0)
        return false;
    else
        return true;
}

int main()
{
    //int A[] = {5, 1, 0, 0, 4, 3, 0, 0, 6, 0, 0};
    int A[] = {10,5,0,0,15,6,0,0,20,0,0};
    int M = sizeof(A)/sizeof(A[0]);
    int ind = 0;
    Tree* T1 = createBT(A, &ind, M);
    bool a1 = isValidBST(T1);
    printf("%d\n", a1);

    return 0;   
}