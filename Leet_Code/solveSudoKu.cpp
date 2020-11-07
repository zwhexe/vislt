#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // three array to verifiy whether it's valid
    bool row[9][9];
    bool col[9][9];
    bool blk[3][3][9];
    bool valid;
    // pair to verifiy where is valid
    vector<pair<int, int>> spaces;
    
public:
    void dfs(vector<vector<char>>& board, int pos) {
        if(pos == spaces.size()) {
            // pos has touch bottom
            valid = true;
            return;
        }

        auto [i,j] = spaces[pos];
        // for loop to test 1-9 in [i,j]
        for(int num = 0; num < 9 && !valid; ++num) {
            if(!row[i][num] && !col[j][num] && !blk[i/3][j/3][num]) {
                row[i][num] = col[j][num] = blk[i/3][j/3][num] = true;
                board[i][j] = num + '0' + 1;
                dfs(board, pos+1);
                row[i][num] = col[j][num] = blk[i/3][j/3][num] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        // set all as false at first
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(blk, false, sizeof(blk));
        valid = false;
        // for loop to fill original 9x9 spaces with empty
        // and record not empty in row, col, blk
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    spaces.emplace_back(i,j);
                else
                {
                    int num = board[i][j] - '0' - 1;
                    row[i][num] = col[j][num] = blk[i/3][j/3][num] = true;
                }
            }
        }
        // row, col, blk and spaces have all been initialized
        dfs(board, 0);
    }
};

int main()
{
    vector<vector<char>> board {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    Solution sol;
    sol.solveSudoku(board);

    for(auto a: board){
        for(auto b: a)
            cout << b << ' ';
        cout << endl;
    }

    return 0;
}