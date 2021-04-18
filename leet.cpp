#include <iostream>
#include "solution.hpp"

using namespace std;

int main()
{
    int n = 4;
    Solution sol;
    int res = sol.totalNQueens(n);
    cout << res << endl;
    cout << "-----Program Ending-----" << endl;
    return 0;
}