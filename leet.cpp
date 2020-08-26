#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(int i = 0; i < t.size(); i++)
            need[t[i]] = 1;
        int left = 0, right = 0;
        while(right < s.size()){
            char c = s[right];

        }
    }
};

int main()
{
    string s("ADOBECODEBANC");
    string t("ABC");
    Solution sol;
    string ans = sol.minWindow(s, t);
    cout << ans << endl;
    // ans is BANC
    system("pause");
    return 0;
}