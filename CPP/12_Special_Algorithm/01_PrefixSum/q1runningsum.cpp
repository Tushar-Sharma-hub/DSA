// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.
//LC-1480
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0) ans[i]=nums[i];
            else{
                ans[i]=nums[i]+ans[i-1];
            }
        }
        return ans;
    }
};