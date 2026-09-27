// Matrix Chain Multiplication
// Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has 
// the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. 
// The efficient way is the one that involves the least number of multiplications.

// Memo
class Solution {
  public:
        // Try every split k of matrices i..j; combine both subchains and add the cost
        // arr[i-1] * arr[k] * arr[j]. Memoize each interval; a single matrix costs 0.
    int f(vector<vector<int>>& dp,int i,int j,vector<int> arr){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mans=1e9;
        for(int k=i;k<=j-1;k++){
            int steps = arr[i-1]*arr[k]*arr[j]+f(dp,i,k,arr)+f(dp,k+1,j,arr);
            mans=min(mans,steps);
        }
        return dp[i][j]=mans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(dp,1,n-1,arr);
    }
};

//Tabulation
class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Base case
        for(int i = 1; i < n; i++) {
            dp[i][i] = 0;
        }

        for(int i = n - 1; i >= 1; i--) {
            for(int j = i + 1; j < n; j++) {
                int mini = 1e9;

                for(int k = i; k < j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j]
                              + dp[i][k]
                              + dp[k+1][j];

                    mini = min(mini, steps);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n-1];
    }
};