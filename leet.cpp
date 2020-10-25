#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N=nums.size();
        int left = 0;
        int right = N-1;
        int mid=0;
        while(left<=right)
        {
            mid = (left + right) / 2;           
            if (nums[mid] >= target)
                right = mid - 1;
            else    
                left = mid + 1;
        }
        return left;

    }
};


int main()
{
    vector<int> nums {1,3,5,6};
    int target = 2;
    Solution sol;
    int res = sol.searchInsert(nums, target);
    cout << res << endl;

    return 0;
}