#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        else if(nums.size()==1)
            return nums[0];
        int N = nums.size();
        vector<int> dp(N, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= N-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        int p = dp[N-1];

        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i <= N-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int q = dp[N-1];

        return max(p,q);
    }
};

int main()
{
    vector<int> nums {2,3,2};
    Solution sol;
    int ans = sol.rob(nums);
    cout << ans << endl;

    return 0;
}