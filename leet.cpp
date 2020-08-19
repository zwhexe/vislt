#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;

        static int* ret = new int[amount+1]();
        if(ret[amount] != 0)
            return ret[amount];

        ret[amount] = amount + 10;
        for(int i = 0; i < coins.size(); i++){
            int t = 1 + coinChange(coins, amount-coins[i]);
            if(t == -1)
                continue;
            else
                ret[amount] = min(ret[amount], t);
        }

        if(ret[amount] != amount+10)
            return ret[amount];
        else
            return -1;
    }
};

int main()
{
    vector<int> coins {1,2,5};
    int amount = 11;
    Solution sol;
    int num = sol.coinChange(coins, amount);
    cout << num << endl;

    return 0;
}