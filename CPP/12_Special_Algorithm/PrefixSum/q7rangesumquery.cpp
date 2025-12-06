// 303. Range Sum Query - Immutable

// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right 
// inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

#include<iostream>
using namespace std;

class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        pre=vector<int>(nums.size());
        pre[0]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre[right];
        return pre[right]-pre[left-1];
    }
};
