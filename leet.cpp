#include <iostream>
#include "solution.hpp"

using namespace std;

int main()
{
    vector<vector<int>> nums;
    nums.push_back({1,3});
    nums.push_back({2,6});
    nums.push_back({8,12});
    nums.push_back({15,18});
    Solution sol;
    vector<vector<int>> res = sol.merge(nums);
    for(auto r: res) {
        for(auto a: r)
            cout << a << " ";
        cout << endl;
    }

    cout << "-----Program Ending-----" << endl;
    return 0;
}