// 122. Best Time to Buy and Sell Stock II
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
// However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
// Find and return the maximum profit you can achieve.

//Recursive solution with memoization
//Steps:
//1. Create a recursive function f(idx,dec) where idx is the current day and 
//   dec is a boolean indicating whether we can buy (true) or sell (false).
//2. If we can buy (dec is true), we have two options:
//   a. Buy the stock at prices[idx] and move to the next day with dec set to false (indicating we can sell next).
//   b. Skip buying and move to the next day with dec still true.
//3. If we can sell (dec is false), we also have two options:
//   a. Sell the stock at prices[idx] and move to the next day with dec set to true (indicating we can buy next).
//   b. Skip selling and move to the next day with dec still false.
//4. Use memoization to store the results of subproblems in a 2D vector dp where dp[idx][dec] stores the maximum profit from day idx with the decision dec.
//5. The base case is when idx reaches the end of the prices array, in which case we return 0 as no more profit can be made.
class Solution {
public:
    int f(vector<vector<long>>& dp,int idx,bool dec,vector<int>& prices){
        if(idx==prices.size()) return 0;
        if(dp[idx][dec]!=-1) return dp[idx][dec];
        long profit=0;
        if(dec){
            profit=max(-prices[idx]+f(dp,idx+1,false,prices),0+f(dp,idx+1,true,prices));
        }else{
            profit=max(prices[idx]+f(dp,idx+1,true,prices),0+f(dp,idx+1,false,prices));
        }
        return dp[idx][dec]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<long>> dp(n+1,vector<long>(2,-1));
        return f(dp,0,true,prices);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<long>> dp(n + 1, vector<long>(2, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            dp[idx][1] = max(
                -prices[idx] + dp[idx + 1][0],
                dp[idx + 1][1]
            );
            dp[idx][0] = max(
                prices[idx] + dp[idx + 1][1],
                dp[idx + 1][0]
            );
        }

        return dp[0][1];
    }
};

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        long nextBuy = 0;
        long nextSell = 0;

        for (int idx = n - 1; idx >= 0; idx--) {

            long currBuy = max(
                -prices[idx] + nextSell,
                nextBuy
            );

            long currSell = max(
                prices[idx] + nextBuy,
                nextSell
            );

            nextBuy = currBuy;
            nextSell = currSell;
        }

        return nextBuy;
    }
};