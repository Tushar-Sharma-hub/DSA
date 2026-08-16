// Subset Sum Problem - Gfg
// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum.

// Recursion + Memoization
// T.C: O(n*sum) where n=arr.size()
// S.C: O(n*sum) + O(n) ~ O(n*sum)
//Just make notTake and take cases and return true if any of them is true.
class Solution {
  public:
    bool f(int idx,vector<int>& arr,int sum,vector<vector<int>>& dp){
        if(sum==0) return true;
        if(idx==0) return (arr[0]==sum);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool notTake=f(idx-1,arr,sum,dp);
        bool take=false;
        if(arr[idx]<=sum) take=f(idx-1,arr,sum-arr[idx],dp);
        return dp[idx][sum]=take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};

// Tabulation
// T.C: O(n*sum) where n=arr.size()
// S.C: O(n*sum)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; i++) {
            dp[i][0] = true; //because sum=0 can be achieved by taking no elements
        }
        if(arr[0] <= sum) dp[0][arr[0]] = true; //because sum=arr[0] can be achieved by taking the first element
        for(int idx = 1; idx < n; idx++) {
            for(int target = 1; target <= sum; target++) {
                // Not take
                bool notTake = dp[idx - 1][target];
                // Take
                bool take = false;
                if(arr[idx] <= target) take = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = take || notTake;
            }
        }
        return dp[n - 1][sum];
    }
};