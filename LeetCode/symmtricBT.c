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

bool compareTree(Tree* t1, Tree* t2)
{
    if(t1 && t2 && t1->val != t2->val){
        return false;
    }
    else if(t1 && t2==NULL){
        return false;
    }
    else if(t2 && t1==NULL){
        return false;
    }
    else if(t1 && t2 && t1->val==t2->val){
        bool tt = true;
        return tt && compareTree(t1->left, t2->right) && compareTree(t1->right, t2->left);
    }
    
    return true;
}

bool isSymmetric(struct TreeNode* root)
{
    if(root==NULL)
        return true;
    bool sym = compareTree(root->left, root->right);
    return sym;
}

int main()
{
    int A[] = {1,2,3,0,0,4,0,0,2,4,0,0,3,0,0};
    int B[] = {1,2,0,3,0,0,2,0,3,0,0};
    int N1 = sizeof(A)/sizeof(A[0]);
    int N2 = sizeof(B)/sizeof(B[0]);
    int ind1 = 0, ind2 = 0;
    Tree* T1 = createBT(A, &ind1, N1);
    Tree* T2 = createBT(B, &ind2, N2);
    bool S1 = isSymmetric(T1);
    bool S2 = isSymmetric(T2);
    printf("%d\n", S1);
    printf("%d\n", S2);

    return 0;   
}