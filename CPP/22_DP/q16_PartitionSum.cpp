// 416. Partition Equal Subset Sum
// Given an integer array nums, return true if you can partition the array into two subsets such that 
// the sum of the elements in both subsets is equal or false otherwise.

//Recursion + Memoization
// T.C: O(n*sum) where n=nums.size()
// S.C: O(n*sum) + O(n) ~ O(n*sum)
class Solution {
public:
    bool isSubsetSum(vector<vector<int>>& dp,int idx,vector<int>& arr, int sum) {
        if(sum==0) return true;
        if(idx==0) return (arr[idx]==sum);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool notTake=isSubsetSum(dp,idx-1,arr,sum);
        bool take=false;
        if(arr[idx]<=sum) take=isSubsetSum(dp,idx-1,arr,sum-arr[idx]);
        return dp[idx][sum] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int e:nums)sum+=e;
        if(sum%2) return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return isSubsetSum(dp,n-1,nums,sum/2);
    }
};

// Tabulation
// T.C: O(n*sum) where n=nums.size()
// S.C: O(n*sum)
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