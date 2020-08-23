#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> track;
        backtrack(nums, track, ret);
        return ret;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& ret) {
        if(track.size() == nums.size()){
            ret.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(contains(track, nums[i]))
                continue;
            track.push_back(nums[i]);
            int j = track.size() - 1;
            backtrack(nums, track, ret);
            track.erase(track.begin() + j);
        }

    }

    bool contains(vector<int>& nums, int num){
        for(auto a = nums.begin(); a != nums.end(); a++)
            if(*a == num)
                return true;
        return false;
    }
};

int main()
{
    vector<int> nums {1,2,3};
    Solution sol;
    vector<vector<int>> ans = sol.permute(nums);

    return 0;
}