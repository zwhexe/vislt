#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode Tree;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int subTrees(int start, int end, int* narr)
{
    int nt = 0;
    int nl = 0;
    int nr = 0;

    if(start > end)
        return 1;
    
    for(int i = start; i <= end; i++){
        if(narr[i-start] == 0){
            nl = subTrees(start, i-1, narr);
            narr[i-start] = nl;
        }
        else{
            nl = narr[i-start];
        }
        
        if(narr[end-i] == 0){
            nr = subTrees(i+1, end, narr);
            narr[end-i] = nl;
        }
        else{
            nr = narr[end-i];
        }
        
        nt += nl * nr;
    }

    return nt;
}

int numTrees(int n)
{
    int nt = 0;
    int nl = 0;
    int nr = 0;
    int* narr = (int*)calloc(n+1, sizeof(int));
    narr[0] = 1;
    narr[1] = 1;
    for(int i = 1; i <= n; i++){
        nl = subTrees(1, i-1, narr);
        nr = subTrees(i+1, n, narr);
        nt += nl * nr;
    }

    return nt;
}

int main()
{
    int n;
    scanf("%d", &n);

    int nt;
    nt = numTrees(n);
    printf("%d\n", nt);
    return 0;
}