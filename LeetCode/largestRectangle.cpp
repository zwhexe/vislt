#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // add 0 that pop all elems at the end
        stack<int> stk; // store elems index of heights, not elems
        int maxA = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                int top = stk.top(); // top will be pop and calculate it's area
                stk.pop();
                maxA = max(maxA, heights[top]*(stk.empty()?i:(i-stk.top()-1)));
            }
            stk.push(i);
        }
        return maxA;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    int ans = sol.largestRectangleArea(heights);
    cout << ans << endl;

    return 0;
}