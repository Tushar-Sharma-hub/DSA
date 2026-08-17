// 0 - 1 Knapsack Problem - Gfg
// Given two arrays, val[] and wt[], where each element represents the value and 
// weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).
// Put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.
// Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. 
// Each item is available only once.

//Recursion + Memoization - Top Down Approach
// T.C: O(n*W) where n=val.size() and W=capacity
// S.C: O(n*W) + O(n) ~ O(n*W)
// Just we can either take or not take the item and return the maximum of both cases.
class Solution {
  public:
    int f(vector<vector<int>>& dp,int idx,int w,vector<int>& val,vector<int>& wt){
        if(w == 0) return 0; //early return if weight is 0, then max value is 0, saves some time in recursion.
        if(idx==0){
            if(wt[idx]<=w) return val[idx];
            else return 0;
        }
        if(dp[idx][w]!=-1) return dp[idx][w];
        int notTake=f(dp,idx-1,w,val,wt);
        int take=INT_MIN;
        if(wt[idx]<=w) take=val[idx]+f(dp,idx-1,w-wt[idx],val,wt);
        return dp[idx][w]=max(notTake,take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(dp,n-1,W,val,wt);
    }
};

// Tabulation - Bottom Up Approach
// T.C: O(n*W) where n=val.size() and W=capacity
// S.C: O(n*W)
class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case: idx = 0
        for (int w = wt[0]; w <= W; w++) { // from the weight of the first item to the maximum capacity, we can take the first item.
            dp[0][w] = val[0];
        }

        // Fill remaining states
        for (int idx = 1; idx < n; idx++) {
            for (int w = 0; w <= W; w++) {

                // Don't take current item
                int notTake = dp[idx - 1][w];

                // Take current item
                int take = 0;
                if (wt[idx] <= w) {
                    take = val[idx] + dp[idx - 1][w - wt[idx]];
                }

                dp[idx][w] = max(notTake, take);
            }
        }

        return dp[n - 1][W];
    }
};