#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums [2];
        int ans = sum;
        for(int i = 0; i < nums.size()-2; i++){
            int lo = i+1;
            int hi = nums.size() - 1;
            while(lo < hi){
                sum = nums[i] + nums[lo] + nums[hi];
                if(abs(target-sum) < abs(target-ans))
                    ans = sum;
                if(sum > target)
                    hi--;
                if(sum < target)
                    lo++;
                if(sum == target)
                    return sum;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums {-1,2,1,-4};
    int target = 1;
    Solution sol;
    int ans = sol.threeSumClosest(nums, target);
    cout << ans << endl;

    return 0;
}
