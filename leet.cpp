#include <iostream>
#include "solution.hpp"

using namespace std;

int main()
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(strs);
    for(auto r : res) {
        for(auto a : r)
            cout << a << " ";
        cout << endl;
    }
    cout << "-----Program Ending-----" << endl;
    return 0;
}