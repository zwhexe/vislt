#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode Tree;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void copyNode(Tree* t, Tree* nt)
{
    if(t != NULL){
        nt->val = t->val;
        if(t->left != NULL){
            nt->left = (Tree*)malloc(sizeof(Tree));
            nt->left->left = NULL; nt->left->right = NULL;
            copy(t->left, nt->left);
        }
        if(t->right != NULL){
            nt->right = (Tree*)malloc(sizeof(Tree));
            nt->right->left = NULL; nt->right->right = NULL;
            copy(t->right, nt->right);
        }
    }
}

Tree* copyTree(Tree* t)
{
    Tree* nt = (Tree*)malloc(sizeof(Tree));
    nt->left = NULL; nt->right = NULL;
    copy(t, nt);
    return nt;
}

void subTrees(int *a, int i, int j, int *returnSize)
{
    if(i == j)
        *returnSize++;
    else{

    }
}

struct TreeNode** generateTrees(int n, int* returnSize)
{
    int* a = (int*)malloc(n*sizeof(int));
    for(int i = 1; i <= n; i++)
        *(a+i) = i;

    int sum = 0; //create list to store trees
    Tree** A = NULL;

    for(int i = 1; i <= n; i++){
        // loop every i as the top of tree
        Tree* t = (Tree*)malloc(sizeof(Tree));
        t->val = i;
        t->left = NULL;
        t->right = NULL;

        sum++;
        A = (Tree**)realloc(A, sizeof(Tree*));


        if(i-1>=0)
            subTrees(a, 0, i-1, &returnSize);
        if(i+1<=n-1)
            subTrees(a, i+1, n-1, &returnSize);
    }

}


int main()
{
    int n = 3;
    int s = 0;
    Tree** A = generateTrees(n, &s);

    return 0;
}