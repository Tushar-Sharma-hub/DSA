// 300. Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Recursion + Memoization
//Just make notTake and take cases and return max of them.
//Like for storing prev index we can use prev+1 as index in dp because prev can be -1 and we can't use -1 as index in dp.
class Solution {
public:
    int f(int idx, vector<int>& nums, int prev, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int nt=f(idx+1,nums,prev,dp);
        int t=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            t=1+f(idx+1,nums,idx,dp);
        }
        return dp[idx][prev+1]=max(nt,t);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, nums, -1, dp);
    }
};

// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){ //take prev as -1 to n-1 so we can use prev+1 as index in dp
                int nt=dp[idx+1][prev+1];
                int t=0;
                if(prev==-1 || nums[idx]>nums[prev]){
                    t=1+dp[idx+1][idx+1];
                }
                dp[idx][prev+1]=max(nt,t);
            }
        }
        return dp[0][0];
    }
};

//Space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                int nt=next[prev+1];
                int t=0;
                if(prev==-1 || nums[idx]>nums[prev]){
                    t=1+next[idx+1];
                }
                curr[prev+1]=max(nt,t);
            }
            next=curr;
        }
        return curr[0];
    }
};

//Tabulation with single array
//For every index i we will check all the previous indexes j and if nums[j]<nums[i] then we can take that index and update dp[i] as max(dp[i],1+dp[j])
//Finally we will return the maximum value in dp array as the answer.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int mans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
            mans=max(mans,dp[i]);
        }
        return mans;
    }
};