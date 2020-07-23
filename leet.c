#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000
#define MIN -10000000
#define bool int
#define true 1
#define false 0
#define MAX_Q 100

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
    // initialize input and output
    int** ret = (int**)calloc(MAX_Q, sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_Q, sizeof(int));
    *returnSize = 0;

    Tree** queue = (Tree**)malloc(MAX_Q*sizeof(Tree*));
    int inInd = 0, outInd = 0;

    if(root == NULL)
        return NULL;
    queue[inInd++] = root;
    int levelcount = inInd - outInd;
    int count = 0;

    while(levelcount > 0){
        count++;
        ret[*returnSize] = (int*)calloc(levelcount, sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelcount;

        for(int i = 0; i < levelcount; i++){
            if(queue[outInd]->left != NULL){
                queue[inInd++] = queue[outInd]->left;
            }
            if(queue[outInd]->right != NULL){
                queue[inInd++] = queue[outInd]->right;
            }
            ret[*returnSize][i] = queue[outInd]->val;
            outInd++;
        }
        (*returnSize)++;
        levelcount = inInd - outInd;
    }
    return ret;
}

int main()
{
    int A[] = {3,9,0,0,20,15,0,0,7,0,0};
    int N1 = sizeof(A)/sizeof(A[0]);
    int ind1 = 0;
    Tree* T1 = createBT(A, &ind1, N1);

    int s = 0;
    int* size = &s;
    int* c = NULL;
    int** colsize = &c;
    int** la = levelOrder(T1, size, colsize);

    return 0;
}