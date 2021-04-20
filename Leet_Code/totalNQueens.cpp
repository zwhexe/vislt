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
    int res = 0;

public:
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) {
            res++; return; 
        }
        // set all availiable pos as 1
        int bits = ~(col | ld | rd) & ((1 << n) - 1);   // 1
        while (bits > 0) {   // 2
            int pick = bits & -bits; // 3
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1); //4
            bits &= bits - 1; // 5
        }
    }

    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        return this->res;
    }
};

#endif