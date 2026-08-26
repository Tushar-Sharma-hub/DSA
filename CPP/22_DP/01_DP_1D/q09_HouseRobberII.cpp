// 213. House Robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
// if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you 
// can rob tonight without alerting the police.

//Recursion plus memoization (Top-down DP)
class Solution {
public:
    int helper(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+helper(nums,i+2,n,dp),helper(nums,i+1,n,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int c1 = helper(nums, 0, n - 2, dp1);
        int c2 = helper(nums, 1, n - 1, dp2);
        return max(c1,c2);
    }
};

//Tabulation (Bottom-up DP)
class Solution {
public:
    void solve(vector<int>& nums, int start, int end, int n, vector<int>& dp) {
        for (int i = end; i >= start; i--) {
            if (i == n - 1)
                dp[i] = nums[i]; // max(0, nums[i] + 0)
            else if (i == n - 2)
                dp[i] = max(dp[i + 1], nums[i]); // max(dp[i + 1], nums[i] + 0)
            else
                dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        solve(nums, 2, n - 2, n, dp1);
        solve(nums, 1, n - 1, n, dp2);

        return max(nums[0] + dp1[2], dp2[1]);
    }
};