// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>=1 && nums[i]==nums[i-1]) continue; //to remove duplicates
            int left=i+1,right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<0) left++;
                else if(sum>0) right--;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++; //to remove duplicates.
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
            }
        }
        return ans;
    }
};