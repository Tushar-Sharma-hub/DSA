// 368. Largest Divisible Subset
// Given a set of distinct positive integers nums, return the largest subset answer 
// such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

//Just store the index of the previous element in vector numsIdx and 
//then backtrack from the last index of the largest divisible subset to get the elements of the largest divisible subset.
//Like we did in LIS print problem.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> numsIdx(n);
        int mans=0,li=0;
        for(int i=0;i<n;i++){
            numsIdx[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
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