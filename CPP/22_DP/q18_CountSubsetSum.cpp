// Count Subsets with Sum - Gfg
// Given an array arr of non-negative integers and an integer target, 
// the task is to count all subsets of the array whose sum is equal to the given target.

//recursion + Memoization
// T.C: O(n*target) where n=arr.size()
// S.C: O(n*target) + O(n) ~ O(n*target)
class Solution {
  public:
    int f(vector<vector<int>>& dp,int idx,vector<int>& arr,int t){
        if(idx == 0) {
            if(t == 0 && arr[0] == 0) return 2;
            if(t == 0 || arr[0] == t) return 1;
            return 0;
        }
        if(dp[idx][t]!=-1) return dp[idx][t];
        int notTake=f(dp,idx-1,arr,t);
        int take=0;
        if(arr[idx]<=t) take=f(dp,idx-1,arr,t-arr[idx]);
        return dp[idx][t] = take+notTake;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(dp,n-1,arr,target);
    }
};

//Tabulation
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // First element
        dp[0][0] = (arr[0] == 0) ? 2 : 1;
        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;
        // Remaining elements
        for (int idx = 1; idx < n; idx++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[idx - 1][t];
                int take = 0;
                if (arr[idx] <= t)
                    take = dp[idx - 1][t - arr[idx]];
                dp[idx][t] = take + notTake;
            }
        }
        return dp[n - 1][target];
    }
};

//Space optimization
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        // Base case
        prev[0] = (arr[0] == 0) ? 2 : 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++) {
            for (int t = 0; t <= target; t++) {

                int notTake = prev[t];

                int take = 0;
                if (arr[idx] <= t)
                    take = prev[t - arr[idx]];

                curr[t] = take + notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};