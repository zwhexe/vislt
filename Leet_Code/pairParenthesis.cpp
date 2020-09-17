#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        foo(res, "", 0, 0, n);
        return res;
    }

    void foo(vector<string>& res, string str, int l, int r, int N) {
        if(l > N || r > N || l < r) 
            return;
        if(l==N && r==N) {
            res.push_back(str);
            return;
        }

        foo(res, str+'(', l+1, r, N);
        foo(res, str+')', l, r+1, N);

        return;
    }
};

int main()
{
    int n = 3;
    Solution sol;
    vector<string> ret = sol.generateParenthesis(n);
    for(auto a: ret)
        cout << a << endl;

    return 0;
}