// 1137. N-th Tribonacci Number
// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.\

//Recursion plus memoization (Top-down DP)
class Solution {
public:
    int helper(int n,vector<int>& dp){
        if(n==0) return 0;
        if(n<=2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};

//Tabulation (Bottom-up DP)
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};