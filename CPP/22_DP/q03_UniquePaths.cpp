// 62. Unique Paths
// There is a robot on an m x n grid. 
// The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

//Simple Recursion- Time limit exceeded
class Solution {
public:
    int helper(int m,int n,int i,int j){
        if(i==m && j==n) return 1;
        if(i>m || j>n) return 0; 
        int rightWays=helper(m,n,i,j+1);
        int downWays=helper(m,n,i+1,j);
        return rightWays+downWays;
    }
    int uniquePaths(int m, int n) {
        return helper(m-1,n-1,0,0);
    }
};

//Recursion plus memoization
class Solution {
public:
    int helper(int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i==m && j==n) return 1;
        if(i>m || j>n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=helper(m,n,i,j+1,dp)+helper(m,n,i+1,j,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,0,0,dp);
    }
};

//Tabulation
//In a first row and first column, there is only one way to reach any cell, which is by moving right or down respectively.
//So we can fill the first row and first column with 1.
//For the rest of the cells, we can fill them by adding the number of ways to reach the cell from the top and from the left.(as we can only move right or down).
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};