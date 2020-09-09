#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode*, int> memo;

public:
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        if(memo[root])
            return memo[root];
        // g: do not rob root
        int g = rob(root->left) + rob(root->right);
        // f: rob root and remember add its children
        int f = root->val;
        if(root->left)
            f += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            f += rob(root->right->left) + rob(root->right->right);
        // compare two situations and record in dp map
        memo[root] = max(f, g);
        return max(f, g);
    }
};

vector<TreeNode> initTree(int A[], int N) {
    vector<TreeNode> v;
    for(int i = 0; i < N; i++){
        TreeNode* t = new TreeNode (A[i]);
        v.push_back(*t);
    }
    for(int i = 0; i < N; i++){
        if(i*2+1<N && v[i*2+1].val!=0)
            v[i].left = &v[i*2+1];
        else
            v[i].left = NULL;
        if(i*2+2<N && v[i*2+2].val!=0)
            v[i].right = &v[i*2+2];
        else
            v[i].right = NULL;
    }
    return v;
}

int main()
{
    int A[] = {3,4,5,1,3,0,1};
    int N = sizeof(A)/sizeof(A[0]);
    vector<TreeNode> t = initTree(A, N);
    Solution sol;
    int ans = sol.rob(&t[0]);
    cout << ans << endl;

    return 0;
}