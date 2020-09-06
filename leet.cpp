#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices){
        if(prices.empty())
            return 0;
        int N = prices.size();
        int ***dp = new int**[N];
        for(int i = 0; i < N; i++){
            dp[i] = new int* [2];
            dp[i][0] = new int[2];
            dp[i][1] = new int[2];
        }

        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for(int i = 1; i < N; i++){

        }

        return 0;
    }
};

int main()
{
    vector<int> prices {3,3,5,0,0,3,1,4};
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout << ans << endl;

    return 0;
}