// 309. Best Time to Buy and Sell Stock with Cooldown
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like 
// (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//Recursive solution with memoization
//Jusst like we did in BS2, but we have to add a cooldown day after selling the stock.
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& prices,int b){
        if(idx>=prices.size()) return 0;
        if(dp[idx][b]!=-1) return dp[idx][b];
        long profit=0;
        if(b){
            profit=max(f(dp,idx+1,prices,0)-prices[idx],f(dp,idx+1,prices,1)+0); //either buy or skip
        }else{
            profit=max(f(dp,idx+2,prices,1)+prices[idx],f(dp,idx+1,prices,0)+0); //either sell or skip
        }
        return dp[idx][b]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(dp,0,prices,1);
    }
};

//Tabulation
//Just like we did in BS2, but we have to add a cooldown day after selling the stock.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
            dp[i][0]=max(dp[i+2][1]+prices[i],dp[i+1][0]);
        }
        return dp[0][1];
    }
};