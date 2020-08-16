#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> vec;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top();
            if(t == nullptr){
                stk.pop();
                vec.push_back(stk.top()->val);
                stk.pop();
                continue;
            }
            // set nullptr as sentinel to announce whether node already in stack
            stk.push(nullptr);
            if(t->right)
                stk.push(t->right);
            if(t->left)
                stk.push(t->left);
        }
        return vec;
    }
};



int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.right = &t2;
    t2.left = &t3;

    Solution sol;
    vector<int> v = sol.postorderTraversal(&t1);
    system("pause");
    return 0;
}