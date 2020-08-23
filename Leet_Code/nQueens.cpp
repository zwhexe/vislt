#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 2 || n==3)
            return {};
        vector<string> board (n, string(n, '.'));
        vector<vector<string>> ret;
        boardtrack(0, board, ret);
        return ret;
    }

    void boardtrack(int row, vector<string>& bd, vector<vector<string>>& ret){
        if(row == bd.size()){
            ret.push_back(bd);
            return;
        }
        for(int col = 0; col < bd.size(); col++){
            if(!isValid(bd, row, col))
                continue;
            bd[row][col] = 'Q';
            boardtrack(row+1, bd, ret);
            bd[row][col] = '.';
        }
    }

    bool isValid(vector<string> bd, int row, int col){
        int d = 1;
        for(int i = row-1; i >= 0; i--){
            if(bd[i][col]=='Q')
                return false;
            if(col-d>=0 && bd[i][col-d]=='Q')
                return false;
            if(col+d<bd.size() && bd[i][col+d]=='Q')
                return false;
            d++;
        }
        return true;
    }
};

int main()
{
    int n = 4;
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);

    return 0;
}