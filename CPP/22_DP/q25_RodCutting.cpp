// Rod Cutting - Gfg
// Given a rod of length n inches and an array price[], where price[i] denotes the value 
// of a piece of length i (1-based Index). Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Note: The value of n is equal to the size of price array.

//Recursion + memo
class Solution {
public:
    int f(vector<vector<int>>& dp,int idx, int capacity, vector<int>& price) {
        if (idx == 0) return capacity * price[0];
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        int notTake = f(dp,idx - 1, capacity, price);
        int take = 0;
        if (idx + 1 <= capacity) 
            take = price[idx] + f(dp,idx, capacity - (idx + 1), price);
        return dp[idx][capacity]=max(take, notTake);
    }

    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(dp,n - 1, n, price);
    }
};

//Tabulation
class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        for(int idx=1;idx<n;idx++){
            for(int c=0;c<=n;c++){
                int nt=dp[idx-1][c];
                int t=0;
                if(idx+1<=c) t=price[idx]+dp[idx][c-(idx+1)];
                dp[idx][c]=max(nt,t);
            }
        }
        return dp[n-1][n];
    }
};

//Space optimization
class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<int> prev(n+1,0),curr(n+1);
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0];
        }
        for(int idx=1;idx<n;idx++){
            for(int c=0;c<=n;c++){
                int nt=prev[c];
                int t=0;
                if(idx+1<=c) t=price[idx]+curr[c-(idx+1)];
                curr[c]=max(nt,t);
            }
            prev=curr;
        }
        return prev[n];
    }
};