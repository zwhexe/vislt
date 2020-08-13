#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxM = matrix[0][4] - '0';
        return maxM;
    }
};

int main()
{
    vector<vector<char>> mat;

    char ch1[] = "10100";
    vector<char> v1(ch1, ch1+strlen(ch1));
    mat.push_back(v1);

    char ch2[] = "10111";
    vector<char> v2(ch2, ch2+strlen(ch2));
    mat.push_back(v2);

    char ch3[] = "11111";
    vector<char> v3(ch3, ch3+strlen(ch3));
    mat.push_back(v3);

    char ch4[] = "10010";
    vector<char> v4(ch4, ch4+strlen(ch4));
    mat.push_back(v4);

    Solution sol;
    int ans = sol.maximalRectangle(mat);
    cout << ans << endl;

    return 0;
}