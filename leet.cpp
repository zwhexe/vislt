#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = 0, n = 4;
        queue<string> qs;
        qs.push("0000");
        while(toEnd(deadends, qs.front())){
            string str = qs.front();
            if(str == target)
                return ans;
            pushStr(qs, str);
            qs.pop();
            ans++;
        }
        return -1;
    }

    bool toEnd(vector<string>& dd, string &str){
        for(auto a = dd.begin(); a != dd.end(); a++){
            if(*a == str)
                return false;
        }
        return true;
    }

    void pushStr(queue<string>& qs, string& str){
        for(int i = 0; i < 4; i++){
            if(str[i] == '0'){
                str[i] = '1'; qs.push(str);
                str[i] = '9'; qs.push(str);
            }
            else if(str[i] == '9'){
                str[i] = '0'; qs.push(str);
                str[i] = '8'; qs.push(str);
            }
            else{
                str[i]++; qs.push(str);
                str[i]-=2; qs.push(str);
            }
        }
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