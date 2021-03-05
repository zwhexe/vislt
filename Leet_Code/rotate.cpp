#ifndef _SOLUTION_HPP
#define _SOLUTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using std::string;
using std::vector;
using std::unordered_set;
using std::swap;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	// horizontal flip
    	for(int i = 0; i < n/2; i++)
     		for(int j = 0; j < n; j++)
     			swap(matrix[i][j], matrix[n-i-1][j]);
     	// diagonal flip
     	for(int i = 0; i < n; ++i)
     		for(int j = 0; j < i; ++j)
     			swap(matrix[i][j], matrix[j][i]);       
    }
};

#endif