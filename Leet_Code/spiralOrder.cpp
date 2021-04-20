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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = 0;
        int M = matrix.size() - 1;
        int n = 0;
        int N = matrix[0].size() - 1;
        vector<int> res;

        if(m == M)
            return matrix[0];
        else if (n == N) {
            for(auto a: matrix)
                res.push_back(a[0]);
            return res;
        }
        
        while(m <= M) {
            for(int i = n; i <= N; i++) {
                res.push_back(matrix[m][i]);
            }
            if(++m > M)
                break;
            for(int i = m; i <= M; i++) {
                res.push_back(matrix[i][N]);
            }
            if(--N < n)
                break;
            for(int i = N; i >= n; i--) {
                res.push_back(matrix[M][i]);
            }
            if(--M < m)
                break;
            for(int i = M; i >= m; i--) {
                res.push_back(matrix[i][n]);
            }
            if(++n > N)
                break;
        }
        return res;
    }
};

#endif