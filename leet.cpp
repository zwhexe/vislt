#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> pn;
        pn.push_back("");
        pn.push_back("");
        pn.push_back("abc");
        pn.push_back("def");
        pn.push_back("ghi");
        pn.push_back("jkl");
        pn.push_back("mno");
        pn.push_back("pqrs");
        pn.push_back("tuv");
        pn.push_back("wxyz");
        vector<string> tb;
        for(int i = 0; i < digits.size(); i++){
            char c = digits[i];
            int j = c - '0';
            tb.push_back(pn[j]);
        }
        vector<string> ret;
        string str = "";
        foo(ret, tb, 0, str);
        return ret;
    }

    void foo(vector<string>& ret, vector<string> tb, int ind, string str) {
        if(ind == tb.size()){
            ret.push_back(str);
            return;
        }
        for(int i = ind; i < tb.size(); i++){
            string ts = tb[i];
            for(int j = 0; j < ts.length(); j++){
                char c = ts[j];
                str += c;
                foo(ret, tb, ind++, str);
                str.pop_back();
            }
        }
    }
};

int main()
{
    string digits = "23";
    Solution sol;
    vector<string> strs = sol.letterCombinations(digits);
    for(auto a = strs.begin(); a != strs.end(); a++)
        cout << *a << endl;

    return 0;
}
