// Minimum Steps to Make 1
// Given a number n, count minimum steps to minimize it to 1 using the following operations :
// If n is divisible by 2 then you may reduce n to n/2.
// If n is divisible by 3 then you may reduce n to n/3.
// Decrement n by 1 (No condition for this)

//Top-down
class Solution {
  public:
    int inf=INT_MAX;
    int helper(int n,vector<int>&dp){
        if(n==1) return 0;
        if(n==2 || n==3) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= 1 + min({ helper(n-1,dp), (n%3==0)?helper(n/3,dp):inf, (n%2==0)?helper(n/2,dp):inf});
    }
    int getMinSteps(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};

//Bottom-up
class Solution {
  public:
    int inf=INT_MAX;
    int getMinSteps(int n) {
        vector<int> dp(n+1);
        if(n==1) return 0;
        if(n==2 || n==3) return 1;
        dp[1]=0;
        dp[2]=1;
        dp[3]=1;
        int i=4;
        while(i<=n){
            dp[i]=1+min({dp[i-1],i%2==0?dp[i/2]:inf,i%3==0?dp[i/3]:inf});
            i++;
        }
        return dp[n];
    }
};
