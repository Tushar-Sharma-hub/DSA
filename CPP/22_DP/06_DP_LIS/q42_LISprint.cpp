// Get Longest Increasing Subsequence
// Given an array of integers arr[], return the Longest Increasing Subsequence (LIS) of the given array. 
// LIS is the longest subsequence where each element is strictly greater than the previous one.
// If multiple LIS exist, return the one that appears first based on the lexicographical order of indices 
// (i.e., the earliest combination of positions from the original sequence).

//Just store the index of the previous element in vector numsIdx and 
//then backtrack from the last index of the LIS to get the elements of the LIS.
class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> numsIdx(n);
        int mans=0,li=0;
        for(int i=0;i<n;i++){
            numsIdx[i]=i;
            for(int j=0;j<=i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    numsIdx[i]=j;
                }
            }
            if(dp[i]>mans){
                mans=dp[i];
                li=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[li]);
        while(li != numsIdx[li]){
            li=numsIdx[li];
            temp.push_back(nums[li]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};