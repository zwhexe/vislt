#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        

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