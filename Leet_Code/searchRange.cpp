#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        if(left > right)
            return{-1, -1};
        return vector<int> {left, right};
    }

    int left_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }
        if(left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int right_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                left = mid + 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }
        if(right < 0 || nums[right] != target)
            return -1;
        return right;
    }
};

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution sol;
    vector<int> v = sol.searchRange(nums, target);
    cout << *v.begin() << " " << *(v.end()-1) << endl;

    return 0;
}