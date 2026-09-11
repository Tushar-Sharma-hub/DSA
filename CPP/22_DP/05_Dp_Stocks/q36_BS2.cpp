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
    int f(vector<vector<int>>& dp,int idx,vector<int>& prices,int b){
        if(idx==prices.size()) return 0;
        if(dp[idx][b]!=-1) return dp[idx][b];
        long profit=0;
        if(b){
            profit=max(f(dp,idx+1,prices,0)-prices[idx],f(dp,idx+1,prices,1)+0); //either buy or skip
        }else{
            profit=max(f(dp,idx+1,prices,1)+prices[idx],f(dp,idx+1,prices,0)+0); //either sell or skip
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
//Approach:
//1.Intialize a 2D vector dp of size (n+1) x 2 with all values set to 0, where n is the number of days.
//2.Iterate through the days in reverse order (from n-1 to 0).
//3.For each day, calculate the maximum profit for both buying and selling decisions:
//   a. If we can buy (b=1), the maximum profit is the maximum of either buying the stock at prices[idx] and moving to the next day with b=0 (indicating we can sell next) or skipping buying and moving to the next day with b=1.
//   b. If we can sell (b=0), the maximum profit is the maximum of either selling the stock at prices[idx] and moving to the next day with b=1 (indicating we can buy next) or skipping selling and moving to the next day with b=0.
//4. Return the maximum profit starting from day 0 with the option to buy (b=1).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
            dp[i][0]=max(dp[i+1][1]+prices[i],dp[i+1][0]);
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