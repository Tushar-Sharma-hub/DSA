// 494. Target Sum
// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' 
// before each integer in nums and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Same as q19 just language is change we have to find two susbet whose sum difference will be target.(+ve one subset,-ve one subset)
// Just checkout q19 to revise this pattern.
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
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n=arr.size();
        int ts=0;
        for(int e:arr) ts+=e;
        if((ts-diff < 0) || (ts-diff)%2!=0) return 0;
        int target = (ts-diff)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(dp,n-1,arr,target);
    }
};