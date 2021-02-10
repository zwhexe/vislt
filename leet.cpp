#include <iostream>
#include "solution.hpp"

using namespace std;

int main()
{
    vector<int> nums {1,2,2,1};
    Solution sol;
    vector<vector<int>> res = sol.permuteUnique(nums);
    for(auto r: res){
        for(auto a: r)
            cout << a << " ";
        cout << endl;
    }
    cout << "-----Program Ending-----" << endl;
    return 0;
}