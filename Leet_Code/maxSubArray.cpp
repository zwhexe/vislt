#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::vector;
using std::unordered_map;
using std::sort;
using std::swap;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int res = nums[0];
        for(int i = 0; i < size; i++) {
            if(sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            res = sum > res ? sum : res;
        }
        return res;
    }
};

#endif