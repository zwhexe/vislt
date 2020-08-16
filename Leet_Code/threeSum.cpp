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
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            twoSum(ret, nums, i);
            while(i < nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return ret;
    }

    void twoSum(vector<vector<int>>& ret, vector<int>& nums, int i) {
        int target = 0 - nums[i];
        int j = i+1, k = nums.size() - 1;
        while(j < k){
            if(nums[j] + nums[k] == target){
                vector<int> v{nums[i], nums[j++], nums[k--]};
                ret.push_back(v);
                while(nums[j] == nums[j-1] && j < k)
                    j++;
                while(nums[k] == nums[k+1] && j < k)
                    k--;
            }
            else if(nums[j] + nums[k] < target)
                j++;
            else if(nums[j] + nums[k] > target)
                k--;
        }
    }
};

int main()
{   
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    for(auto a = ans.begin(); a != ans.end(); a++){
        vector<int> vec = *a;
        for(auto v = vec.begin(); v != vec.end(); v++)
            cout << *v << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}