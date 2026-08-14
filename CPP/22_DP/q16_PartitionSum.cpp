// 416. Partition Equal Subset Sum
// Given an integer array nums, return true if you can partition the array into two subsets such that 
// the sum of the elements in both subsets is equal or false otherwise.

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if(arr[0] <= sum) dp[0][arr[0]] = true;
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
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int e:nums)sum+=e;
        if(sum%2) return false;
        return isSubsetSum(nums,sum/2);
    }
};