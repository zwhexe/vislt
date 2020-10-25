#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        vector<int> dp(s.length(), 0);
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    // find out whether i-2 existed
                    dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
                }
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(') {
                    dp[i] = (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0) + dp[i-1] + 2;
                }
            }
            maxlen = max(dp[i], maxlen);
        }
        return maxlen;
    }
};

int main()
{
    string s(")()())");
    Solution sol;
    int res = sol.longestValidParentheses(s);
    cout << res << endl;

    return 0;
}