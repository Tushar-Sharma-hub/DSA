// 322. Coin Change
// You are given an integer array coins representing coins of different denominations and an integer amount 
// representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Recursion + Memoization - Top Down Approach
// T.C: O(n*amount) where n=coins.size() and amount=amount
// S.C: O(n*amount) + O(n) ~ O(n*amount)
// Just we can either take or not take the coin and return the minimum of both cases.
// Here we can reuse the same coin multiple times, so when we take the coin, we don't move to the next index, we stay at the same index.
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& coins,int amount){
        if(idx==0){
            if(amount%coins[idx]==0){
                return amount/coins[idx];
            }
            return 1e8;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notTake=f(dp,idx-1,coins,amount);
        int take=INT_MAX;
        if(coins[idx]<=amount) take=1+f(dp,idx,coins,amount-coins[idx]);
        return dp[idx][amount]=min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= f(dp,n-1,coins,amount);
        if(ans>=1e8) return -1;
        return ans;
    }
};

// Tabulation - Bottom Up Approach
// T.C: O(n*amount) where n=coins.size() and amount=amount
// S.C: O(n*amount)
// Here we can reuse the same coin multiple times, so when we take the coin, we don't move to the next index, we stay at the same index.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0) dp[0][a]=a/coins[0];
            else dp[0][a]=1e8;
        }
        for(int idx=1;idx<n;idx++){
            for(int a=0;a<=amount;a++){
                int notTake=dp[idx-1][a];
                int take=INT_MAX;
                if(coins[idx]<=a) take=1+dp[idx][a-coins[idx]];
                dp[idx][a]=min(take,notTake);
            }
        }
        if(dp[n-1][amount]>=1e8) return -1;
        return dp[n-1][amount];
    }
};

// Space Optimization - Bottom Up Approach
// T.C: O(n*amount) where n=coins.size()
// S.C: O(amount)
// Here we can reuse the same coin multiple times, so when we take the coin, 
// we don't move to the next index, we stay at the same index.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0) prev[a]=a/coins[0];
            else prev[a]=1e8;
        }
        for(int idx=1;idx<n;idx++){
            for(int a=0;a<=amount;a++){
                int notTake=prev[a];
                int take=INT_MAX;
                if(coins[idx]<=a) take=1+curr[a-coins[idx]];
                curr[a]=min(take,notTake);
            }
            prev=curr;
        }
        if(prev[amount]>=1e8) return -1;
        return prev[amount];
    }
};