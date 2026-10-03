// 16. 3Sum Closest
// You are given an integer array nums of length n and an integer target.
// Find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=1e5;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target) return target;
                if (abs(target - sum) < abs(target - ans)) ans = sum;
                else if(sum<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};