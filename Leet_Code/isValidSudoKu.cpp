#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        vector<int> center {11, 14, 17, 41, 44, 47, 71, 74, 77};
        unordered_map<char, vector<int> > hash;
        for(int i = 1; i <= 9; i++){
            vector<int> vec;
            hash[i+'0'] = vec;
        }
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    hash[ch].push_back(i*10+j);
                }

        for(int n = 1; n <= 9 && res == true; n++) {
            vector<int> row(9, 0);
            vector<int> col(9, 0);
            vector<int> ctr(9, 0);
            char ch = n + '0';
            if(!hash[ch].empty()){
                for(auto a: hash[ch]){
                    int i = a/10;
                    int j = a%10;
                    int k = i/3 * 3 + j/3;
                    if(row[i] == 0 && col[j] == 0 && ctr[k] == 0) {
                        row[i]++;
                        col[j]++;
                        ctr[k]++;
                    }
                    else {
                        res = false;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<char>> board {{'8','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    Solution sol;
    bool ans = sol.isValidSudoku(board);
    cout << ans << endl;

    return 0;
}