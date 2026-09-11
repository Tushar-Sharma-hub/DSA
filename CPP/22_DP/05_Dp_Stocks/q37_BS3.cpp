// 123. Best Time to Buy and Sell Stock III
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//Recursive solution with memoization
//Steps:
//1. Create a recursive function f(idx,b,cap) where idx is the current day, 
//b is a boolean indicating whether we can buy (true) or sell (false), and cap is the number of transactions left.
//2. If we can buy (b is true), we have two options:
//   a. Buy the stock at prices[idx] and move to the next day with b set to false (indicating we can sell next) and cap remains the same.
//   b. Skip buying and move to the next day with b still true and cap remains the same.
//3. If we can sell (b is false), we also have two options:
//   a. Sell the stock at prices[idx] and move to the next day with b set to true (indicating we can buy next) and cap decreases by 1.
//   b. Skip selling and move to the next day with b still false and cap remains the same.
//4. Use memoization to store the results of subproblems in a 3D vector dp where dp[idx][b][cap] stores the maximum profit from day idx with the decision b and cap transactions left.
//5. The base case is when idx reaches the end of the prices array or cap reaches 0, in which case we return 0 as no more profit can be made.
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(dp,0,prices,1,2);
    }
};

//Tabulation
//Approach:
//1. Initialize a 3D vector dp of size (n+1) x 2 x 3 with all values set to 0, where n is the number of days.
//2. Iterate through the days in reverse order (from n-1 to 0).
//3. For each day, calculate the maximum profit for both buying and selling decisions and for each transaction capacity:
//   a. If we can buy (b=1), the maximum profit is the maximum of either buying the stock at prices[idx] and moving to the next day with b=0 
//   (indicating we can sell next) and cap remains the same or skipping buying and moving to the next day with b=1 and cap remains the same.
//   b. If we can sell (b=0), the maximum profit is the maximum of either selling the stock at prices[idx] and moving to the next day with b=1 
//   (indicating we can buy next) and cap decreases by 1 or skipping selling and moving to the next day with b=0 and cap remains the same.
//4. Return the maximum profit starting from day 0 with the option to buy (b=1) and 2 transactions left (cap=2).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int b = 0; b <= 1; b++) {
                for (int cap = 1; cap <= 2; cap++) {
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
        return dp[0][1][2];
    }
};