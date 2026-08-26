// 120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, 
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

//Just store the last row of the triangle in a 1D array and update it in place for each row above it.
//Time complexity: O(n^2), where n is the number of rows in the triangle.
//Space complexity: O(n), where n is the number of rows in the triangle.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

//T.C. O(n^2) time and O(1) space solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int below = triangle[i + 1][j];
                int belowRight = triangle[i + 1][j + 1];
                triangle[i][j] += min(below, belowRight);

            }
        }
        return triangle[0][0];
    }
};