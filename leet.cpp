#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int combination(int i) {
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()<1 || candidates.size()>30 || target>500 || target<1)
            return {};
        sort(candidates.begin(), candidates.end());
        if(*candidates.begin() < 1 || *(candidates.end()-1) > 200)
            return {};
        
        vector<vector<int>> res;
        for(int i = 0; i < res.size(); i++){
            if(res[i] > target)
                break;
            vector<int> arr;
            int sum = 0;

        }

    }
};

int main()
{
    vector<int> candidates {2,3,6,7};
    int target = 7;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(candidates, target);

    
    return 0;
}