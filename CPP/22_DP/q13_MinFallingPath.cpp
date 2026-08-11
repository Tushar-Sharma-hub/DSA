// 931. Minimum Falling Path Sum
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly 
// below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), 
// (row + 1, col), or (row + 1, col + 1).

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        vector<int> dp=matrix[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(j==0)
                    curr[j]=matrix[i][j]+min(dp[j],dp[j+1]);
                else if(j==n-1)
                    curr[j]=matrix[i][j]+min(dp[j],dp[j-1]);
                else
                    curr[j]=matrix[i][j]+min(dp[j],min(dp[j-1],dp[j+1]));
            }
            dp=curr;
        }
        return *min_element(dp.begin(),dp.end());
    }
};