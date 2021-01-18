#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int np = p.length(), ns = s.length();
        // dp[i][j] stand for whether first p[i] is match first s[j]
        vector<vector<bool>> dp(np+1, vector<bool>(ns+1, false));

        dp[0][0] = true;
        for(int i = 1; i <= ns; i++)
            if(p[i-1] == '*')
                dp[i][0] = true;
            else
                break;
        
        for(int i = 1; i <= ns; i++)
            for(int j = 1; j <= np; j++)
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
        
        return dp[np][ns];
    }
};

int main()
{
    // ? match any single character
    // * match any characters include empty
    // use p to match s
    string s = "adceb";
    string p = "*a*b";
    Solution sol;
    bool ans = sol.isMatch(s, p);
    if(ans)
        cout << "Match!" << endl;
    else
        cout << "Not Match!" << endl;

    return 0;
}