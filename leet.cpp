#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

    }
};

int main()
{
    vector<string> deadends{"0201","0101","0102","1212","2002"};
    string target = "0202";
    Solution sol;
    int ans = sol.openLock(deadends, target);
    cout << ans << endl;

    return 0;
}