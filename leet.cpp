#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

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
            swap(vec[pos], vec[i]);
            arr.push_back(vec[pos]);
            backtrack(res, arr, pos+1, len);
            arr.pop_back();
            swap(vec[pos], vec[i]);
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


int main()
{
    vector<int> nums {1,2,2,1};
    Solution sol;
    vector<vector<int>> res = sol.permuteUnique(nums);
    for(auto r: res){
        for(auto a: r)
            cout << a << " ";
        cout << endl;
    }
    cout << "-----Program Ending-----" << endl;
    return 0;
}