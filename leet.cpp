#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(int cur, vector<int>& arr, vector<vector<int>>& res,
            vector<int>& candidates, int target) {
        if(target < 0) return; // sum is beyond target
        if(target == 0) {   // sum of arr equal to target
            res.push_back(arr);
            return;
        }
        for(int i = cur; i < candidates.size(); i++) {
            arr.push_back(candidates[i]);
            dfs(i, arr, res, candidates, target - candidates[i]);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        dfs(0, arr, res, candidates, target);
        return res;
    }
};

int main()
{
    vector<int> candidates {2,3,6,7};
    int target = 7;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for(auto a: res){
        for(auto b: a)
            cout << b << " ";
        cout <<endl;
    }

    return 0;
}