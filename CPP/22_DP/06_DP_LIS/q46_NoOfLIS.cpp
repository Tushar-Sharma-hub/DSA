// 673. Number of Longest Increasing Subsequence
// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1); //intialize count
        int mans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        count[i]=count[j]; // if found longer lcs inherit their count, as we have to find the number of longer subseq.
                    }else if(1+dp[j]==dp[i]){
                        count[i]+=count[j]; //if found duplicate just increase the count of current with count of ele we are matching with.
                    }
                }
            }
            mans=max(mans,dp[i]); // to maintain max length of lcs.
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mans) ans+=count[i]; // find ele which create longest length subseq , and add their count and return as ans.
        }
        return ans;
    }
};