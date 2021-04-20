#include <iostream>
#include "solution.hpp"

using namespace std;

int main()
{
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    bool res = sol.canJump(nums);
    cout << res << endl;

    cout << "-----Program Ending-----" << endl;
    return 0;
}