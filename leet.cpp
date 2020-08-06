#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        int max = heights[0];
        int area = max, tmp;
        vector<int> st{*heights.begin()};

        for(auto a = heights.begin()+1; a!=heights.end(); a++){
            while(*a < *(st.end()-1) && !st.empty()){
                tmp = *(st.end()-1);
                st.pop_back();
                area += *a;
            }
            st.push_back(*a);
            if(area >= max)
                max = area;
        }

        return max;
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