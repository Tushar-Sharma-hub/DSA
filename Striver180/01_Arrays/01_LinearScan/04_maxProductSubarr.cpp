// 152. Maximum Product Subarray
// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

class Solution{
public:
    int maxProduct(vector<int>& nums){
        int ans=nums[0];
        int maxCurr=nums[0],minCurr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(maxCurr,minCurr); //for -ve numbers, we swap the max and min values because multiplying by a negative number will turn the maximum product into a minimum product and vice versa.
            maxCurr=max(nums[i],nums[i]*maxCurr);
            minCurr=min(nums[i],nums[i]*minCurr);
            ans=max(ans,maxCurr);
        }
        return ans;
    }
};
