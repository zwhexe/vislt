#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return search(root, 1);
    }

    int search(TreeNode* t, int d){
        if(!t->left && !t->right)
            return d;
        else{
            int ld = d, rd = d;
            if(t->left)
                ld = search(t->left, d+1);
            if(t->right)
                rd = search(t->right, d+1);
            return max(ld, rd);
        }
    }
};



int main()
{   
    TreeNode t1(3);
    TreeNode t2(9);
    TreeNode t3(20);
    TreeNode t4(15);
    TreeNode t5(7);
    t1.left = &t2; t1.right = &t3;
    t3.left = &t4; t3.right = &t5;

    Solution sol;
    int ans = sol.maxDepth(&t1);
    cout << ans << endl;
    system("pause");
    return 0;
}