#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode Tree;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int recursiveGenerateTree(Tree*** pRet, int iStart, int iEnd)
{
    int iCur = 0;
    int i = 0;
    int j = 0;
    int iRetNum = 0;
    int iMaxNum = 2000;
    int iLeftNum = 0;
    int iRightNum = 0;
    Tree** pRetLeft = NULL;
    Tree** pRetRight = NULL;
    Tree** pCurTree = NULL;
    Tree* pCurTreeNode = NULL;

    if(iStart > iEnd){
        *pRet = (Tree**)malloc(sizeof(Tree*) * 1);
        (*pRet)[iRetNum] = NULL;
        iRetNum += 1;
        return iRetNum;
    }
    
    for(iCur = iStart; iCur <= iEnd; iCur++){
        iLeftNum = recursiveGenerateTree(&pRetLeft, iStart, iCur-1);
        iRightNum = recursiveGenerateTree(&pRetRight, iCur+1, iEnd);
        
        pCurTree = realloc(pCurTree, sizeof(Tree**)*(iRetNum+(iLeftNum*iRightNum)));
        for(i = 0; i < iLeftNum; i++){
            for(j = 0; j < iRightNum; j++){
                pCurTreeNode = (Tree*)malloc(sizeof(Tree) * 1);
                pCurTreeNode->val = iCur;
                pCurTreeNode->left = pRetLeft[i];
                pCurTreeNode->right = pRetRight[j];
                pCurTree[iRetNum] = pCurTreeNode;
                iRetNum += 1;
            }
        }

        free(pRetLeft);
        free(pRetRight);
    }

    *pRet = pCurTree;
    return iRetNum;
}

Tree** generateTrees(int n, int* returnSize)
{
    int iRetNum = 0;
    Tree** pRet = NULL;

    if(n=0){
        *returnSize = iRetNum;
        return pRet;
    }

    iRetNum = recursiveGenerateTree(&pRet, 1, n);

    *returnSize = iRetNum;
    return pRet;
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