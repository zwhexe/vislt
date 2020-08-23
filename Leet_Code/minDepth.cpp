#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root){
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                if(!q.front()->left && !q.front()->right)
                    return depth;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    TreeNode t(3);
    TreeNode t1(9);
    TreeNode t2(20);
    TreeNode t3(15);
    TreeNode t4(7);
    t.left = &t1; t.right = &t2;
    t2.left = &t3; t2.right = &t4;
    Solution sol;
    int depth = sol.minDepth(&t);
    cout << depth << endl;

    return 0;
}