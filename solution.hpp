#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::vector;
using std::unordered_map;
using std::sort;
using std::swap;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> map;
        string temp;
        for(auto str: strs) {
            temp = str;
            sort(str.begin(), str.end());
            if(map[str] == 0) {
                int num = map.size();
                map.insert({str, num+1});
                vector<string> ans;
                ans.push_back(temp);
                res.push_back(ans);
            }
            else {
                int num = map[str];
                res[num].push_back(temp);
            }
        }
        return res;
    }
};

#endif