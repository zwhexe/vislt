#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode Tree;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorderTree(Tree* T)
{
    while(T!=NULL){
        printf("%d ", T->val);
        preorderTree(T->left);
        preorderTree(T->right);
    }
    printf("\n");
}

Tree* insertNode(Tree* t, int val)
{
    if(t==NULL){
        t = (Tree*)malloc(sizeof(Tree));
        t->val = val;
        t->left = NULL;
        t->right = NULL;
    }
    else if(val < t->val){
        t-> left = insertNode(t->left, val);
    }
    else if(val > t->val){
        t->right = insertNode(t->right, val);
    }
    return t;
}

void copyNode(Tree* t, Tree* nt)
{
    if(t != NULL){
        nt->val = t->val;
        if(t->left != NULL){
            nt->left = (Tree*)malloc(sizeof(Tree));
            nt->left->left = NULL; nt->left->right = NULL;
            copyNode(t->left, nt->left);
        }
        if(t->right != NULL){
            nt->right = (Tree*)malloc(sizeof(Tree));
            nt->right->left = NULL; nt->right->right = NULL;
            copyNode(t->right, nt->right);
        }
    }
}

void copyTree(Tree** A, int* returnSize)
{
    // extend A size, and copy last tree in A
    (*returnSize)++;
    A = (Tree**)realloc(A, (*returnSize)*sizeof(Tree*));

    A[*returnSize-1] = (Tree*)malloc(sizeof(Tree));
    A[*returnSize-1]->left = A[*returnSize-1]->right = NULL;
    copyNode(A[*returnSize-2], A[*returnSize-1]);
}

void subTrees(Tree** A, int m, int n, int *returnSize)
{
    A[*returnSize-1] = insertNode(A[*returnSize-1], m);
    for(int i = m+1; i <= n; i++){
        copyTree(A, returnSize);
        if(i-1>=m)
            subTrees(A, m, i-1, returnSize);
        if(i+1<=n)
            subTrees(A, i+1, n, returnSize);
    }

}

struct TreeNode** generateTrees(int n, int* returnSize)
{
    Tree** A = NULL;
 
    for(int i = 1; i <= n; i++){
        // loop every i as the top of tree
        (*returnSize)++;
        A = (Tree**)realloc(A, (*returnSize)*sizeof(Tree*));
        A[*returnSize-1]->val = i;
        A[*returnSize-1]->left = A[*returnSize-1]->right = NULL;

        if(i-1>=1)
            subTrees(A, 1, i-1, returnSize);
        if(i+1<=n)
            subTrees(A, i+1, n, returnSize);
    }
    
    return A;
}


int main()
{
    int n = 3;
    int s = 0;
    Tree** A = generateTrees(n, &s);

    for(int i = 0; i < s; i++){
        preorderTree(A[i]);
    }

    return 0;
}