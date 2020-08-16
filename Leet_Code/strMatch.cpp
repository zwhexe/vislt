#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        return match(s.data(), p.data());
    }

    bool match(const char* s, const char* p){
        if(!*p)
            return !*s;
        if(*(p+1) != '*')
            return *s==*p || (*p=='.' && *s!='\0') ? match(s+1, p+1) : false;
        else
            return *s==*p || (*p=='.' && *s!='\0') ? match(s, p+2) || match(s+1, p) : match(s, p+2);
    }
};

int main()
{
    string s = "aab";
    string p = ".*b";
    Solution sol;
    bool ans = sol.isMatch(s, p);
    cout << ans << endl;

    return 0;
}