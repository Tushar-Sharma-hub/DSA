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

//Tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n=arr.size();
        int ts=0;
        for(int e:arr) ts+=e;
        if((ts-diff < 0) || (ts-diff)%2!=0) return 0;
        int target = (ts-diff)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
        for(int idx=1;idx<n;idx++){
            for(int t=0;t<=target;t++){
                int notTake=dp[idx-1][t];
                int take=0;
                if(arr[idx]<=t) take=dp[idx-1][t-arr[idx]];
                dp[idx][t]=notTake + take;
            }
        }
        return dp[n-1][target];
    }
};

//Space optimization
class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int n=arr.size();
        int ts=0;
        for(int e:arr) ts+=e;
        if((ts-diff < 0) || (ts-diff)%2!=0) return 0;
        int target = (ts-diff)/2;
        vector<int> prev(target+1,0),curr(target+1);
        if(arr[0]==0) prev[0]=2;
        else{
            prev[0]=1;
            if(arr[0]<=target) prev[arr[0]]=1;
        }
        for(int idx=1;idx<n;idx++){
            for(int t=0;t<=target;t++){
                int notTake=prev[t];
                int take=0;
                if(arr[idx]<=t) take=prev[t-arr[idx]];
                curr[t]=take+notTake;
            }
            prev=curr;
        }
        return prev[target];
    }
};