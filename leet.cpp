#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &arr, int pos, int len) {
        if(arr.size() == len) {
            res.push_back(arr);
            return;
        }
        for(int i = pos; i < len; i++) {
            swap(vec[pos], vec[i]);
            arr.push_back(vec[pos]);
            backtrack(res, arr, pos+1, len);
            arr.pop_back();
            swap(vec[pos], vec[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(auto a: nums)
            vec.emplace_back(a);
        int N = (int)nums.size();
        vector<vector<int>> res;
        vector<int> arr;
        backtrack(res, arr, 0, N);
        return res;
    }

private:
    vector<int> vec;
};


int main()
{
    vector<int> nums {1,1,2};
    Solution sol;
    vector<vector<int>> res = sol.permuteUnique(nums);
    for(auto r: res){
        for(auto a: r)
            cout << a << " ";
        cout << endl;
    }
    cout << "---Program Ending---" << endl;
    return 0;
}