#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {

    }
};

int main()
{
    vector<int> nums {1,0,-1,0,-2,2};
    int target = 0;
    Solution sol;
    vector<vector<int> > ans = sol.fourSum(nums, target);
    for(auto a: ans){
        for(auto b: a)
            cout << b << " ";
        cout << endl;
    }
}