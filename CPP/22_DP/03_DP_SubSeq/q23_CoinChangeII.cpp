// 518. Coin Change II
// You are given an integer array coins representing coins of different denominations and 
// an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The final answer is guaranteed to fit into a signed 32-bit integer.

//Recursion + memo.
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& coins,int t){
        if(t==0) return 1;
        if(idx==0){
            if(t%coins[idx]==0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][t]!=-1) return dp[idx][t];
        int notTake=f(dp,idx-1,coins,t);
        int take=0;
        if(coins[idx]<=t) take=f(dp,idx,coins,t-coins[idx]);
        return dp[idx][t]=notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(dp,n-1,coins,amount);
    }
};

//Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for(int t=0;t<amount+1;t++){
            if(t%coins[0]==0) dp[0][t]=1;
        }
        for(int idx=1;idx<n;idx++){
            for(int t=0;t<=amount;t++){
                long long nt=dp[idx-1][t];
                long long take=0;
                if(coins[idx]<=t) take=dp[idx][t-coins[idx]];
                if (nt > INT_MAX - take) dp[idx][t] = INT_MAX; //if going out of bound / runtime error to prevent it
                else dp[idx][t] = nt + take;
            }
        }
        return dp[n-1][amount];
    }
};

//Space optimization
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0);
    vector<int> curr(amount + 1, 0);
    for (int t = 0; t <= amount; t++) {
        if (t % coins[0] == 0) prev[t] = 1;
    }
    for (int idx = 1; idx < n; idx++) {
        for (int t = 0; t <= amount; t++) {
            int nt = prev[t];
            int take = 0;
            if (coins[idx] <= t) take = curr[t - coins[idx]];
            if (nt > INT_MAX - take)
                curr[t] = INT_MAX;
            else
                curr[t] = nt + take;
        }
        prev = curr;
    }
    return prev[amount];
}