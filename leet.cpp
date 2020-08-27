#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        for (auto c : t) count[c] ++;
        int len = 0, n = s.size();
        int minlen = n;
        string ans = "";
        int l = 0, r = 0;
        for ( ; r < n; r ++) {
            count[s[r]] --;
            if (count[s[r]] >= 0) len ++;
            while (len == t.size()) {
                if (r - l + 1 <= minlen) {
                    minlen = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                }
                count[s[l]] ++;
                if (count[s[l]] > 0) len --;
                l ++;
            }
        }
        return ans;
    }
};

int main()
{
    string s("ADOBECODEBANC");
    string t("ABC");
    Solution sol;
    string ans = sol.minWindow(s, t);
    cout << ans << endl;

    return 0;
}