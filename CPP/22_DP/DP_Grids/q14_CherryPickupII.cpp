// 1463. Cherry Pickup II
// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] 
// represents the number of cherries that you can collect from the (i, j) cell.
// You have two robots that can collect cherries for you:
// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:
// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

//Recursive + Memoization
//T.C: O(n*m*m*9) ~ O(n*m*m) where n=rows, m=cols
//S.C: O(n*m*m) + O(n) ~ O(n*m*m)
class Solution {
public:
    int f(int i,int j1,int j2,int r,int c,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int mans=-1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int v=0;
                if(j1==j2) v=grid[i][j1];
                else v=grid[i][j1]+grid[i][j2];
                v+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
                mans=max(mans,v);
            }
        }
        return dp[i][j1][j2]=mans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return f(0,0,c-1,r,c,grid,dp);
    }
};

//Tabulation
//T.C: O(n*m*m*9) ~ O(n*m*m) where n=rows, m=cols
//S.C: O(n*m*m)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int v=0;
                if(j1==j2) v=grid[r-1][j1];
                else v=grid[r-1][j1]+grid[r-1][j2];
                dp[r-1][j1][j2]=v;
            }
        }
        for(int i=r-2;i>=0;i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int mans=-1e8;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int v=0;
                            if(j1==j2) v=grid[i][j1];
                            else v=grid[i][j1]+grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c) v+=dp[i+1][j1+dj1][j2+dj2];
                            else v+=-1e8;
                            mans=max(mans,v);
                        }
                    }
                    dp[i][j1][j2]=mans;
                }
            }
        }
        return dp[0][0][c-1];
    }
};