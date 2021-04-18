#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::string;
using std::vector;
using std::unordered_map;
using std::sort;
using std::swap;
using std::find;

class Solution {
private:
    int res;
    int size;
    vector<unordered_map<int, bool>> board;

public:
    void boardtrack(int row) {
        if(row == size) {
            res++;
            return;
        }
        // for loop cols usage
        for(int i = 0; i < size; i++) {
            if(board[row][i])
                continue;
            
            boardtrack(row+1);

        }
    }

    int totalNQueens(int n) {
        if (n == 2 || n == 3)
            return 0;
        else if (n == 1) 
            return 1;
        else
            this->size = n;
        // unRow and unCol
        res = 0;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++)
                board[i][j] = false; 
        }
        boardtrack(0);
        return res;
    }
};

#endif