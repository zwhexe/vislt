#ifndef _UNIQUE_HPP
#define _UNIQUE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using std::string;
using std::vector;
using std::unordered_set;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    int N;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N = nums.size();
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int> nums) {
        if((int)tmp.size() == N) {
            res.emplace_back(tmp);
            return;
        }
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int num = nums[i];
            // store num in tmp, and delete it from nums
            tmp.emplace_back(nums[i]);
            std::swap(nums[i], nums[nums.size() - 1]);
            nums.pop_back();
            // backtrack nums that has been processed
            backtrack(nums);
            // restore nums
            nums.emplace_back(num);
            std::swap(nums[i], nums[nums.size() - 1]);
            tmp.pop_back();
        }
    }
};

#endif