// Longest Bitonic Subsequence
// Given an array of positive integers. Find the maximum length of Bitonic subsequence.  
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. 
// Return the maximum length of bitonic subsequence. 
// Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

// Steps:
//1. Find the length of Longest Increasing Subsequence (LIS) for each index i and store it in dp1[i].
//2. Find the length of Longest Decreasing Subsequence (LDS) for each index i and store it in dp2[i].
//3. The length of the longest bitonic subsequence that ends at index i is given by dp1[i] + dp2[i] - 1 (since the peak element is counted twice).
//4. Iterate through all indices and find the maximum length of the bitonic subsequence by checking dp1[i] + dp2[i]
class Solution{
public:
    int longestBitonicSequence(int n,vector<int>&nums){
        vector<int>dp1(n,1),dp2(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i]){
                    dp2[i]=max(dp2[i],1+dp2[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1&&dp2[i]>1){
                ans=max(ans,dp1[i]+dp2[i]-1);
            }
        }
        return ans;
    }
};