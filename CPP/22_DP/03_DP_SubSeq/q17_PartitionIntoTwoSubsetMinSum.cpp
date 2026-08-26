// Partition Into 2 Subsets with Min Sum Diff - Gfg
// Given an array arr[]  containing non-negative integers, divide it into two sets set1 and set2 
// such that the absolute difference between their sums is minimum and find the minimum difference.

// Recursion + Memoization
// T.C: O(n*sum) where n=arr.size()
// S.C: O(n*sum) + O(n) ~ O(n*sum)
// So when finding subset sum the last row of the dp array will tell us which sums are possible with the given array.
// So we can iterate through the last row and find the minimum difference between the two subsets.
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        for(int i=0;i<arr.size();i++) sum+=arr[i];
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
        int idx=n-1;
        int ans=INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[idx][i]){
                int s1=i;
                int s2=sum-i;
                ans=min(ans,abs(s1-s2));
            }
        }
        return ans;
    }
};