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
            dp[i] = new int* [3];
            dp[i][0] = new int[2];
            dp[i][1] = new int[2];
            dp[i][2] = new int[2];
            // define k = 0 situation
            dp[i][0][0] = 0;
            dp[i][0][1] = -prices[i];
        }

        for(int i = 0; i < N; i++){
            for(int k = 1; k <= 2; k++){
                if(i==0){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[0];
                }
                else{
                    // first is rest, second is sell that k++
                    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]);
                    // first is rest, second is buy that k stay
                    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
                }
            }
        }

        return dp[N-1][2][0];
    }
};

int main()
{
    vector<int> prices {1,2,3,4,5};
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout << ans << endl;

    return 0;
}