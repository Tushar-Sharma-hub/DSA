// 300. Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Recursion + Memoization
//Just make notTake and take cases and return max of them.
class Solution {
public:
    int f(int idx, vector<int>& nums, int prev, vector<vector<int>>& dp) {
        if (idx == 0) return 0;
        if (dp[idx][prev] != -1) return dp[idx][prev];
        int nt = f(idx - 1, nums, prev, dp);
        int t = 0;
        if (prev == nums.size() || nums[idx - 1] < nums[prev]) {
            t = 1 + f(idx - 1, nums, idx - 1, dp);
        }
        return dp[idx][prev] = max(nt, t);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(n, nums, n, dp);
    }
};