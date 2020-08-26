#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.size() == 0)
            return 0;
        unordered_map<char, int> arr;
        int left = 0, right = 1, ml = 1;
        arr[s[0]] = 1;
        while(right < s.size()){
            char sr = s[right];
            if(arr[sr] == 0){
                arr[sr] = 1;
                ml = (right-left+1) > ml ? (right-left+1) : ml;
                right++;
                continue;
            }
            else{
                while(arr[s[right]] != 0 && left < right){
                    char sl = s[left++];
                    int a = arr.erase(sl);
                }
            }
        }
        return ml;
    }
};

int main()
{
    string s("pwwkew");
    Solution sol;
    int n = sol.lengthOfLongestSubstring(s);
    cout << n << endl;

    system("pause");
    return 0;
}