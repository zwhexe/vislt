#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(int pos, vector<int>& arr, vector<vector<int>>& res, vector<int>& candidates, int target) {
        if(target < 0)  return;
        if(target == 0) {
            sort(arr.begin(), arr.end());
            res.push_back(arr);
            return;
        }
        for(size_t i = pos; i < candidates.size(); i++) {
            arr.push_back(candidates[i]);
            dfs(i+1, arr, res, candidates, target - candidates[i]);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> arr;
        dfs(0, arr, res, candidates, target);
        set<vector<int>> st(res.begin(), res.end());
        res.assign(st.begin(), st.end());
        return res;
    }
};

int main() 
{
    vector<int> candidates {2,5,2,1,2};
    int target = 5;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum2(candidates, target);
    for(auto a: res){
        for(auto b: a)
            cout << b << " ";
        cout <<endl;
    }

    return 0;
}