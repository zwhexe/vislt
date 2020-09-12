#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

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