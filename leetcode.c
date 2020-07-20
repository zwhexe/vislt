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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{

}

int main()
{
    int A[] = {3,9,0,0,20,15,0,0,7,0,0};
    int N1 = sizeof(A)/sizeof(A[0]);
    int ind1 = 0;
    Tree* T1 = createBT(A, &ind1, N1);

    return 0;   
}