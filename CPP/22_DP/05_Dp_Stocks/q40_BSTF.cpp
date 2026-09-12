// 714. Best Time to Buy and Sell Stock with Transaction Fee
// The transaction fee is only charged once for each stock purchase and sale.

//Recursive solution with memoization
//Just add fee to the selling price in the selling case of BS2
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& prices,int b,int fee){
        if(idx>=prices.size()) return 0;
        if(dp[idx][b]!=-1) return dp[idx][b];
        long profit=0;
        if(b){
            profit=max(f(dp,idx+1,prices,0,fee)-prices[idx],f(dp,idx+1,prices,1,fee)+0); //either buy or skip
        }else{
            profit=max(-fee+f(dp,idx+1,prices,1,fee)+prices[idx],f(dp,idx+1,prices,0,fee)+0); //either sell or skip
        }
        return dp[idx][b]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(dp,0,prices,1,fee);
    }
};

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][1]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
            dp[i][0]=max(-fee+dp[i+1][1]+prices[i],dp[i+1][0]);
        }
        return dp[0][1];
    }
};

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> f1(2,0);
        vector<int> curr(2,0);
        for(int i=n-1;i>=0;i--){
            curr[1]=max(f1[0]-prices[i],f1[1]);
            curr[0]=max(-fee+f1[1]+prices[i],f1[0]);
            f1=curr;
        }
        return curr[1];
    }
};