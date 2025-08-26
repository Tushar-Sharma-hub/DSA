//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.-LC73.
#include<iostream>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;

    // Step 1: Use first row and column as markers
    for(int i = 0; i < n; i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Set matrix zeroes based on markers
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        // Step 3: Handle the first column separately
        if(col0 == 0) {
            matrix[i][0] = 0;
        }
    }
}