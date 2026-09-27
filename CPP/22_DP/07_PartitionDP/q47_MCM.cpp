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

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len = length of matrix chain
        for(int len = 2; len <= n - 1; len++) {

            for(int i = 1; i + len - 1 <= n - 1; i++) {

                int j = i + len - 1;
                dp[i][j] = 1e9;

                // Try every possible partition
                for(int k = i; k < j; k++) {

                    int steps = arr[i - 1] * arr[k] * arr[j]
                              + dp[i][k]
                              + dp[k + 1][j];

                    dp[i][j] = min(dp[i][j], steps);
                }
            }
        }

        return dp[1][n - 1];
    }
};