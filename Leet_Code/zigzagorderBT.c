#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000
#define MIN -10000000
#define bool int
#define true 1
#define false 0
#define MAX_Q 100

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

void inorderTravel(Tree *T)
{
    if(T){
        inorderTravel(T->left);
        printf("%d ", T->val);
        inorderTravel(T->right);
    }
    return;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    // initialize input and output
    int** ret = (int**)calloc(MAX_Q, sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_Q, sizeof(int));
    *returnSize = 0;

    Tree** queue = (Tree**)malloc(MAX_Q*10*sizeof(Tree*));
    int levelcount = 0;
    int i = 0, j = 0, k = 0;
    if(root == NULL)
        return NULL;
    queue[j++] = root;
    levelcount = j - i;
    // *returnSize is level number
    while(levelcount > 0){
        ret[*returnSize] = (int*)calloc(levelcount, sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelcount;
        if((*returnSize)%2 == 0){
            for(k = 0; k < levelcount; k++){
                if(queue[i]->left)
                    queue[j++] = queue[i]->left;
                if(queue[i]->right)
                    queue[j++] = queue[i]->right;
                ret[*returnSize][k] = queue[i++]->val;
            }
        }
        else{
            for(k = levelcount-1; k >= 0; k--){
                if(queue[i]->left)
                    queue[j++] = queue[i]->left;
                if(queue[i]->right)
                    queue[j++] = queue[i]->right;
                ret[*returnSize][k] = queue[i++]->val;
            }
        }
        (*returnSize)++;
        levelcount = j - i;
    }
    return ret;
}

int main()
{
    int A[] = {3,9,10,0,0,0,20,15,0,0,7,0,0};
    int N1 = sizeof(A)/sizeof(A[0]);
    int ind1 = 0;
    Tree* T1 = createBT(A, &ind1, N1);

    int s = 0;
    int* size = &s;
    int* c = NULL;
    int** colsize = &c;
    int** ret = levelOrder(T1, size, colsize);

    return 0;
}