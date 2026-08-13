// Subset Sum Problem
// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum.

class Solution {
  public:
    bool f(int idx,vector<int>& arr,int sum,vector<vector<int>>& dp){
        if(sum==0) return true;
        if(idx==0) return (arr[0]==sum);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool notTake=f(idx-1,arr,sum,dp);
        bool take=false;
        if(arr[idx]<=sum) take=f(idx-1,arr,sum-arr[idx],dp);
        return dp[idx][sum]=take | notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};