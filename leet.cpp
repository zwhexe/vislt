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
        if(s.size() < t.size())
            return "";
        int lo = 0, hi = s.size();
        unordered_map<char,int> window;
        int left = 0, right = 0;
        while(right < s.size()){
            window.insert(pair<char,int>{s[right], 1});
            if(!validStr(window, t)){
                right++;
            }
            else{
                while(validStr(window, t) && left <= right){
                    if(right-left < hi - lo){
                        lo = left;
                        hi = right;
                    }
                    left++;
                }
            }
        }
        if(hi - lo >= s.size())
            return "";
        return s.substr(lo, hi-lo+1);
    }

    bool validStr(unordered_map<char,int>& window, string& t){
        for(int i = 0; i < t.size(); i++)
            if(window[t[i]] == 0)
                return false;
        cout << "existed!" << endl;
        return true;
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