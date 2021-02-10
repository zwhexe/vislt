#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_set;

class Solution {
public:
    vector<int> vec;
    unordered_set<int> uset;

    void backtrack(vector<vector<int>> &res, vector<int> &arr, int pos, int len) {
        if(arr.size() == len) {
            res.push_back(arr);
            return;
        }
        for(int i = pos; i < len; i++) {
            if(i!=pos && vec[i] == vec[pos] && uset.count(vec[i]))
                continue;
            else
                uset.emplace(vec[i]);
            std::swap(vec[pos], vec[i]);
            arr.push_back(vec[pos]);
            backtrack(res, arr, pos+1, len);
            arr.pop_back();
            std::swap(vec[pos], vec[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // arrange nums from small to large
        sort(nums.begin(), nums.end());
        // copy nums to vec as global variable
        for(auto a: nums)
            vec.emplace_back(a);
        // prepare backtrack parameters
        int N = (int)nums.size();
        vector<vector<int>> res;
        vector<int> arr;
        backtrack(res, arr, 0, N);
        return res;
    }
};

#endif