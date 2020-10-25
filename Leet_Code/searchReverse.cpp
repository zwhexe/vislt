#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if(n == 0)  return -1;
        if(n == 1) return nums[0] == target ? 0 : -1;
        // find place where bisect search
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) 
                return mid;

            if(nums[mid] >= nums[left]) { // left half ascending
                if(nums[left] <= target && target <= nums[mid]) // target in left half
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            else { // right half ascending
                if(target >= nums[mid] && target <= nums[right]) // target in right half
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            
        }
        return -1;
    }
};

int main()
{
    vector<int> nums {4,5,6,7,0,1,2};
    int target = 0;
    Solution sol;
    int res = sol.search(nums, target);
    cout << res << endl;

    return 0;
}