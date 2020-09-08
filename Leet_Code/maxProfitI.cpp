#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int n = prices.size();
        // int** dp = new int* [10];
        // for(int i = 0; i < n; i++){
        //     dp[i] = new int[2];
        // }
        int* dp = new int[2];

        for(int i = 0; i < n; i++){
            if(i==0){
                dp[0] = 0;
                dp[1] = -prices[i];
                continue;
            }
            int d0 = dp[0], d1 = dp[1];
            dp[0] = max(d1+prices[i], d0);
            dp[1] = max(d0-prices[i], d1);
        }

        return dp[0];
    }
};

int main()
{
    vector<int> prices {7,1,5,3,6,4};
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout << ans << endl;

    return 0;
}