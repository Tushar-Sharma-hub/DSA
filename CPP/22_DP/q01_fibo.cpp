//Fibonacci Number

//Using Top-Down DP (Memoization)
class Solution {
public:
    int fibo(int n, vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n]; // Return the cached result if it exists
        dp[n]=fibo(n-1,dp)+fibo(n-2,dp); // Compute the Fibonacci number recursively and store the result in the dp array
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibo(n,dp);
    }
};

//Using Bottom-Up DP (Tabulation)
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<dp.size();i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}; 