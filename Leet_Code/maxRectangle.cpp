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
        if(!matrix.size()) 
            return 0;
            
        int row = matrix.size();
        int col = matrix[0].size();
        int maxA = 0;
        vector<int> bar(col+1, 0); // store the column height
        stack<int> stk; // store the column index
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col+1; j++){
                if(j == col || matrix[i][j] == '0')
                    bar[j] = 0;
                else
                    bar[j] += 1;

                while(!stk.empty() && bar[j] < bar[stk.top()]){
                    int top = stk.top();
                    stk.pop();
                    maxA = max(maxA, bar[top]*(stk.empty()?j:j-stk.top()-1));
                }
                stk.push(j);
            }
        }
        return maxA;
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

    system("pause");
    return 0;
}