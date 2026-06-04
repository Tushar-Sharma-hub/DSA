// 198. House Robber

// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that 
// adjacent houses have security systems connected and it will automatically contact the police 
// if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

//Recursion plus memoization (Top-down DP)
class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>& dp){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i]; 
        return dp[i]=max(nums[i]+helper(nums,i+2,dp),helper(nums,i+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};

//Tabulation (Bottom-up DP)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-2],nums[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};