// 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>=1 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }else if(nums[i]+nums[l]+nums[r]>0) r--;
                else l++;
            }
        }
        return ans;
    }
};