// 209. Minimum Size Subarray Sum
// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
#include<iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum=0,len=0,minlen=INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len=j-i+1;
                minlen=min(minlen,len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX) return 0;
        return minlen;
    }
};