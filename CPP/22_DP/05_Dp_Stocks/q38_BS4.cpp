// 188. Best Time to Buy and Sell Stock IV
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//Recursive solution with memoization
//Just BS3 with k transactions instead of 2
class Solution {
public:
    int f(vector<vector<vector<int>>>& dp,int idx,vector<int>& prices,int b,int cap){
        if(idx==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[idx][b][cap]!=-1) return dp[idx][b][cap];
        long profit=0;
        if(b){
            profit=max(f(dp,idx+1,prices,0,cap)-prices[idx],f(dp,idx+1,prices,1,cap)+0);
        }else{
            profit=max(f(dp,idx+1,prices,1,cap-1)+prices[idx],f(dp,idx+1,prices,0,cap)+0);
        }
        return dp[idx][b][cap]=profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(dp,0,prices,1,k);
    }
};

//Tabulation
//Just BS3 with k transactions instead of 2
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int b = 0; b <= 1; b++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (b) {
                        // Buy
                        dp[idx][b][cap] = max(
                            dp[idx + 1][0][cap] - prices[idx],
                            dp[idx + 1][1][cap]
                        );
                    }
                    else {
                        // Sell
                        dp[idx][b][cap] = max(
                            dp[idx + 1][1][cap - 1] + prices[idx],
                            dp[idx + 1][0][cap]
                        );
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};