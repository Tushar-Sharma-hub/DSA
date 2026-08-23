// Knapsack with Duplicate Items - Gfg
// Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively.
// Also, a knapsack with a weight limit capacity.
// Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

//Recursion + memo
class Solution {
  public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& val, vector<int>& wt, int capacity){
        if(idx==0){
            if(wt[idx]<=capacity){
                return (capacity/wt[idx])*val[idx];
            }
            return 0;
        }
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        int notTake=f(dp,idx-1,val,wt,capacity);
        int take=0;
        if(wt[idx]<=capacity) take=val[idx]+f(dp,idx,val,wt,capacity-wt[idx]);
        return dp[idx][capacity]=max(notTake,take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return f(dp,n-1,val,wt,capacity);
    }
};

//Tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        for(int c=0;c<capacity+1;c++){
            if(wt[0]<=c){
                dp[0][c]=(c/wt[0])*val[0];
            }
        }
        for(int idx=1;idx<n;idx++){
            for(int c=0;c<=capacity;c++){
                int nt=dp[idx-1][c];
                int take=0;
                if(wt[idx]<=c) take=val[idx]+dp[idx][c-wt[idx]];
                dp[idx][c]=max(take,nt);
            }
        }
        return dp[n-1][capacity];
    }
};

//Space Optimization
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<int> prev(capacity+1,0),curr(capacity+1);
        for(int c=0;c<capacity+1;c++){
            if(wt[0]<=c){
                prev[c]=(c/wt[0])*val[0];
            }
        }
        for(int idx=1;idx<n;idx++){
            for(int c=0;c<=capacity;c++){
                int nt=prev[c];
                int take=0;
                if(wt[idx]<=c) take=val[idx]+curr[c-wt[idx]];
                curr[c]=max(take,nt);
            }
            prev=curr;
        }
        return prev[capacity];
    }
};